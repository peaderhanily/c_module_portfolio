/* colour.c : Practical Program 5
Program that asks user for favorite colour and displays it back to them
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)
{
	char colour[16]; //Create array of 16, 15+1 (1 to end array)

	printf("Whats your favorite color?\n");//Ask user what favorite colour is
	scanf("%15s", colour); //Use scanf to input there favorite colour. %15s used to only allow 15 characters be entered to stop overflow

	printf("You said: %s\n", colour);//Print favorite color

	return 0;
}