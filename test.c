#include <stdio.h>
#include <stdlib.h>

#include "cmlib.h"

int main()
{
    int x[] = {1, 2, 3, 4};
    Matrix* a = createMatrix(x, 2, 2);
    Matrix* b = createMatrix(x, 2, 2);
    // matrixPrint(a);
    // matrixPrint(b);

    //inits array with all zeros
    int res[4] = {0};
    Matrix* c = createMatrix(res, 2, 2);

    matrixAdd(a, b, c);
    matrixPrint(c);

    //matrixSub(a, b, c);
    //matrixPrint(c);

    return 0;
}