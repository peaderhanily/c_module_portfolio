/*****************************************************************************************************************
prac34.c : Practical Program 34
Create a Program that asks the user to enter two file names on the cmd line and it will compare the files to see if there the same and
display a message if they are
Authors: Peter Hanily
Last Modiefied: 05/12/12
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])//second main function argument count and argument value
{
	FILE *fp1;// create file pointers
	FILE *fp2;
	char ca, cb;
	
	//print arguments from cmd line executable will be argv[0]
	printf("\nFirst File: %s\n", argv[1]);
	printf("Second File: %s\n", argv[2]);
	
	//open files and assign to pointer
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");
		
	if(fp1 == NULL)//if the text file does not exist it will return a NULL and this warning message
	{
		printf("\nWarning No File has been opened please check the first file entered!!!\n");
		exit(0);//exit function exits the program
	}

	else if(fp2 == NULL)//if second text file does not exist
	{
		printf("\nWarning No File has been opened please check the second file entered!!!\n");
		exit(1);//exit function exits the program
	}
	
	else//Now files can be compared
	{
		ca = getc(fp1);//gets char from first file and and assigns it to ca
		cb = getc(fp2);//gets char from second file and and assigns it to cb
		
		while(ca != EOF && cb != EOF && ca == cb)//this only happens if they are not at the end AND equal to each other
		{
			ca = getc(fp1);
			cb = getc(fp2);
		}
		
		if(ca==cb)//if files identical
		{
			printf("\n\nThe files are Identical\n\n");
		}
		
		else if(ca !=cb)//if files not identical
		{
			printf("\n\nFiles Differ\n\n");
		}
	}
	
	//close files
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}