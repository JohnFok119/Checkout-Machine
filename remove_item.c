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

void remove_item(FILE *inventory, char *shopping_cart[]);

void remove_item(FILE *inventory, char *shopping_cart[])
{
    char *ptr;
    int found = 0;
    int count = 0;
    char item[128];
    char available[128];

//block to receive user input
    printf("\nPlease enter the item you wish to be removed: ");
    getchar();
    fgets(item, 128, stdin);
    item[strlen(item) - 1] = '\0';
    item[0] = toupper(item[0]);
    printf("the item you want is:%s\n", item);
    rewind(inventory);
    found = 0;

//block to remove item IF found
    while( (fgets(available, 128, inventory) != NULL) && !found)      //IF found, ends because of !=NULL    &&    IF NOT found, ends because of !found 
    {
        found = 0;
        available[strlen(available) - 1] = '\0';
        found = (strncmp(item, available, strlen(item)) == 0 ); 
        if (found)
        {
            // while (shopping_cart[count] != NULL)
            // {
            //     if (strncmp(available, shopping_cart[count], 128) == 0)
            //     {
            //         while(shopping_cart[count++] != NULL)
            //         {
            //             shopping_cart[count] = shopping_cart[count+1]; 
            //             printf("%d: %s\n", count, shopping_cart[count] );
            //         } 
            //     } 
            // }

            printf("%s was removed from your shopping cart.\n", available);
        } //end of (1) if

    } //end of (1) while


//block IF NOT found      
    if (!found)
    {
        printf("That item was not found in your shopping cart. \n\n\n");
    }
    return;
}