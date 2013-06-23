/*****************************************************************************************************************
prac35.c : Practical Program 35
Description: Write a Program that displays file contents 20 lines at a time. The program pauses after displaying 20 lines
and asks the user to press q to quit or return to see the next 20 lines or
Authors: Peter Hanily
Last Modiefied: 05/12/12
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	FILE *fp1;
	char option[10];
	int c;
	int line =0;
	fp1 = fopen("lipsum.txt", "r");//open file in read mode
		
	if(fp1 == NULL)//if the text file does not exist it will return a NULL and this warning message
	{
		printf("\nWarning No File has been opened please check the first file entered!!!\n");
		exit(0);//exit function exits the program
	}
	
	c = getc(fp1);// get first character
	
	while(c != EOF)//continue untill the end of the file
	{
		putchar(c);//print each character
		
		if(c == '\n')//if c is a newline char increment line counter by 1
		{
			line = line +1;
		}
		
		if(line == 20)// if line counter is 20 
		{
			line = 0;//reset line to 0
			printf("\n\n\n\nReturn for next 20 lines OR q to end program\n\n\n\n");
			fgets(option, 10, stdin);
			
			if(option[0] == 'q')//if q end program with message
			{
				printf("\n\nYou have ended the program Goodbye\n\n");
				exit(1);
			}
		}
		c=getc(fp1);//get next character
	}
	
	printf("\n\nYou have reached the end of the file\n\n");//tell user they have reached end of file

	return 0;
}