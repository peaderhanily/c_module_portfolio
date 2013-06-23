/* prac15.c : Practiacl Program 15
Program to display that a char variable is a byte size of 1 and ranges from 0 - 255
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	//Create variables and initalise values
	char c = 0;
	int x = 0;

	//create while loop 
	while(x <=10000)
	{
	c = c + 1; //add 1 to variable c each time it is looped
	printf("%d\n", c);//print variable each loop

	x++;//add 1 to x after every loop
	}

	//the char c will be treated as a byte therefore it will not go to 10000 it will vary in value between +127 or -128 
	//this represents the 256 values which a byte contains
	//It ends of 17 as it begins at 0 which in this instance 
	//chars are 1 byte in size that is why stays bettween -128 and +127
	
	return 0;
}