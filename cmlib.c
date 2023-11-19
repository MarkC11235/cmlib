#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cmlib.h"

//TESTER
//--------------------------------------------------
void cmlibHello()
{
    printf("Hello from cmlib!\n");
}
//--------------------------------------------------

//Definitions
//--------------------------------------------------
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0])) // DOESN'T WORK WITH POINTERS

#define OUTPUT_ARRAY_SPACING 5
//--------------------------------------------------

//VECTOR2
//Possibly add in a result vector to the inputs so the only malloc is by the createVector function called by the user
//--------------------------------------------------
Vector2* createVector2(int x, int y)
{
    Vector2* result = malloc(sizeof(Vector2));
    result->x = x;
    result->y = y;
    return result;
}

Vector2* vector2Add(Vector2* a, Vector2* b)
{
    Vector2* result = createVector2(0, 0);
    result->x = a->x + b->x;
    result->y = a->y + b->y;
    return result;
}

Vector2* vector2Sub(Vector2* a, Vector2* b)
{
    Vector2* result = createVector2(0, 0);
    result->x = a->x - b->x;
    result->y = a->y - b->y;
    return result;
}

void vector2Print(Vector2* v)
{
    printf("(%d, %d)\n", v->x, v->y);
}
//--------------------------------------------------

//VectorN
//--------------------------------------------------
VectorN* createVectorN(int* data, int size)
{
    assert(data != NULL);
    assert(size > 0);
    assert(ARRAY_SIZE(data) == size);

    VectorN* result = malloc(sizeof(VectorN));
    result->data = data;
    result->size = size;
    return result;
}

void vectorNPrint(VectorN* v)
{
    printf("(");
    for(int i = 0; i < v->size; i++)
    {
        printf("%d", v->data[i]);
        if(i < v->size - 1)
        {
            printf(", ");
        }
    }
    printf(")\n");
}
//--------------------------------------------------

//Matrix
//--------------------------------------------------
Matrix* createMatrix(int* data, int rows, int cols)
{
    assert(rows > 0);
    assert(cols > 0);
    //When sending in a pointer, the array size marco will not work
    //This is becuase it just gets the size of the pointer, not the array
    //Right now, just trust the user to send in the correct size
    //assert(ARRAY_SIZE(data) == rows * cols);

    Matrix* result = malloc(sizeof(Matrix));
    result->data = data;
    result->rows = rows;
    result->cols = cols;
    return result;
}

//Still have to send in data so that way the user is allocating it
//send in data initialized with all zeros
Matrix* createIdentityMatrix(int* data, int rows, int cols){
    assert(rows > 0);
    assert(cols > 0);

    Matrix* result = malloc(sizeof(Matrix));
    result->rows = rows;
    result->cols = cols;

    for(int i = 0; i < rows; i++){
        data[i*cols + i] = 1;
    }

    result->data = data;

    return result;
}

void matrixAdd(Matrix* a, Matrix* b, Matrix* res)
{
    assert(a->rows == b->rows);
    assert(a->cols == b->cols);
    assert(res->rows == a->rows && res->cols == a->cols);
    //have rows in outer loop becuase C uses row major order, so looping through each row in order is faster
    for(int i = 0; i < a->rows * a->cols; i++){
        res->data[i] = a->data[i] + b->data[i];
    }
}

void matrixSub(Matrix* a, Matrix* b, Matrix* res)
{
    assert(a->rows == b->rows);
    assert(a->cols == b->cols);
    assert(res->rows == a->rows && res->cols == a->cols);
    //have rows in outer loop becuase C uses row major order, so looping through each row in order is faster
    for(int i = 0; i < a->rows * a->cols; i++){
        res->data[i] = a->data[i] - b->data[i];
    }
}

void matrixMul(Matrix* a, Matrix* b, Matrix* res){
    assert(a->cols == b->rows);
    assert(res->rows == a->rows && res->cols == b->cols);  

    for(int i = 0; i < a->rows; i++){
        for(int j = 0; j < b->cols; j++){
            int c = 0;
            for(int k = 0; k < a->cols; k++){
                c += a->data[i*a->cols + k] * b->data[k*b->cols + j];
            }
            res->data[i*res->cols + j] = c;
        }
    }
}

void matrixInverse(Matrix* a, Matrix* res){

}

int matrixComp(Matrix* a, Matrix* b){
    int total = 0;
    for(int i = 0; i < a->cols*a->rows; i++){
        total += a->data[i] - b->data[i];
    }
    return total;
}

void matrixPrint(Matrix* m)
{
    for(int i = 0; i < m->rows; i++)
    {
        printf("|");
        for(int j = 0; j < m->cols; j++)
        {
            printf("%*d", OUTPUT_ARRAY_SPACING, m->data[i * m->cols + j]); // The %*d looks at the 6 in the printf function and makes sure the output takes at least that much space
            if(j < m->cols - 1)
            {
                printf(", ");
            }
        }
        printf("|\n");
    }

    printf("\n");
}
//--------------------------------------------------