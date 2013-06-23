/* prac23.c : Practical Program 23
Modify earlier program (enter secret word to end with 3 guesses)
so that it uses a function to wait for the persons response.
Authors: Peter Hanily
Last Modiefied: 02/12/12
*/

#include <stdio.h>

void clear_screen(void);
void read_user_input(char word[]);
void wait_for_user(char word[]);

int main(void)
{

	char word[20];//create a string

	clear_screen();
	read_user_input(word);// pass created string into function which can read input and display result. other function inside can wait for user

	return 0;
}

void clear_screen(void)//small function I made to clear screen to see it more clearly for user
{
	int i;
	char p = '\n';
	for(i=0; i <= 200; i++)//for loop prints newline character 200 times then next function starts
		printf("%c",p);
}

void read_user_input(char word[])
{
	char SECRET[] = "pink";//create char variable present locally in function
	int i;//int to be used for the for loop. This is a local variable to the function
	
	for(i = 1; (i <= 3); i++)//for loop using i (initialise;condition;increment) in this case it begins at 1 you only have 3 chances ie 1,2,3 not 0,1,2,3
	{
	printf("\nPlease Enter the Secret Word To End The Program\n");//ask user to enter the secret word
	scanf("%19s", word);// used %19s to stop buffer overflow. remember scanf leaves \n at end
	getchar();//get char captures the end of the array so it allows the program to wait for user in the next function
	
	wait_for_user(word);//The function will now begin
	
	if(strcmp(SECRET, word) == 0)//compares printf will display if true
		{
		printf("\nYOU HAVE GUESSED CORRECTLY THE WORD WAS: %s\n", SECRET);
		break;//break is used as if the statement above is true it will end the loop
		}
		
	else
		{
		printf("\n\nGuess again %s was not the right word\n", word);//tell user that "what they entered" was not the right word
		printf("You have guessed %d\\3 \n", i);//This shows the user how many chances they have used ie 1/3.. 2/3.. 3/3
		}
	}

}

void wait_for_user(char word[])//function that waits for user starts passed variable word to function for display purposes
{
	char dummy [80];// local variable to function
	printf("\n\nYou entered: %s\n",word);
	printf("Press RETURN to continue:");
	fgets(dummy, 80, stdin);
}