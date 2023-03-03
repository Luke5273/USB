#include <stdio.h>

#include "vector.h"
#include "convert.h"

/// @brief state of the data currently
static int state = J;

Vector toNRZI(int* data, int flags)
{
    Vector output = vec_init(data[0] ^ state);
    
    int dataSize = sizeof(data)/sizeof(int);
    int repsOf1 = 0;

    for(int i = 1; i < dataSize; i++)
    {
        state ^= (data[i]^1);
        vec_push(&output, state);
        
        if(flags & BIT_STIFFING)
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