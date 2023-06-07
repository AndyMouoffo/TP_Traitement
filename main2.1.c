#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int N = 65636;
    double x[N];
    double sum = 0.0;
    omp_set_num_threads(4);
#pragma omp parallel for reduction(+:sum)

    for (int i = 0; i < N ; i++)
    {
        sum += x[i];
    }
    printf("%d", sum);

}
