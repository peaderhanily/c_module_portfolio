/* prac28.c : Practical Program 28
Demonstrate the difference between arrays and pointers by repeating program 27 but changing char *array to char array[]
Authors: Peter Hanily
Last Modiefied: 02/12/12
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char array[30];//character array of 30 created

	fgets(array, 30, stdin);// fgets used to insert input into char array
	
	printf("The input was: %s\n The address is: %u\n", array, array);//prints input of string and prints array address
	
	return 0;
}
//The array has an address it sets aside a block of memory like