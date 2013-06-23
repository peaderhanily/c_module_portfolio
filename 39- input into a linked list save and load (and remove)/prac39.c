/*****************************************************************************************************************
prac39.c : Practical Program 39
Description: After completing programs 37 and 38 modify program to use a linked list
			The program should be able to store any number of students
			Design a way to save linked list to file and the load it again
Authors: Peter Hanily
Last Modiefied: 12/12/12
*******************************************************************************************************************/

//Call Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create struct and use typedef so it can be defined as a point
typedef struct sPOINT {
	char name[30];
	char telephone[20];
	char studentnumber[20];
	
	struct sPOINT* next;
} point;

point *create_element(void);								// function to create a node
point *add_point(point *start);								// function to add node
point *remove_point(point *start);							// function to remove a node
point *element_at_index(point *e, int index);				// function to find element at a specific index

void input(point *p);										// function for user input
void display(point *p);										// displays one particular node
void display_all(point *p);									// displays all nodes in list

void write_to_disk(FILE *fp1, point *p);					//writes all nodes to file
point *read_from_disk(FILE *fp1, point *start);				//reads file data back into linked list

int main(void)
{
	int option, i = 0;
	FILE *fp1;
	point *start =NULL;									// root node

	do													// do while loop
	{
		//Display user menu
		printf("\n\n0 - quit\n");
		printf("1 - ADD A Record\n");
		printf("2 - Remove A Record\n");
		printf("3 - Display All Records\n");
		printf("4 - Save\n");
		printf("5 - Load Saved Data\n");
		printf("Enter Option: ");
		fflush(stdout);

		scanf("%2d", &option);
		getchar();
		
		//Process option
		switch (option)									// switch statement to decide next action
		{
			case 1: start = add_point(start);
				break;
			case 2:	display_all(start); start = remove_point(start);
				break;
			case 3: display_all(start);
				break;
			case 4: write_to_disk(fp1, start);
				break;
			case 5: start = NULL; start = read_from_disk(fp1,start); printf("\nSAVED DATA:\n");
				break;
		}
	}while (option != 0);

	return 0;
}

//Function allocates a single element, and initialises its values
point *create_element()
{	
	point *p = (point*) malloc(sizeof(point));			// allocate memory
	p->next=NULL;										// set next pointer to NULL
	p->name;											// initialise user information
	p->telephone;										// initialise user information
	p->studentnumber;									// initialise user information

	
	return p;											// return pointer to point p
}

//Adds new point to the linked list. Remember start may be NULL.
point* add_point(point *start)
{
	point *last;
	point *n = create_element();						// creates a new point

	input(n);											//User inputfunction allows values to be set						
	
	//Add n to the end of the list
	if (start != NULL) 							
	{
		for (last = start; last->next != NULL; last = last->next);	// iterate to end of list
		last->next = n;												// add new point to end of list
	}
	else start=n; 													//this element is the new start

	
	return start;
}

//return a pointer to the element at the specified index. This shows a list of all Nodes by iterating through them
point *element_at_index(point *e, int index)
{
	for (; index > 0 && e != NULL; index--, e=e->next);			// each iteration jumps to the next node - perform this loop index number of times and you reach the desired node
	return e;
}

//REMOVE POINT: This Funtion allows the user to remove an element from a linked list and returns a pointer
point *remove_point(point *start)
{
	point *rem, *previous;
	int index,count;
	
	if (start == NULL)										// error checking
	{
		printf("No elements to remove\n");
		return start;
	}

	printf("Which element index do you want to remove? (starting from 0)\n");
	scanf("%9d", &index);

	//The first element is a special case as the 2nd element will become the start
	if (index == 0)
	{
		point *next = start->next;									// set pointer
		free(start);												// free memory
		return next;												// return from function
	}
	
	//find the element to remove and the previous element
	rem = element_at_index(start, index);							// find node to remove
	previous = element_at_index(start, index-1);					// set previous node (node before node you want to remove)

	if (rem == NULL)												// if node not found
	{
		printf("Invalid index: %d\n", index);
		return start;
	}

	previous->next = rem->next;			// set the previous element to point to the one after the one being removed
	free(rem);							// free memory
	return start;						// return from function
}

//INPUT VALUES INTO ELEMENTS: allow user to input values
void input(point *p)
{	
	int len1=0, len2=0, len3=0;
	
	//Input user name
	printf("\nPlease enter the Student Name: ");
	fgets(p->name, 30, stdin);
	len1 = strlen(p->name);
	p->name[len1-1] = '\0';								//Remove newline char '\n' from fgets input

	//input telephone number
	printf("\nPlease enter the telephone number: ");
	fgets(p->telephone, 20, stdin);
	len2 = strlen(p->telephone);
	p->telephone[len2-1] = '\0';						//Remove newline char '\n' from fgets input
	
	//input studentnumber
	printf("\nPlease enter the Student Number: ");
	fgets(p->studentnumber, 20, stdin);
	len3 = strlen(p->studentnumber);
	p->studentnumber[len3-1] = '\0';					//Remove newline char '\n' from fgets input
	
	display(p);											//displays inserted information
}

//DISPLAY SINGLE ELEMENT: used to display single record after each record input.
void display(point *p)
{
	printf ("\nStudent Name: %s\nStudent Telephone: %s\nStudent Number: %s\n",p->name, p->telephone, p->studentnumber);
}

//DISPLAY ALL ELEMENTS: Used to diplay all elements in the list and can be called by the user
void display_all(point *p)
{
	int count=0;
	
	if (p == NULL)									// check if list is NULL
	{
		printf("No elements in the list!\n");
		return;										//Leave function
	}

	for (; p != NULL; p = p->next)					// iterate over all points and print them on screen
	{
		printf("%d: ", count);
		printf("\nRECORD %d\nStudent Name: %s\nStudent Telephone: %s\nStudent Number: %s\n\n", count, p->name, p->telephone, p->studentnumber);
		count++;
	}
	printf("\n\n");
}

//WRITE TO DISK FUNCTION: This saves the all records to a text document called prac39structurewords.txt in specific format
void write_to_disk(FILE *fp1, point *p)
{

	int i;
	fp1 = fopen("prac39structurewords.txt", "w");//open file

	for (; p != NULL ; p = p->next)							// iterate over all points and print
	{
		fprintf(fp1,"%s %s %s\n", &p->name, &p->telephone, &p->studentnumber); // print each point on newline as p changes
	}
	printf("\nFILE SAVED\n");//tell user file has saved
	
	fclose(fp1);//close file
}

//READ FROM DISK FUNCTION:This function can be called by the user to read data from txt doc back into lined list each record a seperate NODE
point *read_from_disk(FILE *fp1, point *start)
{
	int count = 0;
	point *last;
	point *n;
	fp1 = fopen("prac39structurewords.txt", "r");//open document
	
	if((fp1 = fopen("prac39structurewords.txt","r")) == NULL)//Check if document opens
	{
		printf("\nWarning No File has been opened!!!\n");
		exit(0);//exit function exits the program
	}		
	
	while((fscanf (fp1,",%s%s%s\n",&n->name, &n->telephone, &n->studentnumber)) != EOF)//while it is not the end of the file
	{
	n = create_element();																// creates new point

	fscanf(fp1,",%s%s%s\n",&n->name, &n->telephone, &n->studentnumber);					//insert information on line into point						
	
	//Add n to the end of the list
	if (start != NULL) 							
	{
		for (last = start; last->next != NULL; last = last->next);	// iterate to end of list
		last->next = n;												// add new point to end of list
	}
	else start=n; 													//if start is null
		
		fscanf (fp1,"%s%s%s\n",&n->name, &n->telephone, &n->studentnumber);//This node becomes new start of linked list

		printf("\nRECORD %d\nStudent Name: %s\nStudent Telephone: %s\nStudent Number: %s\n\n", count, &n->name, &n->telephone, &n->studentnumber);
		count++;
	}
	fclose(fp1);//close file
	
	return start;//return this linked list into main function
}