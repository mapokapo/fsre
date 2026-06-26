#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 8
#define INITIAL_BUCKETS 16

typedef void (*ForEachFn)(void *value, void *ctx);

typedef struct SetOps {
    void (*destroy)(Set *set);
    int (*insert_owned)(Set *set, void *value);
    int (*remove)(Set *set, const void *value);
    int (*contains)(const Set *set, const void *value);
    void (*for_each)(const Set *set, ForEachFn fn, void *ctx);
} SetOps;

struct Set {
    SetType type;
    SetCompare cmp;
    SetHash hash;
    SetCopy copy;
    SetFree free_fn;
    void *impl;
    const SetOps *ops;
};

typedef struct {
    void **items;
    size_t size;
    size_t capacity;
    int sorted;
} ArraySet;

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    size_t size;
} ListSet;

typedef struct HashNode {
    void *data;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    size_t bucket_count;
    size_t size;
} HashSet;

typedef struct BstNode {
    void *data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct {
    BstNode *root;
    size_t size;
} BstSet;
static void free_value(Set *set, void *value)
{
    if (set->free_fn != NULL) {
        set->free_fn(value);
    }
}

static void *copy_value(const Set *set, const void *value)
{
    if (set->copy == NULL) {
        return (void *)value;
    }

    return set->copy(value);
}

static int array_ensure_capacity(ArraySet *array, size_t needed)
{
    void **new_items;
    size_t new_capacity;

    if (array->capacity >= needed) {
        return 1;
    }

    new_capacity = array->capacity == 0 ? INITIAL_CAPACITY : array->capacity * 2;
    while (new_capacity < needed) {
        new_capacity *= 2;
    }

    new_items = realloc(array->items, new_capacity * sizeof(*array->items));
    if (new_items == NULL) {
        return 0;
    }

    array->items = new_items;
    array->capacity = new_capacity;
    return 1;
}

static size_t sorted_lower_bound(const Set *set, const void *value, int *found)
{
    const ArraySet *array = set->impl;
    size_t left = 0;
    size_t right = array->size;

    *found = 0;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        int cmp = set->cmp(array->items[mid], value);

        if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    if (left < array->size && set->cmp(array->items[left], value) == 0) {
        *found = 1;
    }

    return left;
}

static void array_destroy(Set *set)
{
    ArraySet *array = set->impl;
    size_t i;

    for (i = 0; i < array->size; i++) {
        free_value(set, array->items[i]);
    }

    free(array->items);
    free(array);
}

static int array_contains(const Set *set, const void *value)
{
    const ArraySet *array = set->impl;
    size_t i;

    if (array->sorted) {
        int found;
        sorted_lower_bound(set, value, &found);
        return found;
    }

    for (i = 0; i < array->size; i++) {
        if (set->cmp(array->items[i], value) == 0) {
            return 1;
        }
    }

    return 0;
}

static int array_insert_owned(Set *set, void *value)
{
    ArraySet *array = set->impl;

    if (!array_ensure_capacity(array, array->size + 1)) {
        return -1;
    }

    if (array->sorted) {
        int found;
        size_t pos = sorted_lower_bound(set, value, &found);
        size_t count = array->size - pos;

        memmove(&array->items[pos + 1], &array->items[pos], count * sizeof(*array->items));
        array->items[pos] = value;
    } else {
        array->items[array->size] = value;
    }

    array->size++;
    return 1;
}

static int array_remove(Set *set, const void *value)
{
    ArraySet *array = set->impl;
    size_t pos;

    if (array->sorted) {
        int found;
        pos = sorted_lower_bound(set, value, &found);
        if (!found) {
            return 0;
        }
    } else {
        for (pos = 0; pos < array->size; pos++) {
            if (set->cmp(array->items[pos], value) == 0) {
                break;
            }
        }

        if (pos == array->size) {
            return 0;
        }
    }

    free_value(set, array->items[pos]);
    memmove(&array->items[pos], &array->items[pos + 1],
            (array->size - pos - 1) * sizeof(*array->items));
    array->size--;
    return 1;
}

static void array_for_each(const Set *set, ForEachFn fn, void *ctx)
{
    const ArraySet *array = set->impl;
    size_t i;

    for (i = 0; i < array->size; i++) {
        fn(array->items[i], ctx);
    }
}
static void list_destroy(Set *set)
{
    ListSet *list = set->impl;
    ListNode *node = list->head;

    while (node != NULL) {
        ListNode *next = node->next;
        free_value(set, node->data);
        free(node);
        node = next;
    }

    free(list);
}

static int list_contains(const Set *set, const void *value)
{
    const ListSet *list = set->impl;
    const ListNode *node;

    for (node = list->head; node != NULL; node = node->next) {
        if (set->cmp(node->data, value) == 0) {
            return 1;
        }
    }

    return 0;
}

static int list_insert_owned(Set *set, void *value)
{
    ListSet *list = set->impl;
    ListNode *node = malloc(sizeof(*node));

    if (node == NULL) {
        return -1;
    }

    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;
    return 1;
}

static int list_remove(Set *set, const void *value)
{
    ListSet *list = set->impl;
    ListNode *prev = NULL;
    ListNode *node = list->head;

    while (node != NULL) {
        if (set->cmp(node->data, value) == 0) {
            if (prev == NULL) {
                list->head = node->next;
            } else {
                prev->next = node->next;
            }

            free_value(set, node->data);
            free(node);
            list->size--;
            return 1;
        }

        prev = node;
        node = node->next;
    }

    return 0;
}

static void list_for_each(const Set *set, ForEachFn fn, void *ctx)
{
    const ListSet *list = set->impl;
    const ListNode *node;

    for (node = list->head; node != NULL; node = node->next) {
        fn(node->data, ctx);
    }
}
static size_t hash_index(const Set *set, const void *value, size_t bucket_count)
{
    return set->hash(value) % bucket_count;
}

static int hash_resize(Set *set, size_t new_bucket_count)
{
    HashSet *hash = set->impl;
    HashNode **new_buckets = calloc(new_bucket_count, sizeof(*new_buckets));
    size_t i;

    if (new_buckets == NULL) {
        return 0;
    }

    for (i = 0; i < hash->bucket_count; i++) {
        HashNode *node = hash->buckets[i];

        while (node != NULL) {
            HashNode *next = node->next;
            size_t index = hash_index(set, node->data, new_bucket_count);
            node->next = new_buckets[index];
            new_buckets[index] = node;
            node = next;
        }
    }

    free(hash->buckets);
    hash->buckets = new_buckets;
    hash->bucket_count = new_bucket_count;
    return 1;
}

static void hash_destroy(Set *set)
{
    HashSet *hash = set->impl;
    size_t i;

    for (i = 0; i < hash->bucket_count; i++) {
        HashNode *node = hash->buckets[i];

        while (node != NULL) {
            HashNode *next = node->next;
            free_value(set, node->data);
            free(node);
            node = next;
        }
    }

    free(hash->buckets);
    free(hash);
}

static int hash_contains(const Set *set, const void *value)
{
    const HashSet *hash = set->impl;
    size_t index = hash_index(set, value, hash->bucket_count);
    const HashNode *node;

    for (node = hash->buckets[index]; node != NULL; node = node->next) {
        if (set->cmp(node->data, value) == 0) {
            return 1;
        }
    }

    return 0;
}

static int hash_insert_owned(Set *set, void *value)
{
    HashSet *hash = set->impl;
    HashNode *node;
    size_t index;

    if ((hash->size + 1) * 4 > hash->bucket_count * 3) {
        if (!hash_resize(set, hash->bucket_count * 2)) {
            return -1;
        }
    }

    node = malloc(sizeof(*node));
    if (node == NULL) {
        return -1;
    }

    index = hash_index(set, value, hash->bucket_count);
    node->data = value;
    node->next = hash->buckets[index];
    hash->buckets[index] = node;
    hash->size++;
    return 1;
}

static int hash_remove(Set *set, const void *value)
{
    HashSet *hash = set->impl;
    size_t index = hash_index(set, value, hash->bucket_count);
    HashNode *prev = NULL;
    HashNode *node = hash->buckets[index];

    while (node != NULL) {
        if (set->cmp(node->data, value) == 0) {
            if (prev == NULL) {
                hash->buckets[index] = node->next;
            } else {
                prev->next = node->next;
            }

            free_value(set, node->data);
            free(node);
            hash->size--;
            return 1;
        }

        prev = node;
        node = node->next;
    }

    return 0;
}

static void hash_for_each(const Set *set, ForEachFn fn, void *ctx)
{
    const HashSet *hash = set->impl;
    size_t i;

    for (i = 0; i < hash->bucket_count; i++) {
        const HashNode *node;

        for (node = hash->buckets[i]; node != NULL; node = node->next) {
            fn(node->data, ctx);
        }
    }
}
static BstNode *bst_node_create(void *value)
{
    BstNode *node = malloc(sizeof(*node));

    if (node == NULL) {
        return NULL;
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void bst_destroy_nodes(Set *set, BstNode *node)
{
    if (node == NULL) {
        return;
    }

    bst_destroy_nodes(set, node->left);
    bst_destroy_nodes(set, node->right);
    free_value(set, node->data);
    free(node);
}

static void bst_destroy(Set *set)
{
    BstSet *bst = set->impl;

    bst_destroy_nodes(set, bst->root);
    free(bst);
}

static int bst_contains(const Set *set, const void *value)
{
    const BstSet *bst = set->impl;
    const BstNode *node = bst->root;

    while (node != NULL) {
        int cmp = set->cmp(value, node->data);

        if (cmp == 0) {
            return 1;
        }

        node = cmp < 0 ? node->left : node->right;
    }

    return 0;
}

static int bst_insert_owned(Set *set, void *value)
{
    BstSet *bst = set->impl;
    BstNode **link = &bst->root;

    while (*link != NULL) {
        int cmp = set->cmp(value, (*link)->data);
        link = cmp < 0 ? &(*link)->left : &(*link)->right;
    }

    *link = bst_node_create(value);
    if (*link == NULL) {
        return -1;
    }

    bst->size++;
    return 1;
}

static BstNode *bst_detach_min(BstNode *node, BstNode **min_node)
{
    if (node->left == NULL) {
        *min_node = node;
        return node->right;
    }

    node->left = bst_detach_min(node->left, min_node);
    return node;
}

static BstNode *bst_remove_node(Set *set, BstNode *node, const void *value, int *removed)
{
    int cmp;
    BstNode *replacement;
    BstNode *min_node;

    if (node == NULL) {
        return NULL;
    }

    cmp = set->cmp(value, node->data);
    if (cmp < 0) {
        node->left = bst_remove_node(set, node->left, value, removed);
        return node;
    }

    if (cmp > 0) {
        node->right = bst_remove_node(set, node->right, value, removed);
        return node;
    }

    *removed = 1;
    if (node->left == NULL) {
        replacement = node->right;
    } else if (node->right == NULL) {
        replacement = node->left;
    } else {
        min_node = NULL;
        replacement = bst_detach_min(node->right, &min_node);
        min_node->left = node->left;
        min_node->right = replacement;
        replacement = min_node;
    }

    free_value(set, node->data);
    free(node);
    return replacement;
}

static int bst_remove(Set *set, const void *value)
{
    BstSet *bst = set->impl;
    int removed = 0;

    bst->root = bst_remove_node(set, bst->root, value, &removed);
    if (removed) {
        bst->size--;
    }

    return removed;
}

static void bst_for_each_node(const BstNode *node, ForEachFn fn, void *ctx)
{
    if (node == NULL) {
        return;
    }

    bst_for_each_node(node->left, fn, ctx);
    fn(node->data, ctx);
    bst_for_each_node(node->right, fn, ctx);
}

static void bst_for_each(const Set *set, ForEachFn fn, void *ctx)
{
    const BstSet *bst = set->impl;

    bst_for_each_node(bst->root, fn, ctx);
}
static const SetOps ARRAY_OPS = {
    array_destroy,
    array_insert_owned,
    array_remove,
    array_contains,
    array_for_each
};
static const SetOps LIST_OPS = {
    list_destroy,
    list_insert_owned,
    list_remove,
    list_contains,
    list_for_each
};
static const SetOps HASH_OPS = {
    hash_destroy,
    hash_insert_owned,
    hash_remove,
    hash_contains,
    hash_for_each
};

static const SetOps BST_OPS = {
    bst_destroy,
    bst_insert_owned,
    bst_remove,
    bst_contains,
    bst_for_each
};
static int set_init_impl(Set *set)
{
    ArraySet *array;
    ListSet *list;
    HashSet *hash;
    BstSet *bst;

    switch (set->type) {
    case SET_UNSORTED_ARRAY:
    case SET_SORTED_ARRAY:
        array = calloc(1, sizeof(*array));
        if (array == NULL) {
            return 0;
        }

        array->sorted = set->type == SET_SORTED_ARRAY;
        set->impl = array;
        set->ops = &ARRAY_OPS;
        return 1;

    case SET_LINKED_LIST:
        list = calloc(1, sizeof(*list));
        if (list == NULL) {
            return 0;
        }

        set->impl = list;
        set->ops = &LIST_OPS;
        return 1;

    case SET_HASH_TABLE:
        hash = calloc(1, sizeof(*hash));
        if (hash == NULL) {
            return 0;
        }

        hash->bucket_count = INITIAL_BUCKETS;
        hash->buckets = calloc(hash->bucket_count, sizeof(*hash->buckets));
        if (hash->buckets == NULL) {
            free(hash);
            return 0;
        }

        set->impl = hash;
        set->ops = &HASH_OPS;
        return 1;

    case SET_BST:
        bst = calloc(1, sizeof(*bst));
        if (bst == NULL) {
            return 0;
        }

        set->impl = bst;
        set->ops = &BST_OPS;
        return 1;
    }

    return 0;
}
Set *set_create(SetType type, SetCompare cmp, SetHash hash, SetCopy copy, SetFree free_fn)
{
    Set *set;

    if (cmp == NULL) {
        return NULL;
    }

    if (type == SET_HASH_TABLE && hash == NULL) {
        return NULL;
    }

    set = calloc(1, sizeof(*set));
    if (set == NULL) {
        return NULL;
    }

    set->type = type;
    set->cmp = cmp;
    set->hash = hash;
    set->copy = copy;
    set->free_fn = free_fn;

    if (!set_init_impl(set)) {
        free(set);
        return NULL;
    }

    return set;
}

void set_destroy(Set *set)
{
    if (set == NULL) {
        return;
    }

    set->ops->destroy(set);
    free(set);
}

int set_insert(Set *set, const void *value)
{
    void *owned_value;
    int result;

    if (set == NULL || value == NULL) {
        return -1;
    }

    if (set_contains(set, value)) {
        return 0;
    }

    owned_value = copy_value(set, value);
    if (owned_value == NULL) {
        return -1;
    }

    result = set->ops->insert_owned(set, owned_value);
    if (result != 1) {
        free_value(set, owned_value);
    }

    return result;
}

int set_remove(Set *set, const void *value)
{
    if (set == NULL || value == NULL) {
        return 0;
    }

    return set->ops->remove(set, value);
}

int set_contains(const Set *set, const void *value)
{
    if (set == NULL || value == NULL) {
        return 0;
    }

    return set->ops->contains(set, value);
}

size_t set_size(const Set *set)
{
    if (set == NULL) {
        return 0;
    }

    switch (set->type) {
    case SET_UNSORTED_ARRAY:
    case SET_SORTED_ARRAY:
        return ((const ArraySet *)set->impl)->size;
    case SET_LINKED_LIST:
        return ((const ListSet *)set->impl)->size;
    case SET_HASH_TABLE:
        return ((const HashSet *)set->impl)->size;
    case SET_BST:
        return ((const BstSet *)set->impl)->size;
    }

    return 0;
}
typedef struct {
    Set *result;
    const Set *other;
    int failed;
} SetBuildCtx;

static void insert_all_cb(void *value, void *ctx)
{
    SetBuildCtx *build = ctx;

    if (set_insert(build->result, value) == -1) {
        build->failed = 1;
    }
}

static void insert_if_in_other_cb(void *value, void *ctx)
{
    SetBuildCtx *build = ctx;

    if (set_contains(build->other, value) && set_insert(build->result, value) == -1) {
        build->failed = 1;
    }
}

static void insert_if_not_in_other_cb(void *value, void *ctx)
{
    SetBuildCtx *build = ctx;

    if (!set_contains(build->other, value) && set_insert(build->result, value) == -1) {
        build->failed = 1;
    }
}

static Set *create_result_set(const Set *source)
{
    SetFree free_fn = source->copy == NULL ? NULL : source->free_fn;

    return set_create(source->type, source->cmp, source->hash, source->copy, free_fn);
}

Set *set_union(const Set *a, const Set *b)
{
    SetBuildCtx build;

    if (a == NULL || b == NULL) {
        return NULL;
    }

    build.result = create_result_set(a);
    build.other = b;
    build.failed = 0;

    if (build.result == NULL) {
        return NULL;
    }

    a->ops->for_each(a, insert_all_cb, &build);
    b->ops->for_each(b, insert_all_cb, &build);

    if (build.failed) {
        set_destroy(build.result);
        return NULL;
    }

    return build.result;
}

Set *set_intersection(const Set *a, const Set *b)
{
    SetBuildCtx build;

    if (a == NULL || b == NULL) {
        return NULL;
    }

    build.result = create_result_set(a);
    build.other = b;
    build.failed = 0;

    if (build.result == NULL) {
        return NULL;
    }

    a->ops->for_each(a, insert_if_in_other_cb, &build);

    if (build.failed) {
        set_destroy(build.result);
        return NULL;
    }

    return build.result;
}

Set *set_difference(const Set *a, const Set *b)
{
    SetBuildCtx build;

    if (a == NULL || b == NULL) {
        return NULL;
    }

    build.result = create_result_set(a);
    build.other = b;
    build.failed = 0;

    if (build.result == NULL) {
        return NULL;
    }

    a->ops->for_each(a, insert_if_not_in_other_cb, &build);

    if (build.failed) {
        set_destroy(build.result);
        return NULL;
    }

    return build.result;
}

typedef struct {
    SetPrint print;
    int first;
} PrintCtx;

static void print_value_cb(void *value, void *ctx)
{
    PrintCtx *print_ctx = ctx;

    if (!print_ctx->first) {
        printf(", ");
    }

    print_ctx->print(value);
    print_ctx->first = 0;
}

void set_print(const Set *set, SetPrint print)
{
    PrintCtx ctx;

    if (set == NULL || print == NULL) {
        printf("{}");
        return;
    }

    ctx.print = print;
    ctx.first = 1;

    printf("{");
    set->ops->for_each(set, print_value_cb, &ctx);
    printf("}");
}

const char *set_type_name(SetType type)
{
    switch (type) {
    case SET_UNSORTED_ARRAY:
        return "nesortirano polje";
    case SET_SORTED_ARRAY:
        return "sortirano polje";
    case SET_LINKED_LIST:
        return "povezana lista";
    case SET_HASH_TABLE:
        return "hash tablica";
    case SET_BST:
        return "BST";
    }

    return "nepoznato";
}
