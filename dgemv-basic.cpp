#include <string.h>
#include <iostream>
const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are nx1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply
   int rowOffset;
   for(int row = 0; row < n; row++){
//       rowOffset = row+n;
//       printf("rowOffset: %d\n", rowOffset);
       for(int col = 0; col < n; col++){
           y[row] = A[row + col] * x[col] + y[row];
           double res = A[row + col] * x[col] + y[row];
//           printf("y[%d]: %f\n", row, res);
       }
       printf("y[%d]: %d", row, res);
   }
}
