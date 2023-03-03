#include <stdio.h>
#include "vector.h"
#include "convert.h"

int main()
{
    int data[] = {1,1,1,1};  //011111111
    Vector NRZI = toNRZI(data, sizeof(data)/sizeof(int), NONE);

    for(int i = 0; i < NRZI.size; i++)
    {
        printf("%d", NRZI.data[i]);
    }printf("\n");
}