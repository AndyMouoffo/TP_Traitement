#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n = 3;
    double A[n][n];
#pragma omp parallel num_threads(4)
{
    int id = omp_get_thread_num;
    int chunk_size = n / omp_get_num_threads();
    int start = id * chunk_size;
    int end = (id == omp_get_num_threads() - 1) ? n : (id + 1) * chunk_size;
    for (int i = 0; i < n; i++)
    {
        for (int j = start + 1; j < end; j++)
        {
            A[i][j] += A[i][j-1];
        }
    }
}

}
