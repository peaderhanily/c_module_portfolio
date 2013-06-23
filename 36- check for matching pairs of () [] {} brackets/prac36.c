/*****************************************************************************************************************
prac36.c : Practical Program 36
Description: Write a program that inputs a .c source file and then counts the amount of brakets in the file (()[]{})
			it should then tell the user if the the amount of right brackets ([{ do not match the amount of left brackets })]
			the user should be able to specify the c file on the command line
Authors: Peter Hanily
Last Modiefied: 06/12/12
*******************************************************************************************************************/

//call headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])//second main function argument count and argument value
{
	FILE *fp1;// create file pointer
	int c;
	//LEFT BRACKETS 	type 1:[		type 2: ( 		type 3: {	0 to start out with
	int lft_bracket1 = 0;
	int lft_bracket2 = 0;
	int lft_bracket3 = 0;
	
	//RIGHT BRACKETS 	type 1:]		type 2: ) 		type 3: }	0 to start out with
	int Rht_bracket1 = 0;
	int Rht_bracket2 = 0;
	int Rht_bracket3 = 0;
	
	//print arguments from cmd line executable will be argv[0]
	printf("\nFile Entered: %s\n", argv[1]);
	
	//open file and assign to pointer
	fp1 = fopen(argv[1], "r");
			
	if(fp1 == NULL)//if the text file does not exist it will return a NULL and this warning message
	{
		printf("\nWarning No File has been opened please check the first file entered!!!\n");
		exit(0);//exit function exits the program
	}
	
	c =getc(fp1);//get first character
	
	//create loop that reads characters until the end of the file
	while(c != EOF)
	{
		//Create if statements for left type brackets and increment by 1 every time c is equal to one
		//type 1:[]		type 2: () 		type 3: {}
		if(c == '[')
		{
			lft_bracket1++;
		}
		
		else if(c == '(')
		{
			lft_bracket2++;
		}
		
		else if(c == '{')
		{
			lft_bracket3++;
		}
		
		//create if statements for right type brackets and increment by 1 every time c is equal to one
		else if(c == ']')
		{
			Rht_bracket1++;
		}
		
		else if(c == ')')
		{
			Rht_bracket2++;
		}
		
		else if(c == '}')
		{
			Rht_bracket3++;
		}
		
		c=getc(fp1);
	}
	
	//see if number of left type brackets equal the number of right type brackets and if they are display message or if not display message
	if(lft_bracket1 != Rht_bracket1)
	{
		printf("\n\nThere is an unequal number of [] type brackets in this file\n");
		printf("The Number of [ type brackets is %d\n",lft_bracket1);
		printf("The Number of ] type brackets is %d\n",Rht_bracket1);
	}
	
	if(lft_bracket2 != Rht_bracket2)
	{
		printf("\n\nThere is an unequal number of () type brackets in this file\n\n");
		printf("The Number of ( type brackets is %d\n",lft_bracket2);
		printf("The Number of ) type brackets is %d\n",Rht_bracket2);
	}
	
	if(lft_bracket3 != Rht_bracket3)
	{
		printf("\n\nThere is an unequal number of {} type brackets in this file\n\n");
		printf("The Number of { type brackets is %d\n",lft_bracket3);
		printf("The Number of } type brackets is %d\n",Rht_bracket3);
	}
	
	if(lft_bracket1 == Rht_bracket1 && lft_bracket2 == Rht_bracket2 && lft_bracket3 == Rht_bracket3)
	{
		printf("\n\nThere is an even number of all bracket types in this file,\nalthough they may not be in the correct order\n\n");
	}
	
	return 0;
}