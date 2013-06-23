/* prac26.c : Practical Program 26
The second main function 1st demonstration
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(int argc, char* argv[])//this is the second main made up of the argument count(argc) and the argument value(argv[])
{								// what you enter on the cmd line can then be accessed in the program 
	int i;						//important to not that argv[0] is the excecutable 
								//spaces represent the gap between arguements
	printf("You supplied %d arguments\n", argc);
	
	for(i=0; i <argc; i++)
	{
	printf("argument %d = %s\n", i, argv[i]);
	}

	//this program shows how many arguments were entered on the cmd line and their values

	return 0;
}