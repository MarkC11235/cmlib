//TESTER
//--------------------------------------------------
void cmlibHello();
//--------------------------------------------------

//Helper Functions/Macros
//--------------------------------------------------
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
//--------------------------------------------------

//VECTOR2
//--------------------------------------------------
typedef struct {
    int x;
    int y;
} Vector2;

// Creates a vector
// User must free the vector
Vector2* createVector2(int x, int y);

// Adds two vectors together
Vector2* vector2Add(Vector2* a, Vector2* b);
// Subtracts two vectors
Vector2* vector2Sub(Vector2* a, Vector2* b);

// Print a vector
void vector2Print(Vector2* v);
//--------------------------------------------------

//VectorN
//--------------------------------------------------
typedef struct {
    int* data;
    int size;
} VectorN;

VectorN* createVectorN(int* data, int size);
VectorN* vectorNAdd(VectorN* a, VectorN* b);
VectorN* vectorNSub(VectorN* a, VectorN* b);

void vectorNPrint(VectorN* v);
//--------------------------------------------------

//Matrix
//--------------------------------------------------
typedef struct {
    int* data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int* data, int rows, int cols);
void matrixAdd(Matrix* a, Matrix* b, Matrix* res);
void matrixSub(Matrix* a, Matrix* b, Matrix* res);
void matrixMul(Matrix* a, Matrix* b, Matrix* res);
void matrixInverse(Matrix* a, Matrix* res);

void matrixPrint(Matrix* m);
//--------------------------------------------------