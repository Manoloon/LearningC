#pragma once

/*
    Crazy pointers use
*/
void ModifyIntegerThroughPointers(int* target)
{
    // Store the address of the target pointer in a void pointer.
    void* addressOfTargetPtr = &target;
    // Cast the void pointer to a pointer to an array of ints pointers.
    // this allows safe deferencing to access the original pointer.
    int* *(arrOfIntsPtrs)[] = (int*(*)[])addressOfTargetPtr;
    // Deference to get the array, then the int pointer, then the int and assign 1 to it.
    (*(*arrOfIntsPtrs))[0] = 1;
}
