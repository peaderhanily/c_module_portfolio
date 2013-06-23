/* prac20.c : Practical Program 20
Demonstrate fgets function
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

const int MAX_LENGTH= 100; // Create a constant variable which will be the sentance length in this case 100 it is a global variable

int main (void)
{
	char sentance[MAX_LENGTH]; // create a constant string which length of 100 using constant variable

	printf("Enter a Sentance\n");//ask user to enter a sentance
	
	fgets(sentance, MAX_LENGTH, stdin);//fgets is used instead of scanf. It is made up of 3 parts (the variable, the length(number) 
											//and the input type in this case standard input :stdin
											
	printf("Your input: %s\n",sentance);//Display input

	// What the fgets function does is copy the string (including spaces between words) into the variable

	return 0;
}