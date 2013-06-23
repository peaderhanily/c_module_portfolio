/* prac25.c : Practical Program 25.c
Create a Program that counts how many times a user uses a character of a certain type in a sentance
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>
#include <string.h>//calls library function useful when dealing with strings

int main(void)
{
	char sentance[100];//create an input array for sentance
	char letters[27] = "abcdefghijklmnopqrstuvwxyz";//input alphabet into array + 1 for end of array
	char cletters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//Input capital letters of alphabet + 1 for end of array
	int i, x, k, len;
	int count[27];//create a count variable to go through each letter
	
	printf("Please type a sentance:\n");//ask user to input a sentance use fgets
	fgets(sentance, 100, stdin);
	printf("You input: %s\n", sentance);//print sentance to make sure into was successful
	
	len = strlen(sentance) - 1;//strnlen used to calculate string length - 1 as it ends with \0
	
	for(k=0; k < 27; k++)//for loop clears count and makes sure its all blank
	{
	count[k] = 0;
	}
	
	for(i=0; i < len; i++)// this for starts i incrementing will be used with sentance array to count through array
	{
		for(x =0; x <= 26; x++)
		{
			if((sentance[i] == letters[x]) || (sentance[i] == cletters[x]))// if letter in sentance matches that stored in alphabet array (captial or normal) count[of that letter] +1
			{
			count[x]++;
			}
		}
	}

	for(i=0; i <26; i++)//prints out 26 alphabetic characters AND how many were counted for both capital and lowercase
	{
	printf("%c = %d\n", letters[i], count[i]);
	}
		
	return 0;
}

/* Another way of acomplishing the same goals of this proram would be to use a while loop with an if statement for 
every letter of the alphabet a-z && A-Z etc and have it + 1 every time on a counter however this would take an inordinate amount
of time and you would have to create many variables this way was deemed to be morre effiecent*/