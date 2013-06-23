/* colouroverflow.c : Practiacl Program 7
Example of what happens when there is a buffer overflow
Authors: Peter Hanily
Last Modiefied: 01/12/12
*/

#include <stdio.h>

int main(void)

{
	char colour[3]; //Create array of 3(small) for example purposes

	printf("Whats your favorite color?\n");//Ask user what favorite colour is
	scanf("%s", colour); //Use scanf to input there favorite colour. %numbers not used so no stop on buffer overflow

	//In this example hold a for 1 minute to see effects of buffer overflow
	//There will be a run time error if a lot of chars entered but it may work if it only goes over by a few however this is not desirable
	
	printf("You said: %s\n", colour);//Print favorite color

	return 0;
}