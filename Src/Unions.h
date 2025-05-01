#ifndef UNIONS_H
#define UNIONS_H
#include <stdio.h>
#include <stdbool.h>

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
    printf("Struct total size in bytes : %d\n",(int)sizeof(st));
    printf("Union total size in bytes : %d\n",(int)sizeof(un));
}

// Polymorphic
typedef struct
{
    char *name;
    bool Rounded;
    union Data
    {
        int area;
        float radius;
        
    }data;
}Shape;

void PrintActor(Shape* shape)
{
    printf("Shape name %s\n",shape->name);
    if(shape->Rounded)
    {
       
        printf("Shape Radius %f\n",shape->data.radius);
        printf("Actor total size in bytes : %llu\n",sizeof(shape));
    }
    else
    {
        printf("Shape Area %d\n",shape->data.area);
        printf("Actor total size in bytes : %llu\n",sizeof(shape));
    }
}

void TestUnionPolymorphic()
{
    Shape circle;
    circle.name = "Circle";
    circle.Rounded = true;
    circle.data.radius = 100.3f;
    Shape rect;
    rect.name = "Rectangle";
    rect.Rounded = false;
    rect.data.area = 60;
    PrintActor(&circle);
    PrintActor(&rect);
}

#endif