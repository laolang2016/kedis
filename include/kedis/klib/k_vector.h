/**
 * @file k_vector.h
 * @author laolang2016 (xiaodaima2016@163.com)
 * @brief 动态数组
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _KEDIS_KLIB_K_VECTOR_H_
#define _KEDIS_KLIB_K_VECTOR_H_

#include <stddef.h>

/**
 * @brief 数组默认长度
 */
#define VECTOR_DEFAULT_LENGTH 10

/**
 * @brief 元素比较函数指针
 */
typedef int (*vector_compare_func_ptr)(const void* el1, const void* el2);

/**
 * @brief 元素拷贝函数指针
 */
typedef void (*vector_copy_func_ptr)(void* dest_ptr, const void* src_ptr);

/**
 * @brief 元素释放函数指针
 */
typedef void (*vector_free_func_ptr)(void* el);

/**
 * @brief 数组排序方式
 */
typedef enum {
    /**
     * @brief 降序
     */
    desc = -1,
    /**
     * @brief 升序
     */
    asc = 1

} vector_sort_type;

/**
 * @brief 动态数组
 */
typedef struct {
    /**
     * @brief 元素数组
     */
    void* data;
    /**
     * @brief 元素大小
     */
    size_t el_size;
    /**
     * @brief 元素数量
     */
    size_t length;
    /**
     * @brief 最多能放多少元素
     */
    size_t max;
    /**
     * @brief 元素比较函数指针
     */
    vector_compare_func_ptr compare_func;
    /**
     * @brief 元素拷贝函数指针
     */
    vector_copy_func_ptr copy_func;
    /**
     * @brief 元素释放函数指针
     */
    vector_free_func_ptr free_func;
} vector;

/**
 * @brief 初始化一个动态数组
 * 
 * @param el_size 元素大小
 * @param compare_func 元素比较函数
 * @param copy_func 元素拷贝函数
 * @param free_func 元素释放函数
 * @return vector* 动态数组结构体指针
 */
vector* vector_new(size_t el_size, vector_compare_func_ptr compare_func, vector_copy_func_ptr copy_func,
                   vector_free_func_ptr free_func);

/**
 * @brief 销毁动态数组
 * 
 * @param v 动态数组指针
 */
void vector_destroy(vector* v);

/**
 * @brief 根据下标获取元素
 * 
 * @param v 动态数组指针
 * @param index 下标
 * @return void* 查找到的元素, 如果未找到则返回 NULL
 */
void* vector_at(vector* v, size_t index);

/**
 * @brief 数组元素个数
 * 
 * @param v 动态数组指针
 * @return size_t 元素个数
 */
size_t vector_length(vector* v);

/**
 * @brief 向数组尾部追加元素
 * 
 * @param v 动态数组指针
 * @param el 要追加的元素
 */
void vector_push_back(vector* v, const void* el);

/**
 * @brief 根据下标删除元素
 * 
 * @param v 动态数组指针
 * @param index 下标
 */
void vector_delete(vector* v, const size_t index);

/**
 * @brief 根据下标交换两个位置的元素内容
 * 
 * @param v 动态数组指针
 * @param first 第一个要交换的下标
 * @param second 第二个要交换的下标
 */
void vector_swap(vector* v, const size_t first, const size_t second);

/**
 * @brief 排序数组
 * 
 * compare_func 不能为空
 * 
 * @param v 动态数组指针
 * @param type 排序方式
 */
void vector_sort(vector* v, vector_sort_type type);

#endif