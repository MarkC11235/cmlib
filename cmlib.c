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

//Helper Functions
//--------------------------------------------------
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
//--------------------------------------------------

//VECTOR2
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