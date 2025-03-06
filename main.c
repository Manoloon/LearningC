#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Src/Unions.h"
#include "Src/ArrayBounds.c"
#include "Src/ObjectPool.h"

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
    User emptyUser = {{(char *)" ",1},(int32_t) 1 };
    return emptyUser;
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
int main() {
    char test[] = "Pablo";
    CharArray charArr = {test,5,10};
    IterateItemsChar(charArr);
    int intTest[] = {1,2,3,4,5,6,7,8};
    Int32Array intArr = {intTest,8,10};
    IterateItemsInt(intArr);
    // Testing Pointers and index
    // " GENERATIONAL INDEXES"
    // User[3] users={};
    // User* friend = UserArray_Get(users,john.friendIndex);

    // Testing structs vs unions
    CompareSizeOfStructVsUnion();
    TestUnionPolymorphic();

    //TestObjectPoolManagerSlow(2000);
    //TestObjectPoolManagerFast(2000);

    return 0;
}