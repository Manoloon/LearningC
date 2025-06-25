#pragma once
#include <stdio.h>
/*
Stack
*/
#define MAX_NAME_CHAR 20
typedef struct node_t
{
    int data;
    char name[MAX_NAME_CHAR];
}node_t;

typedef struct stack_t
{
    int size;
    int top;
    node_t* items;
}stack_t;

void init(stack_t* stack, int capacity)
{
    stack->size = capacity;
    stack->top = -1;
    stack->items = (node_t*)malloc(sizeof(node_t)* capacity);
}

void push(stack_t* stack,node_t* item)
{
    if(stack->top == stack->size -1)
    {
        stack->size *= 2;
        stack->items = (node_t*)realloc(stack->items, sizeof(node_t)*stack->size);
        if(!stack->items)
        {
            fprintf(stderr, "Memory allocation failed for stack expansion");
            exit(EXIT_FAILURE);
        }
    }
    stack->top +=1;
    stack->items[stack->top] = *item;
}

node_t pop(stack_t* stack)
{
    node_t result = {.data = -1, .name = '\0'};

    if(stack->top >= 0)
    {
        result = stack->items[stack->top];
        stack->top--;
    }
    return result;
}

void destroy_stack(stack_t* stack)
{
    free(stack->items);
    stack->items = NULL;
    stack->size = 0;
    stack->top = -1;
}