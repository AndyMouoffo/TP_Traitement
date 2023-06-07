#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int N;
    float A[N], B[N], C[N];
    omp_set_num_threads(4);
#pragma omp parallel for shared(A,B,C) schedule(static)

for (int i = 0; i < N; i++)
    {
        C[i] = B[i] + A[i];
    }

    return 0;
}
