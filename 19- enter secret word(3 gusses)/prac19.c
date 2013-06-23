/* prac19.c : Practical Program 19
In this example you must enter the secret word to end the program or enter a wrong one 3 times
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

const char SECRET[] = "pink";//create constant char variable which is present globally in program

int main(void)
{

	char word[20];//create input array
	int i;//int to be used for the for loop
	
	
	
	for(i = 1; (i <= 3); i++)//for loop using i (initialise;condition;increment) in this case it begins at 1 you only have 3 chances ie 1,2,3 not 0,1,2,3
	{
	printf("Please Enter the Secret Word To End The Program\n");//ask user to enter the secret word
	scanf("%19s", word);//use %19s to not allow buffer overflow
	
	if(strcmp(SECRET, word) == 0)//compares printf will display if true
		{
		printf("You have guessed correctly the word was %s\n", SECRET);
		break;//break is used as if the statement above is true it will end the loop
		}
		
	else
		{
		printf("Guess again %s was not the right word\n", word);//tell user that "what they entered" was not the right word
		printf("You have guessed %d\\3 \n", i);//This shows the user how many chances they have used ie 1/3.. 2/3.. 3/3
		}
	}
	
	return 0;
}