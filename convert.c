#include <stdio.h>

#include "vector.h"
#include "convert.h"

/// @brief state of the data currently
static int state = J;

Vector toNRZI(int* data, int size, int flags)
{
    state ^= (!data[0]);
    Vector output = vec_init(state);
    
    int repsOf1 = 0;

    for(int i = 1; i < size; i++)
    {
        state ^= (!data[i]);
        vec_push(&output, state);
        
        if(flags & BIT_STUFFING)
        {
            if(data[i] == 1)
                repsOf1++;

            if(repsOf1 == 6)
            {
                state ^= 1;
                vec_push(&output, state);
            }
        }
    }

    return output;
}