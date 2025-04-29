#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char* data;
    struct node* left;
    struct node* right;
};

static struct node* root = NULL;

char SaveString(char* string)
{
    char* new_string = malloc((unsigned)(strlen(string) + 1));
    if(new_string == NULL)
    {
        fprintf(stderr,"Error: Out of memory\n");
        exit(8);   
    }
    strcpy(new_string,string);
    return (new_string);
}

void insert(struct node** node, char* word)
{
    char* SaveString(char *);
    if((*node) == NULL)
    {
        (*node) = malloc(sizeof(struct node));
        if((*node) == NULL)
        {
            fprintf(stderr,"Error: Out of memory\n");
            exit(8);
        }
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->data = SaveString(word);
        return;
    }
    int result = strcmp((*node)->data, word);
    if(result == 0)
        return;
    if(result < 0)
        insert(&(*node)->right,word);
    else
        insert(&(*node)->left,word);
}

void find(char* name)
{
    char word[100];
    int index = 0;
    FILE in_file = fopen(name,"r");
    if(in_file == NULL)
    {
        fprintf(stderr,"Error:Unable to open %s\n",name);
        exit(8);
    }
    while (1)
    {
        int ch = fgetc(in_file);
        if(!isalpha(ch)|| (ch == EOF))
            break;
        word[0] = ch;
        for(index = 0; index < sizeof(word); ++index)
        {
            ch = fgetc(in_file);
            if(!isalpha(ch))
                break;
            word[index] = ch;
        }
        word[index] = '\0';
        insert(&root,word);
    }
    fclose(in_file);
}

void printTree(struct node* top)
{
    if(top == NULL)
        return;
    printTree(top->left);
    printf("%s\n",top->data);
    printTree(top->right);
}

int TestTree(int argc,char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Error:Wrong number of parameters\n");
        fprintf(stderr,"    on the command line\n");
        fprintf(stderr, "Usage is:\n");
        fprintf(stderr,"    words 'file'\n");
        exit(8);
    }
    find(argv[1]);
    printTree(root);
    return (0);
}