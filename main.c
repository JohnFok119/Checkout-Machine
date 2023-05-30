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

void show_menu();
void show_inventory(char * inventory_filename);
int purchase_item( FILE *inventory, char *inventory_filename, char *shopping_cart[], int global_count, int total_quantitiies[]);
void prepare_receipt(FILE *receipt_file, char *receipt_filename, int total_quantities[]);
void view_cart(char *shopping_cart[], int global_count);	
void remove_item(FILE *inventory, char *shopping_cart[]);

int main(int argc, char * argv[])
{
    int count = 0;
    char *shopping_cart[20];
//=========================== Introduction ===================================
    printf("\nWelcome to Fullerton Farmers Market.\n");
    //printf("%s\n", &shopping_cart[0]);

//Variables
    int total_quantities[10];
    char menu_select;
    int global_count = 0;

//Obtain and display the Linux time in the present machine.
    time_t current_linux_time;
    current_linux_time = time(NULL);

    struct tm * broken = localtime(&current_linux_time);
    if(broken == NULL)
    {
        printf("A call to function localtime failed.\n");
    }

//========================= Obtaining inventory name ================================
//block to receive inventory file name
    char inventory_filename[64];
    printf("Please enter the name of the file for analysis: ");
    fgets(inventory_filename, 40, stdin);             //parameters of fgets(array storing stdin, max_size to be read (including null char, stream to read from) )

    int filenameLen = strlen(inventory_filename);
    //printf("filenameLen is: %d\n", filenameLen);
    if (filenameLen == 1)
    {
        filenameLen = 0;

    } else
    {
        inventory_filename[filenameLen-1] = '\0';         //replaces the \n of the string with EOF character
    }


    FILE * inventory = fopen(inventory_filename, "r");      //we obtain the inventory contents here globally
    if (inventory == NULL)
    { 
        printf("Error: unable to open the file. Make sure the name of the file is correct and run the program again.\n");
        printf("Bye\n");
        return 0;
    }        

//=========================== Continuous Operation ===================================
    show_menu();
    printf("\nPlease enter selection: ");
    menu_select = fgetc(stdin);
    if (menu_select == '\n')
    {
        menu_select = fgetc(stdin);
    }
    while(toupper(menu_select) != 'X')
    {
        switch (toupper(menu_select))
        {
            //view inventory
            case 'D':                                       
                show_inventory(inventory_filename);
                break;
            //purchase items
            case 'P':                                       
                if ( (purchase_item(inventory, inventory_filename, shopping_cart, global_count, total_quantities) ) == 1)     
                {
                    break;
                } else
                {
                    global_count++;
                    printf("global count is: %d\n", global_count);
                    break;
                }
            //show menu selection
            case 'R':                                       
                show_menu();
                break;  
            //view shopping cart
            case 'V':                                       
                view_cart(shopping_cart,global_count);
                break; 
            //remove item
            case 'C':  
                remove_item(inventory, shopping_cart);                                    
                break; 
            //invalid input 
            default:
                printf("Error encountered. Try again.\n");
                break;
        }

        if (menu_select != 'R')
        {
            printf("\n");
            show_menu();
            printf("\nPlease enter selection: ");
            menu_select = fgetc(stdin);
            if (menu_select == '\n')
            {
                menu_select = fgetc(stdin);
            }           
        } else
        {
            printf("\nPlease enter selection: ");
            menu_select = fgetc(stdin);
            if (menu_select == '\n')
            {
                menu_select = fgetc(stdin);
            }       
        }

    } //end of if else statement


//finishing
    //prepare_receipt(receipt_file, receipt_filename, total_quantity);



//=========================== Exit ===================================
    printf("\nMain received this number %d and will keep it. A zero will be returned to the operating system.\nBye\n", count);
    return 0;
}

void prepare_receipt(FILE *receipt_file, char *receipt_filename, int total_quantities[])
{
//============================================= LINUX TIME ================================================
//Use the Linux time computed immediately above and convert it to broken time (human manageable time) in current time zone.

//Obtain and display the Linux time in the present machine.
    time_t current_linux_time;
    current_linux_time = time(NULL);
    struct tm * broken = localtime(&current_linux_time);
    if(broken == NULL)
    {
        printf("A call to function localtime failed.\n");
    }

//block of statements to display the month
    char today[10];
    switch (broken->tm_mon)
    {
    case 0: strcpy(today, "January");
        break;
    case 1: strcpy(today, "February");
        break;
    case 2: strcpy(today, "March");
        break;
    case 3: strcpy(today, "April");
        break;
    case 4: strcpy(today, "May");
        break;
    case 5: strcpy(today, "June");
        break;
    case 6: strcpy(today, "July");
        break;
    case 7: strcpy(today, "August");
        break;
    case 8: strcpy(today, "September");
        break;
    case 9: strcpy(today, "October");
        break;
    case 10: strcpy(today, "November");
        break;
    case 11: strcpy(today, "December");
        break;
    default:
        break;
    } //end of switch
//end of block


//========================================================= Begin Exit Procedure ===============================================================
    printf("    Your receipt is being generated.\n");


//=============================== Open receipt file and final checkout file ==================================
    receipt_file = fopen(receipt_filename, "r");
    FILE * checkout_file = fopen("ffmarket.txt", "w");

    if (receipt_file == NULL)
    {
        printf("Error opening receipt file.\n");
        return;
    }
    rewind(receipt_file);

//=============================== Obtain receipt file length ==================================
    long file_len = 0;

    fseek(receipt_file, 0, SEEK_END);                   //set fileptr to end of file
    file_len = ftell(receipt_file);                    //retrieve file size
    fseek(receipt_file, 0, SEEK_SET);                   //set fileptr to beginning


//====================== Write preliminaries into receipt.txt ======================
//printf("We are at preliminaries.\n");
    char receipt_intro1[100] = "Fullerton Farmer's Market";        
    char receipt_intro2[100] = "The customer is always first.\n\n";
    char receipt_intro3[100] = "Today's purchases:\n\n";
    char receipt_intro4[100] = "Quantity        Item        Cost\n";


    fprintf(checkout_file,"%s", receipt_intro1);
    fprintf(checkout_file," %s %02d, %04d\n", today, broken->tm_mday, broken->tm_year+1900);
    fprintf(checkout_file,"%s", receipt_intro2);
    fprintf(checkout_file,"%s", receipt_intro3);
    fprintf(checkout_file,"%s", receipt_intro4);
    //fprintf(checkout_file,"     %s", file_content);

//================== Write onto the file ===================================
    char * filearray = (char*)malloc(file_len*sizeof(char) );
    int k = 0;
    char ch;

    while ( (ch = fgetc(receipt_file)) != EOF)
    {
        fprintf(checkout_file, "%c", ch);
        filearray[k] = ch;
        k++;
    }
//***************************************PROBLEM*********************************************
    *(filearray + strlen(filearray) - 3) = '\0';        //removes last 3 chars from filearray and replaces it with \0  


//================== Tokenize price ===================================
    //printf("We are tokenizing.\n");
    char *ptr;
    double temp_total = 0.0;
    double total = 0.0;
    int count = 0;

    char * token_array[100];
    char * price = (char *)malloc(256 * sizeof(char) );
    char * price_array[100];


    while (strlen(filearray) > 1)
    {
        //printf("string length of the file is: %ld\n", strlen(filearray) );
        token_array[count] = strtok(filearray, "\n");       //this tokenizes one index of the array and stores it into token_array
        printf("%s\n", token_array[count]);

        filearray = filearray + strlen(filearray) + 1;      //moves the pointer of the filearray up
        price = strstr(token_array[count], "$");                //searches the index of the array for $
        printf("p is at: %s\n", price);

        price_array[count] = price+1;                           //setting the price array to the string of price + 1 (to get rid of the dollar sign)
        printf("The price is: %s\n", price_array[count]);

        temp_total = strtod(price_array[count], &ptr);              //add to temp_total & convert the string to a float
        printf("temp_total is: %f\n", temp_total);

        total += total_quantities[count] * temp_total;                //multiply the temp_total of the item by the quantity 
        printf("total is: %f\n", total);

        count++;
    } //end of while loop

    fprintf(checkout_file, "\nAmount paid: $%1.2lf\n\n Thank you for shopping at FFM", total);


//close the files
    fclose(checkout_file);
    fclose(receipt_file);


//goodbye 
    printf("    Please view your receipt in the file: ffmarket.txt\n");
    printf("Thank you for shopping at our store. Bye.\n");

}




