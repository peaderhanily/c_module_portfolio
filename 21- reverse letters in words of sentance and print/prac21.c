/* prac21.c : Is the 21st practical we're doing in class
Program that asks user to input sentance reverse letters in words in the sentance and give input to user
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>
#include <string.h>//calls more library functions is useful when using strings

const int MAX_LENGTH = 100;//constant variable of type int is available globally

int main(void)
{
	char sentance[MAX_LENGTH]; // create array using constant variable as size so it is char sentance[100];
	char reverse[MAX_LENGTH];//create array which will be the reverse of the letters also using constant variable size
	int len, i, j, k;
	int start = 0;

	printf("Enter a sentance: \n");
	fgets(sentance, MAX_LENGTH, stdin);//Use fgets function to enter string into sentance array
	
	len = strlen(sentance);//this uses strlen which is calculates the length of the string including spaces and \n at end
	sentance[len - 1] = ' '; // Replace '\n' with space to make string end with space

	printf("\nsentance is: %s\n\n", sentance);//display what the user entered

	for (i = 0; i < len; i++)//condition of for loop means that loop stops before the end of the string
	{
		if (sentance[i] == ' ')//when the sentance reaches a space it will begin the following for loop
		{
			for(j = i-1, k = start; j >= start; j--)//for loop reverses chars by using j-- as a decrement and k++ as increment
			{										//This means that as reverse[k] increase sentance[j] goes back therefore reversing postion of letters
            reverse[k] = sentance[j];				//once completed loop ends and next loop is read
            k++;
			}
		start = i + 1;//these statements keep words in same place so sentance and words don't reverse 
        reverse[i] = ' ';//it des this by making the elements in reverse blank before switchng them above
		}
	}
	printf("\nreverse is: %s\n", reverse);//print reverse of string to the user

	return 0;
}


