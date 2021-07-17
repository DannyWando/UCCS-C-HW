/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 3
 Due Sep 14th, 2017
*/
/*
 While the user does not choose exit
    Print menu
        Take user input from UI
    If user chooses encrypt
        Encrpyt number
        Print new encrypted number
    If user chooses decrypt
        Decrypt number
        Print new decrypted number
    If user chooses exit
        Break and exit program
*/

#include <stdio.h>
#include <stdbool.h>

//global variables //Don't necessarily need to be global but had problems when they weren't
int thousands = 0; int hundreds = 0; int tens = 0; int ones = 0;

int printMenu()
//This function prints the UI and takes user input to navigate to a different function
{
    int option;
    puts("\nCS 2060 Top Secret Decoding Program \n-------------------------------------\n1) Encryption \n2) Decryption \n3) Exit \n");
    printf("Would you like to encrypt, decrypt, or exit? Select option 1, 2, or 3: ");
    scanf(" %d", &option);
    return option;
}

void encryptInteger()
/* This function takes a 4 digit integer from user input and encrypts it. If the user inputs a number less than zero
   or a 5 or greater digit integer, it reprompts them for a valid input. If the integer is greater than or equal to
   zero and is only 1, 2, or 3 digits, the program treats the integer as though it began with the corresponding amount of zeroes. */
{
    int inputToEncrypt = 0; int tempE = 0;
    thousands=0; hundreds=0; tens=0; ones=0;
    inputToEncrypt=0; tempE=0;
    printf("Enter value to encrypt: ");
    scanf(" %d", &inputToEncrypt);
    //Checks input for validity
    while (inputToEncrypt < 0 || inputToEncrypt >=  10000)
    {
        printf("Enter a valid 4-digit integer to encrypt: ");
        scanf(" %d", &inputToEncrypt);
    }
    
    //assigned each place to its own variable
    thousands = inputToEncrypt/1000;
    hundreds = (inputToEncrypt-(thousands*1000))/100;
    tens = (inputToEncrypt-(thousands*1000)-(hundreds*100))/10;
    ones = inputToEncrypt-(thousands*1000)-(hundreds*100)-(tens*10);
    
    /* debugger */ //printf("Value encrypted is %d%d%d%d \n", thousands, hundreds, tens, ones);
    
    //step 1 of encryption
    thousands = (thousands+7)%10;
    hundreds = (hundreds+7)%10;
    tens = (tens+7)%10;
    ones = (ones+7)%10;
    
    //step 2 of encryption
    tempE = thousands;
    thousands = tens;
    tens = tempE;
    tempE = hundreds;
    hundreds = ones;
    ones = tempE;
    
    printf("The encrypted value is: %d%d%d%d \n", thousands, hundreds, tens, ones);
}

void decryptInteger()
/* This function takes a 4 digit integer from user input and decrypts it. If the user inputs a number less than zero
 or a 5 or greater digit integer, it reprompts them for a valid input. If the integer is greater than or equal to
 zero and is only 1, 2, or 3 digits, the program treats the integer as though it began with the corresponding amount of zeroes. */
{
    int inputToDecrypt = 0; int tempD = 0;
    thousands=0; hundreds=0; tens=0; ones=0;
    inputToDecrypt=0; tempD=0;
    printf("Enter value to decrypt: ");
    scanf(" %d", &inputToDecrypt);
    //Checks input for validity
    while (inputToDecrypt < 0 || inputToDecrypt >=  10000)
    {
        printf("Enter a valid 4-digit integer to decrypt: ");
        scanf("  %d", &inputToDecrypt);
    }
    
    //assigned each place to its own variable
    thousands = inputToDecrypt/1000;
    hundreds = (inputToDecrypt-(thousands*1000))/100;
    tens = (inputToDecrypt-(thousands*1000)-(hundreds*100))/10;
    ones = inputToDecrypt-(thousands*1000)-(hundreds*100)-(tens*10);
    
    /* debugger */ //printf("Value decrypted is %d%d%d%d \n", thousands, hundreds, tens, ones);
    
    //step 1 of decryption
    tempD = thousands;
    thousands = tens;
    tens = tempD;
    tempD = hundreds;
    hundreds = ones;
    ones = tempD;
    
    //step 2 of decryption
    thousands = (thousands+3)%10;
    hundreds = (hundreds+3)%10;
    tens = (tens+3)%10;
    ones = (ones+3)%10;
    
    printf("The decrypted value is: %d%d%d%d \n", thousands, hundreds, tens, ones);
}

int main(void)
//Runs the Assignment prompt. Prints the UI and asks the user for encryption, decryption, or exit.
{
    int tmp=0;
    bool exit = false;
    while (!exit)
    {
        tmp = printMenu();
        if (tmp != 1 && tmp != 2 && tmp != 3)
        {
            printf("\nInvalid menu selection - please enter 1, 2, or 3\n");
        }
        else if (tmp == 1)
        {
            encryptInteger();
        }
        else if (tmp == 2)
        {
            decryptInteger();
        }
        else if (tmp == 3)
        {
            puts("Good Bye");
            exit = true;
        }
    }
}
