#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdbool.h>

// basic dynamic matrix object 
typedef struct {
    size_t rows;
    size_t cols;
    float** data;
} matf_t;

// Allocates a matrix given a row and column
matf_t matf_alloc(size_t row, size_t col);

// set all values to num
void matf_set_all(matf_t* m, float num);

// set one value to num, if the row/col is invalid returns false
bool matf_set_one(matf_t* m, size_t row, size_t col, float num);

// m1 + m2, result in m2, returns false if the operation is invalid
bool matf_sum(const matf_t* m1, matf_t* m2);

// m1 + m2, output result, returns false if the operation is invalid (result will be allocated in this function)
bool matf_sum_n(matf_t* result, const matf_t* m1, const matf_t* m2);

// m1 • m2, output result, returns false if the operation is invalid (result will be allocated in this function)
bool matf_dot(matf_t* result, const matf_t* m1, const matf_t* m2);

// m1^T, output result, returns false if the operation is invalid (result will be allocated in this function)
bool matf_transpose(matf_t* result, const matf_t* m1);

void matf_free(matf_t* mat);

void matf_print(const matf_t* m1);

#endif