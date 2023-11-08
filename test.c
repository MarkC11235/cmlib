#include <stdio.h>
#include <stdlib.h>

#include "cmlib.h"

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix* a = createMatrix(x, 3, 3);
    Matrix* b = createMatrix(x, 3, 3);
    // matrixPrint(a);
    // matrixPrint(b);

    //inits array with all zeros
    int res[9] = {0};
    Matrix* c = createMatrix(res, 3, 3);

    matrixAdd(a, b, c);
    matrixPrint(c);

    matrixSub(a, b, c);
    matrixPrint(c);

    return 0;
}