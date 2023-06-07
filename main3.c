#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
 int n = 3;
 double A[n][n], B[n], C[n];
#pragma omp parallel for num_threads(4)
 for (int i=0; i < n; i++)
 {
     C[i] = 0.0;
     for (int j=0; j < n; j++)
     {
         C[i] += A[i][j] * B[j];
     }
 }
}
