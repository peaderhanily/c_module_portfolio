/* colourfirstletter.c : Practiacl Program 6
Ask User for Favorite Colour but output only first letter
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	char colour[16]; //Create array of 16, 15+1 (1 to end array)
	
	printf("Whats your favorite color?\n");//Ask user what favorite colour is
	scanf("%15s", colour); //Use scanf to input there favorite colour.
	
	colour[1] = '\0';//Arrays end with \0 and this is now assigned to 2nd char
	
	printf("You said: %s\n", colour);//Print out first letter. printf thinks array is over so only displays first char

	return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
First Soloution

#include <stdio.h>

int main(void)
{
	char colour[16]; //Create array of 16, 15+1 (1 to end array)

	printf("Whats your favorite color?\n");//Ask user what favorite colour is
	scanf("%15s", colour); //Use scanf to input there favorite colour.

	printf("You said: %c\n", colour[0]);//Print out first letter with %c and accessing first with clour[0] (arrays start at 0)

	return 0;
}
*/
//----------------------------------------------------------------------------------------------------------------------------------------------
/*
OR another soloution

#include <stdio.h>

int main(void)
{
	char colour[16]; //Create array of 16, 15+1 (1 to end array)

	printf("Whats your favorite color?\n");//Ask user what favorite colour is
	scanf("%1s", colour); //Use scanf to input there favorite colour. %1s will only allow 1 char to be entered

	printf("You said: %s\n", colour);//Print out first letter 

	return 0;
}
*/
