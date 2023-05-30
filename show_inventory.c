//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
//
//Author information
//  Author name: Johnny Fok
//  Author email: johnnyfok@csu.fullerton.edu
//  Course info: CPSC 223C, Spring 2023
//  Assignment #4
//
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>      //C header files use <>

void show_inventory(char * inventory_filename);

void show_inventory(char * inventory_filename)
{

//block to open file using user inputted filename + variables
    FILE * inventory_filepointer1 = fopen(inventory_filename, "r");
    char temp[1024];

//block to check and print file contents
    if (inventory_filepointer1 == NULL)
    { 
        printf("Error: unable to open the file. Make sure the name of the file is correct and run the program again.\n");
        printf("Bye\n");
    } //end of if statement
    else
    {
        printf("\n");
        while( fgets(temp, 1024, inventory_filepointer1) != NULL)
        {
            fputs(temp, stdout);
        }
        fclose(inventory_filepointer1);
        printf("\n\n");
    } //end of if else statement


}