#include <stdio.h>
#include <stdlib.h>

#include "cmlib.h"

int main()
{
    // int x[] = {1, 2, 3};
    // Matrix* a = createMatrix(x, 3, 1);
    // Matrix* b = createMatrix(x, 1, 3);
    // matrixPrint(a);
    // matrixPrint(b);

    // //inits array with all zeros
    // int res[9] = {0};
    // Matrix* c = createMatrix(res, 3, 3);

    // matrixMul(a, b, c);
    // matrixPrint(c);

    //int* data = malloc(sizeof(int) * 25);
    int data[4] = {0};
    Matrix* iden = createIdentityMatrix(data, 2, 2);
    matrixPrint(iden);

    int data1[4] = {1, 2, 3, 4};
    Matrix* a = createMatrix(data1, 2, 2);
    Matrix* invRes = createMatrix(data, 2, 2);

    printf("matrix comp res : %d", matrixComp(iden, a));

    return 0;
}