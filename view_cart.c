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

void view_cart(char *shopping_cart[], int global_count)
{
    printf("\n");
    //printf("global count is: %d\n", global_count);
    //printf("%s\n", shopping_cart[0]);

    for (int i = 0; i < global_count; i++)
    {
        //printf("i = %d\n\n", i);
        if (i == 0)
        {
            printf("%s\n", shopping_cart[0]);
        } else
        {
            printf("%s\n", shopping_cart[i]);
        }

    }
    printf("We are done viewing cart.\n");


}