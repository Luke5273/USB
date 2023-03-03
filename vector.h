#ifndef VECTOR

#define VECTOR

typedef struct vector
{
    int* data;
    int capacity;
    int size;
}Vector;

Vector vec_init(int value); 

void vec_push(Vector* vec, int value);

void vec_put(Vector* vec, int value, int index);

int vec_remove(Vector* vec, int index);

int vec_pop(Vector* vec);

#define INDEX_CHECK() if(index > vec->size) {printf("Error: Index out of range\n"); exit(1);}

#endif