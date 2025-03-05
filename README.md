# Learning C 

# Arrays with bounds checking
Defining a struct with the type the length and the capacity and using it as a container gives us the power to have a control check to the bounds.

typedef struct
{
    char* items;
    int32_t* length;
    int32_t capacity;
}CharArray;

We need to have one of this for each type that would be creating array of.

# Strings without using the string.h (apparently it have a lot of drawbacks)
For this we define an struct with a char pointer and the length
and we can go like this : 

void PrintString(String string)
{
    for(int i = 0; i < string.length; i++)
    {
        printf("%c",string.chars[i]);
    }
}

# Unions :
The difference with an struct is that the struct will allocate memory for each member of the struct
Example :

struct 
{
    int x; // 4 bytes
    float b; // 4 bytes
    char str[10]; // 12 bytes
}
this struct has allocate : 20 bytes in total.
Now Union will allocate the amount for the LARGER, in this case
char str[10] = 12 bytes.

Another useful use hehe of the union is, as in C there is no polymorphic idea as a Class u Objects,
we can use union as a solution for this.

# Object pool
Object pools are super useful as a way to avoid malloc and free for each object created, also it 