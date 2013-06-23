/* prac18.c : Practical Program 18
This program is a loop that continues until you enter the secret word to stop it
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>
#include <string.h>

const char SECRET[] = "pink"; //constant is created before main function
							 //you could use #define SECRET[] = "pink" but compiler will decide what variable type it is
							 //this was used when it took more memory to use const method but no longer
							 //all Uppercase letters are used for these variable types to define difference in program they are global variables
int main(void)
{
	char word[20];//Create array
		
	while(strcmp(SECRET, word) == 1)//strcmp compares the secret word vs word if it is true it will be 0 otherwise it is any other number
	{
		
	printf("\nPlease Enter the Secret Word To End The Program\n");//Ask user to enter the secret word
	scanf("%19s", word);//user %19s to not allow buffer overflow
	
	if(strcmp(SECRET, word) == 0)//this means that if word inputed is the secret word program will end and prinf statement will appear
		{
		printf("\n\n\nYou have guessed correctly the word was pink\n");
		}
		
	else//if not secret word this prinf statement will appear
		{
		printf("Guess again %s was not the right word\n\n\n", word);
		}
	}
	
	return 0;
}