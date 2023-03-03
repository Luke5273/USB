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

#endif