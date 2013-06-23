/* prac13.c : Practiacl Program 13
Create a calculator program that allows user to perform more that 1 calculation.
It should end when user enters q
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

	do 
	{
	//Ask user to input sign
	printf("\nPlease enter a sign: +,-,*,/,q(end program) and press enter \n");
	sign = getchar();//This means it can only be a single char
	
		if(sign != 'q')
		{
		//Ask user to input two numbers
		printf("Enter a number\n");
		scanf("%9d", &one);
		printf("Enter a second number\n");
		scanf("%9d", &two);
			
		result = 0;//Make sure it becomes 0 after every loop
			
		//if, else if's and else
		if(sign == '+')  //== is boolean operator meaning equal to
		{result = one + two;}

		else if(sign == '-')
		{result = one - two;}

		else if(sign == '*')
		{result = one * two;}

		else if(sign == '/')
		{result = one / two;}

		//Remember that result is a float
		printf("\n%d %c %d = %.02f\n\n\n\n",one, sign, two, result); //%.02f will round it up to 2 decimal places
		
		getchar();//This will get the last character so that when loop starts again it will not enter '\0' as a sign
		}
	}while(sign != 'q');

	//Show that loop is over
	printf("You pressed q for sign. This program is over!!");
	
	return 0;


}