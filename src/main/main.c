#include <stdio.h>

#include "kedis/klib/klib.h"
#include "kedis/util/log_util.h"

int int_compare(const void* el1, const void* el2) {
    return *(int*)el1 - *(int*)el2;
}

int main() {
    kdeis_util_log_init();

    log_info("hello kedis");

    int arr[12] = {1, 3, 5, 10, 56, 2, 8, 50, 21, 11, 31, 20};

    vector* v = vector_new(sizeof(int), int_compare, NULL, NULL);
    for (int i = 0; i < 12; i++) {
        vector_push_back(v, &arr[i]);
    }

    vector_delete(v, 2);
    vector_sort(v, 1);

    for (size_t i = 0; i < v->length; i++) {
        log_info("val:%d", *(int*)vector_at(v, i));
    }
    log_info("length:%zu", v->length);

    vector_destroy(v);

    // printf("\n\nHello kedis.\n");
    kdeis_util_log_fini();
    return 0;
}