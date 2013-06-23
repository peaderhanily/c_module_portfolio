/* prac22.c : Practical Program 22
Write a program that asks the user to input any number of words
 and replace all vowels with $ and display results to user
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>
#include <string.h>//this calls many functions for strings which are useful


const int MAXLINE = 100;//Length of string

int main(void)
{
	//Declare variables
	char sentence[MAXLINE];
	int i, x;
	
	printf("Please write a sentence\n");
	fgets(sentence, MAXLINE, stdin);//use fgets for input
	
	x = strlen(sentence);//find the length of the string
	printf("what it looks like: %s\n", sentence);
	
	for(i=0; i < x ; i++)//for loop changes vowels capital and lowercase to $ using if statement
		{
			if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u'
			|| sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U')// || is the boolean operator for OR
				{
					sentence[i] = '$';//changes specific element which was a vowel to $
				}
		
		}
		
	printf("what it now looks like: %s\n", sentence);//prints what the sentance now looks like
	
	return 0;
}