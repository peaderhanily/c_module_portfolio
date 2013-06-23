/*****************************************************************************************************************
prac37.c : Practical Program 37
Description: Create a structure that has 3 variables (name, telephone, student number).
			Write a function that allows user to input these 3 things
			and store it in a structure. the function should take one parameter a pointer to a structure where it will store the input
			create 2 other functions 1 to write the function to the disk and one to read the function from the disk.
			When user runs the program it should give them the option
			of reading the program from the disk or entering new info and saving it to the disk
Authors: Peter Hanily
Last Modiefied: 05/12/12
*******************************************************************************************************************/

//Call Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create struct and use typedef so it can be defined as user_info
//Remember if you want studentnumber and telephone to start with 0 they have to be char arrays not ints which cannot start with 0
typedef struct s_user_info {
	char name[30];
	char telephone[20];
	char studentnumber[20];
} user_info;

//Declare functions and paramaters
void input_function(user_info *ptr);
void write_to_disk(FILE *fp1, user_info *ptr);
void read_from_disk(FILE *fp1, user_info *ptr);
void display(user_info *ptr);

int main(void)
{
	user_info user1;//Create struct user1
	FILE *fp1;//FILE pointer fp1
	int option;						
	
	do												// do while loop
	{
		//Display user menu
		printf("\n\n0 - QUIT\n");
		printf("1 - EDIT\n");
		printf("2 - Save and Display\n");
		printf("3 - Load and Display\n");
		fflush(stdout);

		scanf("%2d", &option);
		getchar();
		
		//Process option
		switch (option)									// switch statement to decide next action
		{
			case 1: input_function(&user1); display(&user1);//input into data sturcture and display inputed data on screen
				break;
			case 2:	 write_to_disk(fp1, &user1);printf("\nNew Record\n"); display(&user1);// write data struct to file and display structre on scrren
				break;
			case 3:	read_from_disk(fp1, &user1); display(&user1);
				break;
		}
	}while (option != 0);
	
	return 0;
}

//INPUT FUNCTION: Inputs data into struct by passing a pointer to the struct
void input_function(user_info *ptr)
{
	int len;
	
	//Input user name
	printf("\nPlease enter the Student Name: ");
	fgets(ptr->name, 30, stdin);
	len = strlen(ptr->name);
	ptr->name[len-1] = '\0';//Remove newline char '\n' from fgets input

	//input telephone number
	printf("\nPlease enter the telephone number: ");
	fgets(ptr->telephone, 20, stdin);
	len = strlen(ptr->telephone);
	ptr->telephone[len-1] = '\0';//Remove newline char '\n' from fgets input
	
	//input studentnumber
	printf("\nPlease enter the Student Number: ");
	fgets(ptr->studentnumber, 20, stdin);
	len = strlen(ptr->studentnumber);
	ptr->studentnumber[len-1] = '\0';//Remove newline char '\n' from fgets input
	
}

//WRITE TO DISK FUNCTIOn: Pass the pointer to the file(opened in write mode)and the pointer to the struct into the function
						//Then use fprinf to write to file
void write_to_disk(FILE *fp1, user_info *ptr)
{
	
	fp1 = fopen("prac37structurewords.txt", "w");//open file will right to a file if it does not exist
	
	fprintf (fp1, "%s %s %s", &ptr->name, &ptr->telephone, &ptr->studentnumber);//write 3 strings to text document
	
	fclose(fp1);
	
	printf("\n Record Saved\n\n");
}

//READ FROM DISK FUNCTION:This function passes the pointer to the file and then rights the file onto the console window
void read_from_disk(FILE *fp1, user_info *ptr)
{		
	fp1 = fopen("prac37structurewords.txt", "r");
	
	if((fp1 = fopen("prac37structurewords.txt","r")) == NULL)//Check if document opens
	{
		printf("\nWarning No File has been opened!!!\n");
		exit(0);//exit function exits the program
	}	
	
	while(fscanf(fp1, "%s %s %s", &ptr->name, &ptr->telephone, &ptr->studentnumber) != EOF)//while fscanf does not reach end of file
	{
	fscanf (fp1, "%s %s %s", &ptr->name, &ptr->telephone, &ptr->studentnumber);//insert data into struct
	}
	
	fclose(fp1);
}

//Displays data user has input in format and displays data read from file back into structure
void display(user_info *ptr)
{
	printf ("Student Name: %s \nStudent Telephone: %s\nStudent Number: %s",&ptr->name, &ptr->telephone, &ptr->studentnumber);
}