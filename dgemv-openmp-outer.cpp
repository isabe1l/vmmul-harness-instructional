#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are nx1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

#pragma omp parallel
    {
        int nthreads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
//      printf("Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
    }

    // insert your dgemv code here. you may need to create additional parallel regions,
    // and you may want to comment out the above parallel code block that prints out
    // nthreads and thread_id to not taint your timings
    int rowOffset;
    //https://stackoverflow.com/questions/13357065/how-does-openmp-handle-nested-loops
    //used for collapse for nested loops
#pragma omp parallel for
    for(int row = 0; row < n; row++){
        //rowOffset from lecture slides that talked about CP3
        for(int col = 0; col < n; col++){
            rowOffset = row*n;
//       printf("rowOffset: %d\n", rowOffset);
            y[row] = A[rowOffset + col] * x[col] + y[row];
//           printf("y[%d]: %f\n", row, y[row]);
        }
    }

}

//
// Created by Isabel on 5/12/2023.
//
