#ifndef CONVERT

#define CONVERT

#define J 0
#define K 1

#define NONE            0b00
#define BIT_STUFFING    0b01
#define SYNC            0b10
#define USB             0b11

Vector toNRZI(int* data, int size, int flags);

#endif