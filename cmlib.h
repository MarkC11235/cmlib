//TESTER
//--------------------------------------------------
void cmlibHello();
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