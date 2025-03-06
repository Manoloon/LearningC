#ifndef BUGS_C
#define BUGS_C

void TheAwfulSemicolon()
{
    int sum = 0;
    for(int i = 0;i < 5; i++) //; // this semicolon will give you headache
    {
        sum += i;
    }
    printf("Sum = %d\n",sum);
}



#endif