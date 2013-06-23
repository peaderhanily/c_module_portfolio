/* prac30.c : Practical Program 30
Program to demonstrate how to access elements inside pointers and change there values
Authors: Peter Hanily
Last Modiefied: 03/12/12
*/

#include <stdio.h>
#include <stdlib.h>//calls library functions useful for pointers

int main(void)
{
	//create char array pointers
	char *word;
	char *ptr;
	
	//assign 50 characters to char word using malloc
	word = malloc(50);
	
	//input into function using fgets
	fgets(word, 50, stdin);
	
	//make ptr have same memory address as word
	ptr = word;
	
	//access the 2nd and 4th value in pointer and change its address
	ptr[1] = '_';
	ptr[3] = '$';
	
	//print out what is now contained in char arrays
	printf("The input into word was: %s\n", word);
	printf("The input into ptr was: %s\n\n", ptr);
	
	//free memory
	free(word);
	free(ptr);
	
	//for demonstration purposes print what is now contained in word and ptr
	printf("After both ptr and word have been freed\n");
	printf("The input into word was: %s\n", word);
	printf("The input into ptr was: %s\n", ptr);
	
	return 0;
}