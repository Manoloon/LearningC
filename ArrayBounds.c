#ifndef ARRAYBOUNDS_H
#define ARRAYBOUNDS_H

#include <stdint.h>

// Arrays with Bounds Checking
// Have in mind that this should be done for each type
// that we need, in this case is for int32_t, but if you
// need for another type , say char : 

void OutOfBound()
{
    int* intArray = malloc(sizeof(int)*10); // 40 bytes
    int arrayLen = 10;
    
    // Bad Segmentation fault that will pass under the hood if not using sanitazer
    for(int i=0; i<=arrayLen; i++)
    {
        intArray[i] = 2;
    }
}

///////////////////////////////////////////////
// Array of Items char with Bounds checking
///////////////////////////////////////////////
typedef struct
{
    char* items;
    int32_t length;
    int32_t capacity;
}CharArray;
char CharArray_Get(CharArray array,int32_t index)
{
    if(index >= 0 && index < array.length)
    {
        return array.items[index];
    }
    return 0;
}
void IterateItemsChar(CharArray array)
{
    for(int i = 0;i <= array.length;i++)
    {
        char item = CharArray_Get(array,i);
        printf("%c\n",item);
    }
}
///////////////////////////////////////////////
// Array of Items int with Bounds checking
///////////////////////////////////////////////
typedef struct
{
    int32_t* items;
    int32_t length;
    int32_t capacity;
}Int32Array;

int Int32Array_Get(Int32Array array,int32_t index)
{
    if(index >= 0 && index < array.length)
    {
        return array.items[index];
    }
    return 0;
}

void IterateItemsInt(Int32Array array)
{
    for(int i = 0;i <= array.length;i++)
    {
        int item = Int32Array_Get(array,i);
        printf("%s\n",item);
    }
}

#endif
