#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[32];
} Student;

static int int_compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

static size_t int_hash(const void *value)
{
    unsigned int x = (unsigned int)*(const int *)value;
    return (size_t)(x * 2654435761u);
}

static void *int_copy(const void *value)
{
    int *copy = malloc(sizeof(*copy));

    if (copy != NULL) {
        *copy = *(const int *)value;
    }

    return copy;
}

static void int_print(const void *value)
{
    printf("%d", *(const int *)value);
}

static int string_compare(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

static size_t string_hash(const void *value)
{
    const unsigned char *text = value;
    size_t hash = 5381;

    while (*text != '\0') {
        hash = hash * 33u + *text;
        text++;
    }

    return hash;
}

static void *string_copy(const void *value)
{
    const char *text = value;
    size_t len = strlen(text) + 1;
    char *copy = malloc(len);

    if (copy != NULL) {
        memcpy(copy, text, len);
    }

    return copy;
}

static void string_print(const void *value)
{
    printf("\"%s\"", (const char *)value);
}

static int student_compare(const void *a, const void *b)
{
    const Student *x = a;
    const Student *y = b;

    return (x->id > y->id) - (x->id < y->id);
}

static size_t student_hash(const void *value)
{
    const Student *student = value;
    return int_hash(&student->id);
}

static void *student_copy(const void *value)
{
    Student *copy = malloc(sizeof(*copy));

    if (copy != NULL) {
        *copy = *(const Student *)value;
    }

    return copy;
}

static void student_print(const void *value)
{
    const Student *student = value;
    printf("{id: %d, name: %s}", student->id, student->name);
}

static int insert_many_ints(Set *set, const int *values, size_t count)
{
    size_t i;

    for (i = 0; i < count; i++) {
        if (set_insert(set, &values[i]) == -1) {
            return 0;
        }
    }

    return 1;
}

static void print_named_set(const char *name, const Set *set, SetPrint print)
{
    printf("%s = ", name);
    set_print(set, print);
    printf(" (velicina: %zu)\n", set_size(set));
}

static int demo_int_set(SetType type)
{
    int a_values[] = {5, 1, 3, 3, 7, 9};
    int b_values[] = {3, 4, 5, 8};
    int remove_value = 1;
    int contains_value = 7;
    Set *a = NULL;
    Set *b = NULL;
    Set *uni = NULL;
    Set *intersection = NULL;
    Set *difference = NULL;
    int ok = 1;

    printf("\n=== %s ===\n", set_type_name(type));

    a = set_create(type, int_compare, int_hash, int_copy, free);
    b = set_create(type, int_compare, int_hash, int_copy, free);
    if (a == NULL || b == NULL) {
        ok = 0;
        goto cleanup;
    }

    ok = insert_many_ints(a, a_values, sizeof(a_values) / sizeof(a_values[0]));
    ok = ok && insert_many_ints(b, b_values, sizeof(b_values) / sizeof(b_values[0]));
    if (!ok) {
        goto cleanup;
    }

    print_named_set("A", a, int_print);
    print_named_set("B", b, int_print);

    printf("contains(A, %d) = %s\n", contains_value,
           set_contains(a, &contains_value) ? "da" : "ne");

    printf("remove(A, %d) = %s\n", remove_value,
           set_remove(a, &remove_value) ? "uklonjeno" : "nije pronadeno");
    print_named_set("A nakon remove", a, int_print);

    uni = set_union(a, b);
    intersection = set_intersection(a, b);
    difference = set_difference(a, b);
    if (uni == NULL || intersection == NULL || difference == NULL) {
        ok = 0;
        goto cleanup;
    }

    print_named_set("A union B", uni, int_print);
    print_named_set("A intersection B", intersection, int_print);
    print_named_set("A difference B", difference, int_print);

cleanup:
    set_destroy(difference);
    set_destroy(intersection);
    set_destroy(uni);
    set_destroy(b);
    set_destroy(a);
    return ok;
}

static int demo_strings(void)
{
    const char *words[] = {"ana", "marko", "iva", "ana", "petra"};
    Set *set = set_create(SET_LINKED_LIST, string_compare, string_hash, string_copy, free);
    size_t i;

    if (set == NULL) {
        return 0;
    }

    for (i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        if (set_insert(set, words[i]) == -1) {
            set_destroy(set);
            return 0;
        }
    }

    printf("\n=== string primjer (povezana lista) ===\n");
    print_named_set("imena", set, string_print);

    set_destroy(set);
    return 1;
}

static int demo_students(void)
{
    Student students[] = {
        {3, "Luka"},
        {1, "Mia"},
        {2, "Noa"},
        {1, "Duplikat"}
    };
    Student query = {2, ""};
    Set *set = set_create(SET_HASH_TABLE, student_compare, student_hash, student_copy, free);
    size_t i;

    if (set == NULL) {
        return 0;
    }

    for (i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        if (set_insert(set, &students[i]) == -1) {
            set_destroy(set);
            return 0;
        }
    }

    printf("\n=== struct primjer (hash tablica) ===\n");
    print_named_set("studenti", set, student_print);
    printf("contains(student id=%d) = %s\n", query.id,
           set_contains(set, &query) ? "da" : "ne");

    set_destroy(set);
    return 1;
}

int main(void)
{
    SetType types[] = {
        SET_UNSORTED_ARRAY,
        SET_SORTED_ARRAY,
        SET_LINKED_LIST,
        SET_HASH_TABLE,
        SET_BST
    };
    size_t i;

    printf("Demo generickog Set ADT-a\n");

    for (i = 0; i < sizeof(types) / sizeof(types[0]); i++) {
        if (!demo_int_set(types[i])) {
            fprintf(stderr, "Greska u demo programu za: %s\n", set_type_name(types[i]));
            return 1;
        }
    }

    if (!demo_strings() || !demo_students()) {
        fprintf(stderr, "Greska u demo programu za genericke tipove.\n");
        return 1;
    }

    printf("\nSvi demo testovi su zavrsili uspjesno.\n");
    return 0;
}
