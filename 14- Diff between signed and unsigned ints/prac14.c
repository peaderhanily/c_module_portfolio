/* prac14.c : Practiacl Program 14
Program to display differences between signed and unsigned integers
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create int with value of 1
	int number = 1;
	
	//Display value of signed int could be + or - but is + by default
	printf("%d\n",number);

	//Subtract 2 as per question
	number = number - 2;
	
	//Change %d to %u which is an unsigned int....It now cannot be a - number so will display as 4292067295 which is the maximum size of an int
	printf("%u",number);

    return 0;
}
