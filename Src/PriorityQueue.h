#pragma once
#include <stdio.h>
#include <stdlib.h>

/*
Priority Queue (High and low)
*/
#define MAX_PQNODE 100

typedef struct PQNode_t
{
    int data;
    int priority;
}PQNode_t;

typedef struct PQueue_t
{
    PQNode_t heap[MAX_PQNODE];
    int size;

}PQueue_t;

void pq_swap(PQNode_t* a, PQNode_t* b)
{
    PQNode_t temp = *a;
    *a = *b;
    *b = temp;
}

int pq_parent(int i) 
{
    return (i-1)/2;
}
int pq_left(int i)
{
    return 2*i+1;
}
int pq_right(int i)
{
    return 2*i+2;
}

void heapify(PQueue_t* pq, int i)
{
    int left = pq_left(i);
    int right = pq_right(i);
    int smallest = i;

    if(pq->heap[i].priority < pq->heap[smallest].data)
    {
        if(left < pq->size) smallest = left;
        else if (right < pq->size) smallest = right;
    }
    if(smallest != i)
    {
        pq_swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq,smallest);
    }
}

PQNode_t pq_dequeue(PQueue_t* pq)
{
    if(pq->size == 0)
    {
        fprintf(stderr,"Priority size is 0");
        exit(EXIT_FAILURE);
    }
    PQNode_t pq_root = pq->heap[0];
    pq->size--;
    pq->heap[0] = pq->heap[pq->size];
    heapify(pq,0);
    return pq_root;
}

void pq_enqueue(PQueue_t* pq,int data,int priority)
{
    if(pq->size > MAX_PQNODE) return;

    int i = pq->size++;
    pq->heap[i].data = data;
    pq->heap[i].priority = priority;

    while(i != 0 && pq->heap[pq_parent(i)].priority > pq->heap[i].priority)
    {
        pq_swap(&pq->heap[i],&pq->heap[pq_parent(i)]);
        i = pq_parent(i);
    }
}

void PQ_test()
{
    PQueue_t pq = {.size = 0};
    printf("PRIORITY QUEUE \n");
    pq_enqueue(&pq, 100, 2);
    pq_enqueue(&pq, 200, 1);
    pq_enqueue(&pq, 300, 3);

    while (pq.size > 0) {
        PQNode_t n = pq_dequeue(&pq);
        printf("Data: %d, Priority: %d\n", n.data, n.priority);
    }
}