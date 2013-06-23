/*****************************************************************************************************************
prac32.c : Practical Program 32
Description : Write a program that can copy a text file
Authors: Peter Hanily
Last Modiefied: 04/12/12
*******************************************************************************************************************/

//call libray functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	FILE *fp1;
	int c;
	
	fp = fopen("prac32word.txt","r");//open file in read mode
	fp1 = fopen("prac32copiedword.txt","w");//open file in write mode
	
	if(fp == NULL)//check if 1st file opened correctly
	{
		printf("\nCannot open the program prac32word.txt\n");
		exit(1);
	}
	
	else//if both filesare ok carry out copying
	{
		c = getc(fp);//get first char
		while(c != EOF)// while c is not the end of the file
		{
			putc(c, fp1);//put first char to file
			c = getc(fp);//get next char
		}
	}
	
	printf("Files copied successfully");
	
	//close files
	fclose(fp);
	fclose(fp1);
	
	return 0;
}