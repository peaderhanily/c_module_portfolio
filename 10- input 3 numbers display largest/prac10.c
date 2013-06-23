/* prac10.c : Practical Program 10
Program that asks user to input 3 numbers and display largest to the user
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create Variables
	int one, two, three;

	//Ask User to input 3 variables
	printf("\nInput 3 different numbers of your choice\n");
	scanf("%9d", &one);
	scanf("%9d", &two);
	scanf("%9d", &three);

	
	//This is if the biggest number is one
	if ((one > two) && (one > three))// This is the condition if it is true it will display whats inside{}. && is the logical operator it means AND
	{
	printf("The biggest number was: %d", one);
	}
	
	//This is if the biggest number is two
	else if((two>one) && (two>three))
	{
	printf("The biggest number was: %d", two);
	}

	//This is if the biggest number is three
	else if((three>one) && (three>two))
	{
	printf("The biggest number was: %d", three);
	}

	return 0;

}