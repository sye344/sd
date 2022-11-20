#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SYS_matrix_copy 451


int main(int argc, char **argv)
{
  
    float matrix1[2][2] = { {1.98, 2.93 }, {3.23, 4.33} };
    float matrix2[2][2];
 
    printf("Making system call with matrix1 and matrix 2\n");

    long res = syscall(SYS_matrix_copy, matrix1, matrix2);

    printf("System call returned %ld.\n", res);
    perror("Console Output");

    printf("Matrix 2 : - After system call\n");

    for(int i = 0 ; i< 2 ; i++){

        for(int j =0 ; j<2 ; j++){

            printf("%f ",matrix2[i][j]);
        }

        printf("\n");
    }

    return res;
}
