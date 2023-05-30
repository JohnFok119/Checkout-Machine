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

int purchase_item( FILE *inventory, char *inventory_filename, char *shopping_cart[], int global_count, int total_quantities[]);

int purchase_item( FILE *inventory, char *inventory_filename, char *shopping_cart[], int global_count, int total_quantities[])
{
//block to open file + variables
    char *ptr;
    int found = 0;      // 0 = NOT found  1 = FOUND

    char item[128];
    char available[128];

    int char_count = 0;
    int temp_count = 0;
    char space_x_space[10] = " x ";

    int quantity = 0;
    char s_quantity[10];

    char temp[1024] = {0};

//block to receive user input
    printf("\nEnter the name of item wanted. Must match first 8 characters: ");
    getchar();
    fgets(item, 128, stdin);
    item[strlen(item) - 1] = '\0';
    item[0] = toupper(item[0]);
    //printf("the item you want is:%s\n", item);
    rewind(inventory);
    found = 0;


//block to search through inventory with user inputted item
    while( (fgets(available, 128, inventory) != NULL) && !found)      //IF found, ends because of !=NULL    &&    IF NOT found, ends because of !found 
    {
        printf("available is: %s", available);
        found = 0;
        available[strlen(available) - 1] = '\0';
        found = (strncmp(item, available, strlen(item)) == 0 ); 
        if (found)
        {
        //receive quantity
            printf("Please enter quantity: ");
            scanf("%s", s_quantity);
            getchar();
        //convert the quantity of the item to a string 
            quantity = strtod(s_quantity, &ptr);
            if(quantity == 0)
            {
                printf("Invalid quantity value. Item will not be added to the shopping cart\n");
                return 1;
            }
        //storing quantity+item into array
            while(s_quantity[char_count] != '\0')
            {
                temp[temp_count] = s_quantity[char_count];
                //printf("1temp is: %s||j is: %d||i is: %d\n",temp, j, i);
                char_count++;
                temp_count++;
            }
            char_count = 0;

            while(space_x_space[char_count] != '\0')
            {
                temp[temp_count] = space_x_space[char_count];
                //printf("2temp is: %s||j is: %d||i is: %d\n",temp, j, i);
                char_count++;
                temp_count++;
            }
            char_count = 0;
            //printf("temp is: %s\n",temp);
            while(available[char_count] != '\0')
            {
                temp[temp_count] = available[char_count];
                //printf("3temp is: %s||j is: %d||i is: %d\n",temp, j, i);
                char_count++;
                temp_count++;
            }


            printf("global count is: %d\n", global_count);
            shopping_cart[global_count] = (char*)malloc(strlen(temp) *sizeof(char) );
            strcpy(shopping_cart[global_count], temp);

            // printf(" 0: %s\n", shopping_cart[0]); 
            // printf(" %d: %s\n",global_count, shopping_cart[global_count]); 
        
            total_quantities[global_count] = quantity;

            printf("Item was added to shopping cart\n\n");

        }   //end of if statement
    }   //end of while loop

//block to show item not in inventory
    if (!found)
    {
        printf("Sorry. That item is out of stock. \n\n\n");
    }
    return 0;
}