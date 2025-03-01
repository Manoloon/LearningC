# Learning C 

# Arrays with bounds checking
Defining a struct with the type the length and the capacity and using it as a container gives us the power to have a control check to the bounds.
<typedef struct
{
    char* items;
    int32_t* length;
    int32_t capacity;
}CharArray;>
We need to have one of this for each type that would be creating array of.

# Strings without using the string.h (apparently it have a lot of drawbacks)
For this we define an struct with a char pointer and the length
and we can go like this : 
<void PrintString(String string)
{
    for(int i = 0; i < string.length; i++)
    {
        printf("%c",string.chars[i]);
    }
}>