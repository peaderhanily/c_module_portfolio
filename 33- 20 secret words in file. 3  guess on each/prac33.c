/*****************************************************************************************************************
prac33.c : Practical Program 33
Description: Create a Program that reads a secret word from a textt file with 20 secret words. It reads the first secret word and gives user 3 gueses
			when the user guesses correctly it moves onto second word and then gives the user 3 more guesses
Authors: Peter Hanily
Last Modiefied: 05/12/12
*******************************************************************************************************************/

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;//pointer for file
	char *secret;
	char *word;
	char a;
	int i, c, secword;
	
	secword = 1;
	secret = malloc(20);
	word = malloc(20);
	fp = fopen("prac33secretwords.txt", "r");//open text file prac31word and assign to pointer
	
	if((fp = fopen("prac33secretwords.txt", "r")) == NULL)//if the text file does not exist it will return a NULL and this warning message
	{
		printf("\nWarning No File has been opened!!!\n");
		exit(0);//exit function exits the program
	}
	
		
	while(secword <= 20)//loop ends when 20 secret words entered
	{
		fscanf(fp, "%s", secret);
					
		for(i = 1; i <= 3; i++)//for loop using i (initialise;condition;increment) in this case it begins at 1 you only have 3 chances ie 1,2,3 not 0,1,2,3
		{
			printf("Please Enter the Secret Word To End The Program\n");//ask user to enter the secret word
			scanf("%s", word);
			getchar();
			
			if(strcmp(secret, word) == 0)//compares printf will display if true
			{
				printf("You have guessed correctly the word was %s\n", secret);

				if(secword == 20)
				{
					printf("\nCongrats you have entered all 20 secret words\n");
				}
				
				secword = secword + 1;
				break;//break is used as if the statement above is true it will end the loop
			}
			
			else if(i == 3)//if third guess wrong exit the program with the following message
			{
				printf("You have used all your guesses %d/3", i);
				exit(1);
			}
		
			else
			{
				printf("Guess again %s was not the right word\n", word);//tell user that "what they entered" was not the right word
				printf("You have guessed %d\\3 \n", i);//This shows the user how many chances they have used ie 1/3.. 2/3.. 3/3
			}
		}
	}
	
	//free pointers and close files
	free(secret);
	free(word);
	fclose(fp);

	return 0;
}