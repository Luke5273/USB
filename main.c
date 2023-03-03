#include <stdio.h>
#include "vector.h"
#include "convert.h"

int main()
{
    int data[] = {1,0,0,1,0,1,0};
    Vector NRZI = toNRZI(data, 0);

    for(int i = 0; i < NRZI.size; i++)
    {
        printf("%d", NRZI.data[i]);
    }printf("\n");
}