/* prac11.c : Practical Program 11
Modify program to use a while loop where condition is "while c is = newline" and "statement should call is getchar()"
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create array and char c
	char word[10];
	char c;

	printf("Enter a word:\n");//Ask user to input wor
	scanf("%9s", word);//scanf for user to input word
	printf("enter any character:\n");//Ask user to input a character
	
	//Not part of question but could use this to input character into c: scanf("%1c", &c);
	
	//while loop will loop until c is not '\n'
	while(c == '\n')//condition inside ()
	{
	c = getchar();//call getchar()
	}

	//if statement will dispaly condition if c char is a newline
	if (c == '\n') printf("warning char contains a new line\n");
	printf("you entered word: %s char: %c\n", word, c);


return 0;
}