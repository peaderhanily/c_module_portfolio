/* prac16.c :Practical Program 16
Create a program that asks the user to input a word and counts the characters in the word
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create variables and array
	char word[20];
	int i = 0;
	

	//Ask user to input a word to calulate length
	printf("Please enter a word to calculate string length\n");
	scanf("%19s", word);//use scanf with %19s to not allow user to overflow buffer
		
	while(word[i] !='\0')//array ends with \0 there word[i] != '\0' will count i until it is \0 then stop
	{
	i++;//++ is a quick way to increase i by 1 every loop
	}
	
	//Print the length of the string
	printf("The length of this string is %d", i);
	
	return 0;
}