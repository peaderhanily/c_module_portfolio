/* prac24.c : Practical Program 24
Create a program that has the same functionality as program 21 ie reveses the letters but does it within a function
Authors: Peter Hanily
Last Modiefied: 26/11/12
*/

#include <stdio.h>
#include <string.h>//calls more libray functions
#include <stdlib.h>//calls more library functions useful for pointers

void swap_chars_in_word(char* sentance, char* reversesen, int start);// function declaration

int main(void)
{
	//Create Pointers
	char *sentance;
	char *reversesen;
	
	int start = 0;
	
	//Assign Memory to pointers using malloc
	sentance = malloc(100);
	reversesen = malloc(100);

	printf("Enter a sentance: \n");
	fgets(sentance, 100 , stdin); // input string assigned to sentance array
								//stdin represents standard-input from the stdio.h header

	printf("sentance is: %s\n", sentance);

	swap_chars_in_word (sentance, reversesen, start);//function passes variables to be used in function.
	
	printf("reverse is: %s\n", reversesen);//prints the new value

	//free pointers this is used to avoid memory leaks etc
	free(sentance);
	free(reversesen);
	
	return 0;
}

void swap_chars_in_word(char* sentance, char* reversesen, int start)//function same as program 21 except placed inside function
{
	int len, i, j, k;
	
	len = strlen(sentance);
	sentance[len - 1] = ' '; // Replaces '\n' with a space so all words end with a space
		
	for (i = 0; i < len; i++) 
	{
		if (sentance[i] == ' ')
		{
			for(j = i-1, k = start; j >= start; j--)
			{
            reversesen[k] = sentance[j];
            k++;
			}
        start = i + 1;
        reversesen[i] = ' ';
		}
	}
	
}