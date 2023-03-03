#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"

#define INDEX_CHECK() if(index > vec->size) {printf("Error: Index out of range\n"); exit(1);}

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

    while(vec->size >= vec->capacity)
    {
        vec->capacity = (vec->capacity)*2;
        vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));
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

int vec_get(Vector* vec, int index)
{
    INDEX_CHECK();
    return vec->data[index];
}

void vec_set(Vector* vec, int index, int val)
{
    INDEX_CHECK();
    vec->data[index] = val;
}