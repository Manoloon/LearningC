#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
    int x,y,z;
}Vector3;

typedef struct
{
    bool allocated;
    Vector3 Object;
}ObjectPool;

#define NUM_MAX_OBJ 10
ObjectPool ObjectPoolManager[NUM_MAX_OBJ] = {0};

Vector3* BorrowObject(void)
{
    for(int i= 0; i < NUM_MAX_OBJ; i++)
    {
        if(ObjectPoolManager[i].allocated == false)
        {
            ObjectPoolManager[i].allocated = true;
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
            assert(ObjectPoolManager[i].allocated == true);
            ObjectPoolManager[i].allocated = false;
            return;
        }
    }
    // if we get here , we are in trouble.
    assert(false);
}

void ReturnObject(Vector3* obj)
{
    unsigned int i = ((uintptr_t)obj - (uintptr_t)ObjectPoolManager) / sizeof(ObjectPool);
    assert(&(ObjectPoolManager[i].Object) == obj);
    assert(ObjectPoolManager[i].allocated);
    ObjectPoolManager[i].allocated = false;
    return;
}


void TestObjectPoolManagerSlow(int n)
{
    assert(n > 2);
    printf("Testing Object pool");
    time_t startTimer,endTimer;
    double diffTime;
    time(&startTimer);
    for(int i = 0 ; i < n; i++)
    {
        Vector3* v1 = BorrowObject();
        Vector3* v2 = BorrowObject();
        printf("Got Obj %d @ address %p %p\n",i,v1,v2);
        ReturnObjectSlow(v1);
        ReturnObjectSlow(v2);
    }
    time(&endTimer);
    diffTime = difftime(endTimer,startTimer);
    printf("ObjectPool ends took  : %.2lf seconds to run\n",diffTime);
}

void TestObjectPoolManagerFast(int n)
{
    assert(n > 2);
    printf("Testing Object pool");
    time_t startTimer,endTimer;
    double diffTime;
    time(&startTimer);
    for(int i = 0 ; i < n; i++)
    {
        Vector3* v1 = BorrowObject();
        Vector3* v2 = BorrowObject();
        printf("Got Obj %d @ address %p %p\n",i,v1,v2);
        ReturnObject(v1);
        ReturnObject(v2);
    }
    time(&endTimer);
    diffTime = difftime(endTimer,startTimer);
    printf("ObjectPool ends took  : %.2lf seconds to run\n",diffTime);
}
#endif