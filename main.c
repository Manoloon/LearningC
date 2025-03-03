#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayBounds.c"

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
    User emptyUser = { " ", 1 };
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

///////////////////////////////////////////
// Union
///////////////////////////////////////////

struct structTest
{
    int x;
    float b;
    char str[10];
};
 
union unionTest
{
    int x;
    float b;
    char str[10];
};

void CompareSizeOfStructVsUnion()
{
    struct structTest st;
    union unionTest un;
    printf("Struct total size in bytes : %d\n",sizeof(st));
    printf("Union total size in bytes : %d\n",sizeof(un));
}

// Polymorphic
#define ACTOR_UNION_MAXSIZE 64
typedef enum 
{
    ActorAge,
    ActorPower,
    ActorName
} EActorData;

typedef struct
{
    EActorData actorData;
    union
    {
        int age;
        int power;
        char name[ACTOR_UNION_MAXSIZE];
    };
}ActorClass;

void PrintActor(ActorClass* actor)
{
    switch (actor->actorData)
    {
    case ActorAge:
        printf("actor age %d\n",actor->age);
        printf("Actor total size in bytes : %zu\n",sizeof(*actor));
        break;
    case ActorPower:
        printf("actor Power %d\n",actor->power);
        printf("Actor total size in bytes : %zu\n",sizeof(*actor));
        break;
    case ActorName:
        printf("actor Name %s\n",actor->name);
        printf("Actor total size in bytes : %zu\n",sizeof(*actor));
    default:
        break;
    }
}

void CreateAnActor(int a,int p, char* n,EActorData type)
{
    ActorClass actor;
    actor.age = a;
    actor.power = p;
    actor.actorData = type;
    strcpy(actor.name, n);
    PrintActor(&actor);
}

///////////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* args[]) {
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

    CompareSizeOfStructVsUnion();

    CreateAnActor(45,400,"Pablo",ActorAge);
    CreateAnActor(45,400,"Pablo",ActorPower);
    CreateAnActor(45,400,"Pablo",ActorName);
    return 0;
}