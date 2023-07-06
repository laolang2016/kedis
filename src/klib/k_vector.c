#include "kedis/klib/k_vector.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void vector_grow(vector* v) {
    if (NULL == v) return;

    v->data = realloc(v->data, 2 * v->max * v->el_size);
    assert(NULL != v->data);
    v->max = 2 * v->max;
}

vector* vector_new(size_t el_size, vector_compare_func_ptr compare_func, vector_copy_func_ptr copy_func,
                   vector_free_func_ptr free_func) {
    vector* v = malloc(sizeof(vector));
    assert(NULL != v);
    v->max     = VECTOR_DEFAULT_LENGTH;
    v->el_size = el_size;
    v->length  = 0;
    v->data    = malloc(v->max * v->el_size);
    assert(NULL != v->data);
    v->compare_func = compare_func;
    v->copy_func    = copy_func;
    v->free_func    = free_func;
    return v;
}

void vector_destroy(vector* v) {
    if (NULL == v) return;

    if (NULL != v->free_func && v->length > 0) {
        for (size_t i = 0; i < v->length; i++) {
            void* el_ptr = (char*)v->data + i * v->el_size;
            v->free_func(el_ptr);
        }
    }
    free(v->data);
    v->data         = NULL;
    v->el_size      = 0;
    v->length       = 0;
    v->max          = 0;
    v->compare_func = NULL;
    v->copy_func    = NULL;
    v->free_func    = NULL;
    free(v);
}

void* vector_at(vector* v, size_t index) {
    if (NULL == v) return NULL;
    if (index >= v->length) return NULL;

    return (char*)v->data + index * v->el_size;
}

size_t vector_length(vector* v) {
    return v->length;
}

void vector_push_back(vector* v, const void* el) {
    if (v->length >= v->max) vector_grow(v);
    void* dest_addr = (char*)v->data + v->length * v->el_size;
    if (NULL != v->copy_func) {
        v->copy_func(dest_addr, el);
    } else {
        memcpy(dest_addr, el, v->el_size);
    }
    v->length++;
}

void vector_delete(vector* v, const size_t index) {
    if (index < 0) return;
    if (index >= v->length) return;

    void* dest_addr = (char*)v->data + index * v->el_size;
    if (NULL != v->free_func) v->free_func(dest_addr);

    size_t byte_size = (v->length - 1 - index) * v->el_size;
    memmove(dest_addr,(char*)dest_addr + v->el_size,byte_size);
    v->length--;
}
