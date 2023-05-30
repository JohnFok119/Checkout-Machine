#=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**
#/bin/bash
#
#Author: Johnny Fok
#Course Info: CPSC 223C, Spring 2023
#Assignmnet 5
#Email: johnnyfok@fullerton.edu
#
# 
# NOTE: tokenizing part is unfortunately NOT working -> total is not displayed
#       Searching through C Programming... in inventory.txt also unfortunately does NOT work ->attempting to purchase line 9 in inventory.txt causes error
#=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2=========3**

EXECUTABLE=shopping_cart.out

#delete un-needed files
rm *.out
rm *.o
rm *ffmarket.txt

echo "Compile main.c"
gcc -c -Wall -m64 -no-pie -o main.o main.c -std=gnu17

echo "Compile purchase_item.c"
gcc -c -Wall -m64 -no-pie -o purchase_item.o purchase_item.c -std=gnu17

echo "Compile show_inventory.c"
gcc -c -Wall -m64 -no-pie -o show_inventory.o show_inventory.c -std=gnu17

echo "Compile show_menu.c"
gcc -c -Wall -m64 -no-pie -o show_menu.o show_menu.c -std=gnu17

echo "Compile view_cart.c"
gcc -c -Wall -m64 -no-pie -o view_cart.o view_cart.c -std=gnu17

echo "Compile remove_item.c"
gcc -c -Wall -m64 -no-pie -o remove_item.o remove_item.c -std=gnu17

echo "Link object files"
gcc -m64 -no-pie -o $EXECUTABLE main.o purchase_item.o show_inventory.o show_menu.o view_cart.o remove_item.o -std=gnu17
 
#to give the executable permission
chmod u+x $EXECUTABLE

echo "Running the program"
./$EXECUTABLE

# echo "Running the program (convenience)"
# ./$EXECUTABLE < user_input.in

#delete un-needed files
rm *.out
rm *.o

echo "The script file will terminate"
