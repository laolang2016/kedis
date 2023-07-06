#ifndef _KEDIS_KLIB_K_VECTOR_H_
#define _KEDIS_KLIB_K_VECTOR_H_

#include <stddef.h>

#define VECTOR_DEFAULT_LENGTH 10

typedef int (*vector_compare_func_ptr)(const void* el1, const void* el2);
typedef void (*vector_copy_func_ptr)(void* dest_ptr, const void* src_ptr);
typedef void (*vector_free_func_ptr)(void* el);

typedef struct {
    void*                   data;
    size_t                  el_size;
    size_t                  length;
    size_t                  max;
    vector_compare_func_ptr compare_func;
    vector_copy_func_ptr    copy_func;
    vector_free_func_ptr    free_func;
} vector;

vector * vector_new( size_t el_size, vector_compare_func_ptr compare_func, vector_copy_func_ptr copy_func,
                vector_free_func_ptr free_func);

void vector_destroy(vector* v);

void* vector_at(vector* v, size_t index);

size_t vector_length(vector* v);

void vector_push_back(vector* v, const void * el);

void vector_delete(vector * v, const size_t index);



#endif