#include <stdio.h>
#include <stdlib.h>

#include "cmlib.h"

int main()
{
    VectorN* v1 = createVectorN((int[]){1, 2, 3, 4, 5, 6, 7}, 7);

    vectorNPrint(v1);

    free(v1->data);
    free(v1);

    return 0;
}