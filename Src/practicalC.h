#pragma once 
#include <stdio.h>
/*
	convert centigrad to fahrenheit F = 9/5 * C + 32
	calc volume of a sphere 4/3 * PI * r^3
	calc perimeter of a rect p = 2 * (w + h)
	convert km/h to mi/h miles = km * 0.6213712
	a program that takes hours and minutes as input and output the total num of minutes . 1 h 30 min = 90 min
	a program that takes an int as num of minutes and output the total num of hours and minutes . 90 min = 1h 30 min
	
*/

// write a program that use pointers to zeroed an array.
void ZeroedArray(int* array,size_t Size)
{
	for(size_t i=0;i < Size;++i)
	{
		printf("array element before being zeroed %d\n",array[i]);
		array[i] = 0;
		printf("array element after being zeroed %d\n",array[i]);
	}
}

// write a func that takes a single string as arg and return a pointer to the first character in the string.
