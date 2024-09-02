#include <mpi.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
int main(int argc, char **argv) {
    int rank, size;
    int local_sum = 0; 
    int global_sum;    // ȫ���ܺ�
    MPI_Init(&argc, &argv); // ��ʼ��MPI����
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // ��ȡ��ǰ���̵�����
    MPI_Comm_size(MPI_COMM_WORLD, &size); // ��ȡ��������

    for (int i = 0; i < 10; ++i) 
    {
        local_sum += i;
        printf("%d\n",local_sum);
    }
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Global sum: %d\n", global_sum);
    }

    MPI_Finalize(); 
    return 0;
}
