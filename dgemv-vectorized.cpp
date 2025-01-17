const char *dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double *A, double *x, double *y) {
    // insert your code here: implementation of vectorized vector-matrix multiply
    //ensuring that increasing by 3 doesn't cause a problem
    int rowOffset;
    int secondRowOffset;
    for (int row = 1; row < n; row+=2) {
        rowOffset = row * n;
        secondRowOffset = (row-1) *n;
        for (int col = 0 ; col < n; col++) {
            //vectorizing by computing the maxtrix-mult for two rows
            y[row-1] = A[secondRowOffset + col] * x[col] + y[row-1];
            y[row] = A[rowOffset + col] * x[col] + y[row];
        }
    }
}
