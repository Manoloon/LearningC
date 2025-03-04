#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <stdio.h>
#include <assert.h>
#include <stdint.h>

typedef struct
{
    int x,y,z;
}Vector3;

typedef struct
{
    int allocated;
    Vector3 Object;
}ObjectPool;

#define NUM_MAX_OBJ 10
ObjectPool ObjectPoolManager[NUM_MAX_OBJ] = {0};

Vector3* BorrowObject(void)
{
    for(int i= 0; i < NUM_MAX_OBJ; i++)
    {
        if(ObjectPoolManager[i].allocated == 0)
        {
            ObjectPoolManager[i].allocated = 1;
            return &ObjectPoolManager[i].Object;
        }
    }
}

void ReturnObjectSlow(Vector3* obj)
{
    for(int i = 0; i < NUM_MAX_OBJ; i++)
    {
        if(&(ObjectPoolManager[i].Object) == obj)
        {
            assert(ObjectPoolManager[i].allocated == 1);
            ObjectPoolManager[i].allocated = 0;
            return;
        }
    }
    // if we get here , we are in trouble.
    //assert(false);
}

void TestObjectPoolManager(int n)
{
    assert(n > 2);
    printf("Testing Object pool");
    for(int i = 0 ; i < n; i++)
    {
        Vector3* v1 = BorrowObject();
        Vector3* v2 = BorrowObject();
        printf("Got Obj %d @ address %p %p\n",v1,v2);
        ReturnObjectSlow(v1);
        ReturnObjectSlow(v2);
    }
}

#endif