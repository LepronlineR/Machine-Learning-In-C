#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>  

#include "matrix.h"

bool matrix_testing_suite_two(){

    

    return true;
}

bool matrix_testing_suite_one(){
    
    // create 2 matrices
    matf_t m1 = matf_alloc(3, 4);
    matf_t m2 = matf_alloc(4, 1);
    
    // print the two matrices
    printf("M1: \n");
    matf_print(&m1);
    printf("M2: \n");
    matf_print(&m2); 
    printf("\n");

    // set the matrices
    matf_set_all(&m1, 2.0f);
    assert(matf_set_one(&m2, 1, 0, 3.0f));

    printf("M1: \n");
    matf_print(&m1);
    printf("M2: \n");
    matf_print(&m2); 
    printf("\n");

    // matrix add
    matf_t m3 = matf_alloc(2, 2);
    matf_t m4 = matf_alloc(2, 2);

    matf_set_all(&m3, 1.0f);
    assert(matf_set_one(&m4, 0, 0, 3.0f));
    assert(matf_set_one(&m4, 1, 0, 5.0f));
    assert(matf_set_one(&m4, 0, 1, 2.0f));
    assert(matf_set_one(&m4, 1, 1, 4.0f));

    printf("M3: \n");
    matf_print(&m3);
    printf("M4: \n");
    matf_print(&m4); 
    printf("\n");

    assert(matf_sum(&m3, &m4));

    printf("M3: \n");
    matf_print(&m3);
    printf("M4: \n");
    matf_print(&m4); 
    printf("\n");

    // dot product
    assert(matf_set_one(&m2, 0, 0, 6.0f));
    assert(matf_set_one(&m2, 2, 0, 1.0f));
    assert(matf_set_one(&m2, 3, 0, -1.0f));
    assert(matf_set_one(&m1, 1, 1, 1.5f));
    assert(matf_set_one(&m1, 0, 2, 3.0f));
    assert(matf_set_one(&m1, 0, 3, 0.1f));

    matf_t m5;
    assert(matf_dot(&m5, &m1, &m2));
    printf("M1: \n");
    matf_print(&m1);
    printf("M2: \n");
    matf_print(&m2); 
    printf("M5: \n");
    matf_print(&m5); 
    printf("\n");

    return true;
}