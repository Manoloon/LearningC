#pragma once
#include <stdio.h>
#include <math.h>

void PrintDecimal(float n)
{
    printf("%0.4E\n",n);
}

void AddDec(float A, float B)
{
    float C = A + B;
    printf("Add %0.4E + %0.4E = ",A,B );
    PrintDecimal(C);
}
void SubDec(float A, float B)
{
    float C = A - B;
    printf("Sub %0.4E - %0.4E = ",A,B);
    PrintDecimal(C);
}
void MultDec(float A,float B)
{
    float C = A * B;
    printf("Mult %0.4E * %0.4E = ",A,B );
    PrintDecimal(C);
}
void DivDec(float A, float B)
{
    if(B < 1)
    {
        fprintf(stderr, "avoid Divided by Zero\n");
        return;
    }
    float C = A / B;
    printf("Div %0.4E / %0.4E = ",A,B );
    PrintDecimal(C);
}