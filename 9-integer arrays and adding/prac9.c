/* prac9.c : Practical Program 9
Program that stores numbers and resuly in int array. Display result of adding numbers and subtracting numbers
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create arrays 
	int number[2] ;
	int sum[2];

	//Ask user to input 2 numbers
	printf("enter 2 numbers\n");
	scanf("%5d", &number[0]);//first number accessed with number[0] as arrays start at 0
	scanf("%5d", &number[1]);//second number accessed with number[1]

	//Assign value of sum[0]
	sum[0] = number[0] + number[1];

	//Assign value of sum[1]
	sum[1] = number[0] - number[1];

	//Display results
	printf("\n%d + %d = %d\n",number[0], number[1], sum[0]);
	printf("\n%d - %d = %d\n",number[0], number[1], sum[1]);

	return(0);
}