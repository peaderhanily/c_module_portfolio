/* size.c : Practical Program 4
Program that displays the size of variables type int, char, float, double
and an int array with 3 elements, an char array with 4 elements, a float array with 5 elements
and a double array with 6 elements.
Author: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create int, char, float and double
	int size_of_int;
	char size_of_char;
	float size_of_float;
	double size_of_double;
	
	//Assign arrays
	int integer[3] ;
	char character[4];
	float decimal[5];
	double bigdecimal[6];

	//Variable byte size displays
	printf("\nVariable Sizes\n");
	printf("The size of an int %d\n", sizeof(size_of_int));
	printf("The size of a char %d\n", sizeof(size_of_char));
	printf("The size of a float %d\n", sizeof(size_of_float));
	printf("The size of a double %d\n\n", sizeof(size_of_double));

	//Arrays with elements byte size
	printf("Array Sizes\n");
	printf("The size of array int with 3 elements: %d\n", sizeof(integer));
	printf("The size of array char with 4 elements: %d\n", sizeof(character));
	printf("The size of array float with 5 elements: %d\n", sizeof(decimal));
	printf("The size of array double with 6 elements %d\n\n", sizeof(bigdecimal));

	return(0);
}





