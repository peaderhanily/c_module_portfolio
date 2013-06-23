/*********************************************************************************************************
 prac31.c : Practical Program 31
Program that reads secret word from a text file and has the same functionality as program 19(guess the secret word program)
Authors: Peter Hanily
Last Modiefied: 04/12/12
**********************************************************************************************************/

//call libray functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;// assign file pointer
	char secret[20];
	char word[20];//create input array to allow user to input secret word
	int i;//int to be used for the for loop and increments
		
	fp = fopen("prac31word.txt", "r");//open text file prac31word
	
	if(fp == NULL)//if the text file does not exist it will return a NULL and this warning message
	{
		printf("\nWarning No File has been opened!!!\n");
		exit(0);//exit function exits the program
	}
	
	fgets(secret, 20, fp);//writes contents of file to char string
	
	for(i = 1; (i <= 3); i++)//for loop using i (initialise;condition;increment) in this case it begins at 1 you only have 3 chances ie 1,2,3 not 0,1,2,3
	{
		printf("Please Enter the Secret Word To End The Program\n");//ask user to enter the secret word
		scanf("%19s", word);//use %19s to not allow buffer overflow
	
		if(strcmp(secret, word) == 0)//compares printf will display if true
		{
			printf("You have guessed correctly the word was %s\n", secret);
			break;//break is used as if the statement above is true it will end the loop
		}
		
		else
		{
			printf("Guess again %s was not the right word\n", word);//tell user that "what they entered" was not the right word
			printf("You have guessed %d\\3 \n", i);//This shows the user how many chances they have used ie 1/3.. 2/3.. 3/3
		}
	}
	
	fclose(fp);
	
	return 0;
}

/*ALTERNATE SOLUTION NOT VERY EFFICENT uses getc to put string into char array***************************************************************************

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;// assign file pointer
	int c;//EOF is a number -1 ie outside the normal range so when using getc and putc functions if you want to read end of file this must be an int
	char filename[40];// stores user string to allow user to chose file
	char secret[20];
	char word[20];//create input array to allow user to input secret word
	int i, j, len;//int to be used for the for loop and increments
	j=0;
	
	printf("Enter a flie name: ");
	fgets(filename, 40, stdin);//allow user to write filename
	filename[strlen(filename) - 1] = '\0'; //valid file name
		
	while(fp == NULL)//if the text file does not exist it will return a NULL program will loop until valid file entered
	{
	//repeat of code above to allow user to enter valid text file
	printf("\n\nYou hav not entered a valid filename please try again\n");
	printf("Enter a flie name: ");
	fgets(filename, 40, stdin)
	filename[strlen(filename) - 1] = '\0'; //valid filename
	fp = fopen(filename, "r");
	}
	
	c =getc(fp);//define that c is the next char in file
	
	while(c != EOF)//read until end of file is reached
	{
	secret[j] = c;
	j++;
	c=getc(fp);
	}
	
	
	
	for(i = 1; (i <= 3); i++)//for loop using i (initialise;condition;increment) in this case it begins at 1 you only have 3 chances ie 1,2,3 not 0,1,2,3
	{
	printf("Please Enter the Secret Word To End The Program\n");//ask user to enter the secret word
	scanf("%19s", word);//use %19s to not allow buffer overflow
	
	if(strcmp(secret, word) == 0)//compares printf will display if true
		{
		printf("You have guessed correctly the word was %s\n", secret);
		break;//break is used as if the statement above is true it will end the loop
		}
		
	else
		{
		printf("Guess again %s was not the right word\n", word);//tell user that "what they entered" was not the right word
		printf("You have guessed %d\\3 \n", i);//This shows the user how many chances they have used ie 1/3.. 2/3.. 3/3
		}
	}
	
	fclose(fp);
	
	return 0;
}
****************************************************************************************************************************************************/