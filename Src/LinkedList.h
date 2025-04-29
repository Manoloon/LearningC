#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Linked-list, double linked-list and tree
*/
#define MAX_ITEM_LENGTH 100
struct Linked_list
    {
        char data[MAX_ITEM_LENGTH];
        struct Linked_list* next_ptr;
    };
struct Linked_list* first_ptr = NULL;
void add_item(const char* item)
{
    struct Linked_list* new_item_ptr;
    new_item_ptr = malloc(sizeof(struct Linked_list));
    if(new_item_ptr == NULL)
    {
        fprintf(stderr,"Memory Allocation failed\n");
        exit(1);
    }
    strncpy(new_item_ptr->data,item,MAX_ITEM_LENGTH-1);
    new_item_ptr->next_ptr = first_ptr;
    first_ptr = new_item_ptr;
}

struct Linked_list* find(char* name)
{
    struct Linked_list* current_ptr = first_ptr;
    while(current_ptr->next_ptr != NULL && 
        (strcmp(current_ptr->data,name) != 0))
    {
        current_ptr = current_ptr->next_ptr;
    }
    return current_ptr;
}

void del_item(char* name)
{
    struct Linked_list* current = first_ptr;
    struct Linked_list* prev = NULL;
    while (current != NULL)
    {
       if(strcmp(current->data,name)==0)
       {
        if(prev == NULL)
        {
            first_ptr = current->next_ptr;
        }
        else
        {
            prev->next_ptr = current->next_ptr;
        }
        free(current);
        return;
       }
       prev = current;
       current = current->next_ptr;
    }
}

void PrintItems()
{
    struct Linked_list* current_nextPtr = first_ptr;
    while (current_nextPtr != NULL)
    {
        printf("item %s\n",current_nextPtr->data);
        current_nextPtr = current_nextPtr->next_ptr;
    }
}