#include <stdio.h>
#include <stdlib.h>

#include "cmlib.h"

int main()
{
    int x[] = {1, 2, 3};
    Matrix* a = createMatrix(x, 3, 1);
    Matrix* b = createMatrix(x, 1, 3);
    matrixPrint(a);
    matrixPrint(b);

    //inits array with all zeros
    int res[9] = {0};
    Matrix* c = createMatrix(res, 3, 3);

    matrixMul(a, b, c);
    matrixPrint(c);

    return 0;
}