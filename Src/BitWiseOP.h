#ifndef BITWISEOP_H
#define BITWISEOP_H
#include <stdio.h>

typedef enum
{
    CHAR1 = 1,
    CHAR2 = 2,
    CHAR3 = 4,
    CHAR4 = 8
}character_t;

void PrintAmount(character_t a, character_t b)
{
    printf("Char A is : %d\n",a);
    printf("Char B is : %d\n",b);
    printf("a & b = %d\n", a & b);  // AND
    printf("a | b = %d\n", a | b);  // OR
    printf("a ^ b = %d\n", a ^ b);  // XOR
    printf("~a = %d\n", ~a);        // NOT
    printf("a << 1 = %d\n", a << 1); // Left shift
    printf("a >> 1 = %d\n", a >> 1); // Right shift
    printf("b << 1 = %d\n", b << 1); // Left shift
    printf("b >> 1 = %d\n", b >> 1); // Right shift
}

#endif