#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int N = 65636;
    double x[N];
    double sum = 0.0;
    double local_sum = 0.0;
    omp_set_num_threads(4);
#pragma omp parallel
    #pragma omp for
    for ( int i = 0; i < N; i++)
    {
        local_sum += x[i];
    }
    #pragma omp critical
    {
        sum += local_sum;
    }
    printf("%d", sum);

    return 0;
}
