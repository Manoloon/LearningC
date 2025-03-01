#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Arrays with Bounds Checking
// Have in mind that this should be done for each type
// that we need, in this case is for int32_t, but if you
// need for another type , say char : 

///////////////////////////////////////////////
// Array of Items char with Bounds checking
///////////////////////////////////////////////
typedef struct
{
    char* items;
    int32_t* length;
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
    int32_t* length;
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
///////////////////////////////////////////////
// Strings on C are insane haha
///////////////////////////////////////////////
typedef struct
{
    char* chars;
    int32_t length;
}String;
void PrintString(String string)
{
    for(int i = 0; i < string.length; i++)
    {
        printf("%c",string.chars[i]);
        //printf("%.*s", my_string.length, my_string.chars)
    }
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///////////////////////////
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
//    POINTERS : avoiding dangling pointer by using index
//    Saving space by using 32 bit index instead of 64 bits pointer
///////////////////////////////////////////////
typedef struct User
{
    String name;
    int32_t friendIndex;
} User;

typedef struct
{
    User* users;
    int32_t length;
    int32_t capacity;

}UserArray;

User UserArray_Get(UserArray array,int index)
{
    if(index >= 0 && index < array.length)
    {
        return array.users[index];
    }
    return;
}
///////////////////////////////////////////////
//    ARENA : Not use malloc and free like crazy
//    Lifetimes three flavours:
//    Static : create when the program start and delete when it ends
//    Function : Allocate when the function is called , and deallocate when it returns;
//    Task : (open file, etc)
///////////////////////////////////////////////
// TODO:
// Arena DocumentArena = (Arena)
// {
//     .capacity = DOCUMENT_ARENA_CAPACITY,
//     .memory = malloc(DOCUMENT_ARENA_CAPACITY),
//     .nextOffset = 0,
// };
///////////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* args[]) {
    //OutOfBound();

    // Testing Pointers and index
    // " GENERATIONAL INDEXES"
    // User[3] users={};
    // User* friend = UserArray_Get(users,john.friendIndex);
    return 0;
}