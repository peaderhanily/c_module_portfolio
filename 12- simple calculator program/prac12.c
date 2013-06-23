/* prac12.c : Practical Program 12
Make a simple Calculator program
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create variables...remeber that if division is used it could be decimal so use float for results
	int one, two;
	float result;
	char sign;

	//Ask user to input sign
	printf("\nPlease pick what you would like to do +,-,*,/\n");
	scanf("%c", &sign);

	//Ask user to input two numbers
	printf("\nEnter 2 numbers\n");
	scanf("%9d", &one);
	scanf("%9d", &two);
	
	//if, else if's and else
	if(sign == '+')  //== is boolean operator meaning equal to
	{
	result = one + two;
	}

	else if(sign == '-')
	{
	result = one - two;
	}

	else if(sign == '*')
	{
	result = one * two;
	}

	else//Could use else if(sign == '/' here
	{
	result = one / two;
	}

	//Remember that result is a float
	printf("\n%d %c %d = %.02f",one, sign, two, result); //%.02f will round it up to 2 decimal places


	return 0;

}