#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Linked-list, double linked-list and tree
*/
struct Linked_list
    {
        char data[30];
        struct Linked_list* next_ptr;
    };
struct Linked_list* first_ptr = NULL;
void add_item(int item)
{
    struct Linked_list* new_item_ptr;
    new_item_ptr = malloc(sizeof(struct Linked_list));
    strcpy(new_item_ptr->data,item);
    (*new_item_ptr).next_ptr = first_ptr;
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
    struct Linked_list* itemFound = find(name);
    if(itemFound != NULL)
    {
        if(itemFound == first_ptr)
        {
            struct Linked_list* newFirst_ptr = first_ptr->next_ptr;
            struct Linked_list* curr_next_ptr = newFirst_ptr->next_ptr;
            free(first_ptr);
            first_ptr = newFirst_ptr;
        }
    }
}

void PrintItems()
{
    struct Linked_list* current_nextPtr = first_ptr->next_ptr;
    while (current_nextPtr != NULL)
    {
        printf("item %c",current_nextPtr);
        current_nextPtr = current_nextPtr->next_ptr;
    }
    
}