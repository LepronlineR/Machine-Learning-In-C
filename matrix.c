#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"

#pragma region alloc
matf_t matf_alloc(size_t row, size_t col){
    matf_t m;
    m.cols = col;
    m.rows = row;
    m.data = calloc(row, sizeof(float*));
    // note: calloc initalizes the values to 0, do not need to set it
    for(size_t i = 0; i < row; i++){
        m.data[i] = calloc(col, sizeof(float));
    }
    return m;
}

void matf_free(matf_t* mat){
    for(int x = 0; x < mat->rows; x++){
        free(mat->data[x]);
    }

    free(mat->data);
}
#pragma endregion

#pragma region set
void matf_set_all(matf_t* m, float num){
    for(size_t row = 0; row < m->rows; row++){
        for(size_t col = 0; col < m->cols; col++){
            m->data[row][col] = num;
        }
    }
}

bool matf_set_one(matf_t* m, size_t row, size_t col, float num){
    // check for valid
    if(m->rows <= row || m->cols <= col)
        return false;

    m->data[row][col] = num;
    return true;
}
#pragma endregion

#pragma region sum/dot
bool matf_sum(const matf_t* m1, matf_t* m2){
    // check for validity
    if(m1->cols != m2->cols || m1->rows != m2->rows)
        return false;
    
    for(size_t x = 0; x < m1->rows; x++){
        for(size_t y = 0; y < m1->cols; y++){
            m2->data[x][y] = m1->data[x][y] + m2->data[x][y];
        }
    }

    return true;
}


bool matf_dot(matf_t* result, const matf_t* m1, const matf_t* m2){
    // check for validity: row of m1 and col of m2
    if(m1->cols != m2->rows)
        return false;

    *result = matf_alloc(m1->rows, m2->cols);

    float temp = 0.0f;
    for(size_t x = 0; x < result->rows; x++){
        for(size_t y = 0; y < result->cols; y++){
            for(size_t z = 0; z < m1->cols; z++){
                temp += (m1->data[x][z] * m2->data[z][y]);
            }
            result->data[x][y] = temp;
            temp = 0.0f;
        }
    }

    return true;
}

bool matf_sum_n(matf_t* result, const matf_t* m1, const matf_t* m2){
    // check for validity
    if(m1->cols != m2->cols || m1->rows != m2->rows)
        return false;

    *result = matf_alloc(m1->rows, m1->cols);

    for(size_t x = 0; x < m1->rows; x++){
        for(size_t y = 0; y < m1->cols; y++){
            m2->data[x][y] = m1->data[x][y] + m2->data[x][y];
        }
    }

    return true;
}

#pragma endregion

bool matf_transpose(matf_t* result, const matf_t* m1){
    
    *result = matf_alloc(m1->cols, m1->rows);

    

    return true;

}

void matf_print(const matf_t* m1){
    for(size_t row = 0; row < m1->rows; row++){
        for(size_t col = 0; col < m1->cols; col++){
            printf("%f ", m1->data[row][col]);
        }
        printf("\n");
    }
}