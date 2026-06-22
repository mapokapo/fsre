#ifndef SET_H
#define SET_H

#include <stddef.h>

typedef enum {
    SET_UNSORTED_ARRAY,
    SET_SORTED_ARRAY,
    SET_LINKED_LIST,
    SET_HASH_TABLE,
    SET_BST
} SetType;

typedef int (*SetCompare)(const void *a, const void *b);
typedef size_t (*SetHash)(const void *value);
typedef void *(*SetCopy)(const void *value);
typedef void (*SetFree)(void *value);
typedef void (*SetPrint)(const void *value);

typedef struct Set Set;

Set *set_create(SetType type, SetCompare cmp, SetHash hash, SetCopy copy, SetFree free_fn);
void set_destroy(Set *set);

int set_insert(Set *set, const void *value);
int set_remove(Set *set, const void *value);
int set_contains(const Set *set, const void *value);
size_t set_size(const Set *set);

Set *set_union(const Set *a, const Set *b);
Set *set_intersection(const Set *a, const Set *b);
Set *set_difference(const Set *a, const Set *b);

void set_print(const Set *set, SetPrint print);
const char *set_type_name(SetType type);

#endif
