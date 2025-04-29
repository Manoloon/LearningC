#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Src/Unions.h"
#include "Src/ArrayBounds.c"
#include "Src/ObjectPool.h"
#include "Src/BitWiseOP.h"
#include "Src/Alloc.h"
#include "Src/Decimals.c"
#include "Src/LinkedList.h"
#include "Src/Tree.h"

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
int main(int argc,char* argv[]) {
    /*
    char test[] = "Pablo";
    CharArray charArr = {test,5,10};
    IterateItemsChar(charArr);
    int intTest[] = {1,2,3,4,5,6,7,8};
    Int32Array intArr = {intTest,8,10};
    IterateItemsInt(intArr);
    char name[100];
    printf("Please insert your Name\n");
    fgets(name,sizeof(name),stdin);
    //trim the cut of line from name
    name[strlen(name)-1] = '\0';

    printf("Name : %s, length : %zu\n",(char*)&name,sizeof(name));
    // Testing Pointers and index
    // " GENERATIONAL INDEXES"
    // User[3] users={};
    // User* friend = UserArray_Get(users,john.friendIndex);

    // Testing structs vs unions
    CompareSizeOfStructVsUnion();
    TestUnionPolymorphic();

    PrintAmount(CHAR2,CHAR3);    
    //TestObjectPoolManagerSlow(2000);
    //TestObjectPoolManagerFast(2000);
    // note that this length is the total characters inside input = 3
    const char* input = "100";
    size_t length = strlen(input);
    printf("size %zu\n",length);

    const char str[] = "100";
    printf("char* address %p, string %s\n",(void*)&input,input);
    printf("char[] address %p, string %s\n",(void*)&str,str);
    */
    //RunCallocTest();
    TestTree(argc,argv);
    return 0;
}