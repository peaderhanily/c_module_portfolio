/* prac17.c : Practical Program 17
This calculates the string length using a for loop
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create Variable and array
	char word[20];
	int i;

	//Ask user to enter a word
	printf("Please enter a word to calculate string length\n");
	scanf("%19s", word);//stop buffer overflow by having %19s
	
	
	
	for(i=0 ; word[i] != '\0'; i++)// for loop (inialiser; condition; increment) it does not need the int inialised before and the increment during like while loop
	
	//Print value of string length
	printf("The length of this string is %d", i);
	
	return 0;
}