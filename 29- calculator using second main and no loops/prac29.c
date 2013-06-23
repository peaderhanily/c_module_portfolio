/* prac29.c : Practical Program 29
Make a Calculator using second main function and not using loops
Authors: Peter Hanily
Last Modiefied: 03/12/12
*/

#include <stdio.h>

int main(int argc, char *argv[])//2nd main function argc: is the argument count, argv is the argument value. .exe is the first argument
{
	float num1, num2;//create variables floats can have decimals
	
	//print arguments at the momment
	printf("%s", argv[1]);
	printf("%s", argv[2]);
	printf("%s\n", argv[3]);
	
	//change string arguments to ints using sscanf (argument, type of variable %f/%d etc, attach to variable using ampersand)
	sscanf(argv[1], "%f", &num1);
	sscanf(argv[3], "%f", &num2);
	
	//if statements look what operator was entered in the second argument and then do the sum
	if (*argv[2] == '+')
	{
	printf("%.02f\n", num1+num2);//%.02f makes numbers round up to decimal places
	}

	if (*argv[2] == '-')
	{
	printf("%.02f\n", num1-num2);//%.02f makes numbers round up to decimal places
	}

	if ((*argv[2] == 'x')|| (*argv[2] == '*'))//x OR * used for multiplication here as per question but * is still the multiplcation operator in the equation
	{
	printf("%.02f\n", num1*num2);//%.02f makes numbers round up to decimal places
	}

	if (*argv[2] == '/')
	{
	printf("%.02f\n", num1/num2);//%.02f makes numbers round up to decimal places
	}	

	return 0;
}