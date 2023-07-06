#include <stdio.h>

#include "kedis/klib/klib.h"
#include "kedis/util/log_util.h"

int int_compare(const void* el1, const void* el2) {
    return *(int*)el1 - *(int*)el2;
}

int main() {
    kdeis_util_log_init();

    log_info("hello kedis");

    int     arr[20] = {0};
    for( int i = 0; i < 20; i++){
        arr[i] = i + 1;
    }
    vector* v     = vector_new(sizeof(int), int_compare, NULL, NULL);
    for (int i = 0; i < 20; i++) {
        vector_push_back(v, &arr[i]);
    }

    vector_delete(v,2);

    for (size_t i = 0; i < v->length; i++) {
        log_info("val:%d", *(int*)vector_at(v, i));
    }
    log_info("length:%zu", v->length);

    vector_destroy(v);

    // printf("\n\nHello kedis.\n");
    kdeis_util_log_fini();
    return 0;
}