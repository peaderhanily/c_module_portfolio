/*****************************************************************************************************************
prac38.c : Practical Program 38
Description: Expand on Practical Program 37 by adding more students
			This Program creates an input structure for a file called prac38structurewords.txt it allows up to 20 records be inserted
			It uses 3 functions to input data to a struct, to write to disk and to read from disk
Authors: Peter Hanily
Last Modiefied: 08/12/12
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create STRUCT and use typdef. typdef changes struct to now be called user info
typedef struct s_user_info { 
	char name[30];
	char telephone[20];
	char studentnumber[20];
} user_info;

//Funtion declarations
void input_function(user_info *ptr, int *count);
void write_to_disk(FILE *fp1, user_info *ptr, int *count);
void read_from_disk(FILE *fp1, user_info *ptr);


int main(void)
{
	user_info user[20];//Create array of structs
	FILE *fp1;//FILE pointer
	int c, len, count = 0;
	int option;
	
	read_from_disk(fp1, &user[0]);

	do												// do while loop
	{
		//Display user menu
		printf("\n\n0 - QUIT\n");
		printf("1 - ADD Records\n");
		printf("2 - Save & Display\n");
		fflush(stdout);

		scanf("%2d", &option);
		getchar();
		
		//Process option
		switch (option)									// switch statement to decide next action
		{
			case 1: input_function(&user[0], &count);
				break;
			case 2:	 write_to_disk(fp1, &user[0], &count); read_from_disk(fp1, &user[0]);
				break;
		}
	}while (option != 0);
	
	return 0;
}

//INPUT FUNCTION: In this function we allow user the choice of entering up to 20 function
				// Menu options are given so that user can decide to enter more students or quit
				//A record of how many students are entered is kept in int variable count
void input_function(user_info *ptr, int *count)
{
	//Local Variabless
	int len1, i;
	char optionf[80];
	
	//For loop keeps looping if up to 20 Records AND end adding records 'e' not selected
	for(i=0; (i < 20) && (optionf[0] != 'e'); i++)
	{	
		//Give user the option to add a record or not
		printf("\n'E' To Finish\n'A' To Add Another Record(MAX 20 students): ");
		fgets(optionf, 80, stdin);
		len1 = strlen(optionf);
		optionf[len1-1] = '\0';//fgets puts \n at end of array get rid of it here
				
		if(optionf[0] == 'a' || optionf[0] == 'A')//If add more records select  enter data into struct
		{
			printf("\nPlease enter the Student Name: ");
			fgets(ptr[*count].name, 30, stdin);
			len1 = strlen(ptr[*count].name);
			ptr[*count].name[len1-1] = '\0';

			printf("\nPlease enter the telephone number: ");
			fgets(ptr[*count].telephone, 20, stdin);
			len1 = strlen(ptr[*count].telephone);
			ptr[*count].telephone[len1-1] = '\0';
	
			printf("\nPlease enter the Student Number: ");
			fgets(ptr[*count].studentnumber, 20, stdin);
			len1 = strlen(ptr[*count].studentnumber);
			ptr[*count].studentnumber[len1-1] = '\0';
			
			(*count)++;//Increment count before displaying how many records have been created
			printf("\nyou have created %d records", *count);//tell user how many records they have created
		}
		else if(optionf[0] == 'e' || optionf[0] == 'E')//if e selectd stop adding records end loop
		{
			printf("\n\nyou have created %d records\n\n", *count);
			break;
		}
		else//if the user inputs another character by mistake -1 from i to allow user to still input 20 records as loop still increments
		{
			i--;
		}
	}
}

//WRITE TO DISK FUNCTION: In this function pass the pointer to the file, the pointer to the struct array and a pointer to the record count
						//Then use fprinf to write to file each record using a for loop which writes a max of 20 records
						//i < *count and not i <= *count used as a condtion as it only prints out however many records user created and
						// the for loop and arrays start at 0 but count goes up to 20 therefore if I made it be <= 20 it would create a 21st record
void write_to_disk(FILE *fp1, user_info *ptr, int *count)
{	
	int i;
	fp1 = fopen("prac38structurewords.txt", "w+");
	
	for(i= 0; i <*count && i <20; i++)//i < *count and not i
	{
		fprintf (fp1, "%s %s %s\n",&ptr[i].name, &ptr[i].telephone, &ptr[i].studentnumber);// write each record to a new line
	}
	
	fclose(fp1);
}

//READ FROM DISK FUNCTION: This function reads from the file and displays info in terminal window
							//It will not work if it is reading from a file that does not exist
void read_from_disk(FILE *fp1, user_info *ptr)
{
	int i, x = 1;
	
	fp1 = fopen("prac38structurewords.txt", "r+");//open file
	
	if((fp1 = fopen("prac38structurewords.txt","r+")) == NULL)//check if file exists
	{
		printf("\nWarning No File has been opened!!!\n");
		exit(0);//exit function exits the program
	}

	//continue through all records untill end of file. max 20 records displayed
	for(i =0; i<20 &&fscanf(fp1, "%s%s%s", &ptr[i].name, &ptr[i].telephone, &ptr[i].studentnumber) != EOF; i++)
	{
	fscanf (fp1, ",%s%s%s",&ptr[i].name, &ptr[i].telephone, &ptr[i].studentnumber);//read each record
	printf ("RECORD %d\nStudent Name: %s\nStudent Telephone: %s\nStudent Number: %s\n\n", x ,&ptr[i].name, &ptr[i].telephone, &ptr[i].studentnumber);//print each record
	x++;//count variable increments it starts at 1 goes to 20
	}
	
	fclose(fp1// close file
}