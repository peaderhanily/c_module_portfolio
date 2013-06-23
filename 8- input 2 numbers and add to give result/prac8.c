/* prac8.c : Practical Program 8
Program that asks the use to input 2 numbers and add them together to display result
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create int variables
	int number1;//first number
	int number2;//second number
	int sum;//sum of both numbers added together

	//Ask user to input the first number
	printf("Please input one whole number\n");
	scanf("%5d", &number1);//ampersand assigns inputted value to number1
	
	//Ask User to input the second number
	printf("Please input a second whole number\n");
	scanf("%5d", &number2); // ampersand assignes inputted value to number2

	//Add both numbers to create value for int sum
	sum = number1 + number2;

	//display result to user
	printf("\n%d + %d = %d\n",number1,number2,sum);

	return 0;
}