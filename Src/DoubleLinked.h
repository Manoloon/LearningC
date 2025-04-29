#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Linked-list, double linked-list and tree
*/
struct Double_List
    {
        int data;
        struct Double_List* next_ptr;
        struct Double_List* prev_ptr;
    };
struct Double_List* first_ptr = NULL;
void double_add_item(struct Double_List* head_ptr,int item)
{
    struct Double_List* inserted_item = head_ptr;
    while (1)
    {
        inserted_item = inserted_item->next_ptr;
        if(inserted_item == NULL)
        {
            break;
        }
        if (item >= inserted_item->data)
        {
            break;
        }
    }
    
}

struct Double_list* find(int item)
{

}

void del_item(int item)
{

}

void PrintItems()
{
    
}