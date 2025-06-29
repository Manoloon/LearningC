#pragma once
#include <stdlib.h>
#include<stdio.h>
/*
    Simple Queue
*/

typedef struct Qnode_t
{
    int data;
    struct Qnode_t* next;
}Qnode_t;

typedef struct queue_t
{
    Qnode_t* front;
    Qnode_t* back;
}queue_t;

queue_t* create_queue()
{
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = NULL;
    q->back = NULL;
    return q;
}

bool is_empty(queue_t* q)
{
    return q->front == NULL;
}

void enqueue(queue_t* q, int val)
{
    Qnode_t* node = (Qnode_t*)malloc(sizeof(Qnode_t));
    node->data = val;
    node->next = NULL;
    if(is_empty(q))
    {
        q->back = node;
        q->front = node;
    }
    else
    {
        q->back->next = node;
        q->back = node;
    }
}

int dequeue(queue_t* q)
{
    if(is_empty(q)) return -1;
    Qnode_t* temp = q->front;
    int result = temp->data;
    q->front = q->front->next;
    if(is_empty(q))
    {
        q->back = NULL;
    }
    free(temp);
    return result;
}

int peek(queue_t* q)
{
    if(is_empty(q)) return -1;
    return q->front->data;
}

void queue_test()
{
    printf("Start Queue Test\n");
    queue_t* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue : Front: %d\n", peek(q)); // 10

    printf("Queue : Dequeued: %d\n", dequeue(q)); // 10
    printf("Queue : Dequeued: %d\n", dequeue(q)); // 20

    enqueue(q, 40);

    printf("Queue : Front: %d\n", peek(q)); // 30

    while (!is_empty(q)) {
        printf("Queue : Dequeued: %d\n", dequeue(q));
    }
    free(q);
}