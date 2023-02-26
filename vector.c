#include <stdlib.h>
#include <string.h>
#include "vector.h"

Vector vec_init(int value)
{
    Vector output;
    output.capacity = 1;
    output.size = 1;
    output.data = malloc(sizeof(int));
    output.data[0] = value;

    return output;
}

void vec_put(Vector* vec, int value, int index)
{
    INDEX_CHECK();

    if(vec->size >= vec->capacity)
    {
        vec->capacity = (vec->capacity)*2;
        vec->data = reallocarray(vec->data, vec->capacity, sizeof(int));
    }

    for(int i = vec->size; i >= index; i--)
    {
        vec->data[i+1] = vec->data[i];
    }

    vec->data[index] = value;
    vec->size++;
}

void vec_push(Vector* vec, int value)
{
    vec_put(vec, value, vec->size);
}

int vec_remove(Vector* vec, int index)
{
    INDEX_CHECK();
    
    int out = vec->data[index];
    vec->size--;
    for(int i = index; i < vec->size; i++)
    {
        vec->data[i] = vec->data[i+1];
    }

    return out;
}

int vec_pop(Vector* vec)
{
    return vec_remove(vec, vec->size-1);
}