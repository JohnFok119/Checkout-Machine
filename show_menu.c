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

void show_menu()
{
//block to display options & receive user input
    printf("Here is our menu:\n");
    printf("D = Display list of merchandise in current inventory\n");
    printf("P = Purchase an item\n");
    printf("R = Repeat this menu\n");
    printf("V = View shopping cart\n");
    printf("X = Exit, compute amount due, generate receipt\n");
}