#ifndef ALLOC_H
#define ALLOC_H
#define CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
/*
    Dynamic Memory allocation : malloc() - free()
*/
int testDynamicMalloc()
{
    int *array;
    int num_elems;
    int sum = 0;
    printf("Enter Number of elements: ");
    scanf("%d",&num_elems);
    array = (int*) malloc(num_elems * sizeof(int));
    if(array == NULL)
    {
        printf("Memory allocation Failed\n");
        return 1;
    }
    printf("enter %d integers:\n",num_elems);
    for(int i = 0; i < num_elems;i++)
    {
        printf("Element %d:",i+1);
        scanf("%d",&array[i]);
    }
    for(int i = 0; i < num_elems;i++)
    {
        sum +=array[i];
    }
    printf("Sum of elements: %d",sum);
    free(array);
return 0;
}
int testDynamicMallocWithLeaks()
{
    int *array;
    int num_elems;
    int sum = 0;
    printf("Enter Number of elements: ");
    scanf("%d",&num_elems);
    array = (int*) malloc(num_elems * sizeof(int));
    if(array == NULL)
    {
        printf("Memory allocation Failed\n");
        return 1;
    }
    printf("enter %d integers:\n",num_elems);
    for(int i = 0; i < num_elems;i++)
    {
        printf("Element %d:",i+1);
        scanf("%d",&array[i]);
    }
    for(int i = 0; i < num_elems;i++)
    {
        sum +=array[i];
    }
    printf("Sum of elements: %d",sum);
    _CrtDumpMemoryLeaks();
return 0;
}
/*
    Memory Allocation for array with a define size for each element: calloc()
    void *ptr = calloc(num_elems,size_of_each_elem)
*/
#define SIZE 8
void printBoard(int **board)
{
    
    for(int i = 0; i < SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}
int** CreateBoard()
{
    int **board = (int**)calloc(SIZE,sizeof(int*));
    if (board == NULL) 
    {
        printf("Memory alloc failed\n");
        return NULL;
    }
    // Check if failed condition
    for(int i = 0; i < SIZE; i++)
    {
        board[i]=(int*)calloc(SIZE,sizeof(int));
        if(board[i] == NULL)
        {
            printf("Memory Alloc Failed\n");
            for(int j = 0; j < i; j++)
            {
                free(board[j]);
            }
            free(board);
            return NULL;
        }
    }
    // adding temp data
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = i+j;
        }
    }
    return board;
}
void freeBoard(int **board)
{
    if(board == NULL) return;
    for(int i = 0; i < SIZE; i++)
    {
        free(board[i]);
    }
    free(board);
}
// API
void RunCallocTest()
{
    int **board = CreateBoard();
    if(board != NULL)
    {
        printBoard(board);
        freeBoard(board);
    } 
}
/*
    Memory Reallocation : realloc()
    void *ptr = realloc(existing_pointer,new_size_in_bytes)
*/
void testRealloc()
{
    
}

#endif