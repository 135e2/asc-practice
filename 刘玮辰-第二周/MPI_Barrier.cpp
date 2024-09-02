#include<iostream>
#include<cstdio>
#include<mpi.h>
using namespace std;
int main(int argc, char** argv)
{
    int size=0;
    int rank=0;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int data=0, global_sum=0;
        // ÿ����������һЩ����
    for (int i = 0; i < 10; ++i) {
        data += rank * 10 + i; // �����������ص�����
    }
    // ���δͬ��ǰ������
    printf("Process %d before barrier: Data = %d\n", rank, data);

    // ִ������ͬ��
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&data,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    // ���ͬ���������
    printf("Process %d after barrier: Data = %d\n", rank, data);
    printf("GLOBAL_SUM: %d\n\n",global_sum);
    MPI_Finalize();
    return 0;
}
