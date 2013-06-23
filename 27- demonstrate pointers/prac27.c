/* prac27.c : Practical Program 27
Demonstrate pointers, fgets and output these
Authors: Peter Hanily
Last Modiefied: 02/12/12
*/

#include <stdio.h>
#include <stdlib.h>//calls library function useful for pointers

const int SIZE = 50;//create a constant integer of 50 . This is a global variable

int main(void)
{
	char *array;// creates pointer array

	array=malloc(SIZE);
	
	printf("Please input a sentance\n");
	fgets(array, SIZE, stdin);// fgets is used to input characters made up of (variable, size of input,
								//stream or type of input in this case stdin or standard input from stdio.h header
	
	printf("The input was: %s\nThe address is: %u\n", array, array);//%s used to print whats in the string as the pointer points to the array with this value inside
																	//%u used to print out address which will be an unsigned int hence %u not %d. the address is where the values of the string is located
	
	free(array);//frees memory allocated to pointer this is used to avoid memory leaks in future
	
	printf("The input was: %s\nThe address is: %u\n",  array, array);// for demonstration purposes print out array value and address after been freed should be random


	return 0;
}