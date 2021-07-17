/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 4
 Due Sep 28th, 2017
*/
/*
 Print the setup menu
 Once setup, run the infinte customer loop
    Ask for a discount card
        Check for valid input
            Apply discount with entered "y" or "Y"
        If user enters "Q", prompt for the shutdown pin
            Print shutdown report if the pin matches
    Ask for car wash
        Check for valid input
        Ask the user to choose between option 1 and 2
            Check for valid input
        If they said yes, apply the car wash fee
    Fake credit card authorization
    Prompt the user for fuel choice
        Check for valid input
    Print the fueling display
    Ask if the customer wants a receipt
        Check for valid input
        If yes, print the receipt
    Continue looping infinitely until it shuts down
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//global variables
const int P17PIN=2445;
int inputPIN=0; int totalGallons=0; int numInput=0; int zipCode=0; int gallons=0;
float regular=0; float diesel=0; float discount=0; float totalSales=0; float fuelPrice=0; float fuelTotal=0;
float costCarWash=0; float saleTotal=0;
char ynInput='a';
bool shutDown=false;

//Processes the discount card prompt part of the customer interface. Also processes the secret shutdown section
int discountCard()
{
    printf("Do you have a discount card? (Y/N) ");
    scanf(" %c", &ynInput);
    //Check for valid input
    while (ynInput != 'y' && ynInput != 'Y' && ynInput != 'n' && ynInput != 'N' && ynInput != 'q' && ynInput != 'Q')
    {
        printf("Invalid input... Do you have a discount card? (Y/N) ");
        scanf(" %c", &ynInput);
    }
    //If yes, applies the discount
    if (ynInput == 'y' || ynInput == 'Y')
    {
        printf("Scanning your discount card...\n$0.03/Gallon Discount \n");
        discount = 0.03;
    }
    //Processes the backdoor. Made the correct PIN a constant programmer can set it to whatever they want
    else if (ynInput == 'q' || ynInput == 'Q')
    {
        printf("To shut down pump 17 and get a report, enter the pin: ");
        scanf("%d", &inputPIN);
        while (inputPIN != P17PIN)
        {
            printf("Invalid pin number, enter the pin: ");
            scanf("%d", &inputPIN);
        }
        printf("Shutting down... \nPump 17 has been successfully shut down\n");
        //Prints the pump's report
        printf("Total Gallons     = %d \n", totalGallons);
        printf("Total Fuel Sales  = $%.2f \n", totalSales);
        shutDown = true;
        return 0;
    }
    ynInput = 'a'; //reusing variable other places so if the value doesn't change, it is an invalid input
    return 1;
}

//Processes the car wash portion of the customer interface.
void carWash()
{
    printf("Car wash? (Y/N) ");
    scanf(" %c", &ynInput);
    //Checks for a valid input
    while (ynInput != 'Y' && ynInput != 'y' && ynInput != 'N' && ynInput != 'n')
    {
        printf("Invalid input, car wash? (Y/N) ");
        scanf(" %c", &ynInput);
    }
    //If yes, prompts for which car wash and also checks for the second valid input
    if (ynInput == 'Y' || ynInput == 'y')
    {
        printf("1) Basic Wash    $2.00 \n2) Premium Wash  $5.00 \n");
        printf("Enter car wash type: ");
        scanf("%d", &numInput);
        while (numInput != 1 && numInput != 2)
        {
            printf("Invalid input... Enter car wash type: ");
            scanf("%d", &numInput);
        }
        if (numInput == 1)
        {
            costCarWash = 2.00;
        }
        else if (numInput == 2)
        {
            costCarWash = 5.00;
        }
    }
    ynInput = 'a'; //reusing variable other places so if the value doesn't change, it is an invalid input
}

//Processes the fueling output portion of the customer interface
void fueling(int numGallons, int fuelType)
{
    //Figure out the correct price/gallon by determining fuel type and its corresponding price
    if (fuelType == 1)
    {
        fuelPrice = regular;
    }
    else if (fuelType == 2)
    {
        fuelPrice = diesel;
    }
    fuelPrice = fuelPrice - discount;
    fuelTotal=0;
    //Prints fueling display
    printf("************* Fueling *************\n");
    for (int i=1; i<=numGallons; i++)
    {
        fuelTotal = fuelTotal + fuelPrice;
        printf("  ** $%.2f          %d Gallons ** \n", fuelTotal, i);
    }
    printf("***********************************\n\n");
}

//Processes and prints the receipt
void receipt()
{
    printf("\n********** Receipt **********\n");
    printf("Gallons:         %d \n", gallons);
    printf("Price/gallon:    $%.2f \n", fuelPrice);
    printf("Fuel cost:       $%.2f \n", fuelTotal);
    //If car wash was purchased
    if (costCarWash != 0)
    {
        printf("Car wash:        $%.2f \n", costCarWash);
    }
    printf("-------------------------\n");
    saleTotal = fuelTotal + costCarWash;
    printf("Total:           $%.2f \n", saleTotal);
    printf("*****************************\n");
}

//Prints the pump setup menu and processes the prices for each fuel type
void printSetup()
{
    //Price input
    printf("**********************************\n");
    printf("    Gas Station Pump 17 Setup\n");
    printf("**********************************\n");
    printf("Enter price of regular fuel: ");
    scanf("%f", &regular);
    printf("Enter price of diesel fuel: ");
    scanf("%f", &diesel);
    printf("Are these the correct prices? (Y/N) ");
    scanf(" %c", &ynInput);
    //Checks for a valid input
    while (ynInput != 'y' && ynInput != 'Y' && ynInput != 'n' && ynInput != 'N')
    {
        printf("Invalid input... Are these the correct prices? (Y/N) ");
        scanf(" %c", &ynInput);
    }
    //If no, assuming a mistake and restarts the menu by calling the function recursively
    if (ynInput == 'N' || ynInput == 'n')
    {
        printf("Please input the correct prices. Restarting setup mode...\n\n");
        printSetup();
    }
    ynInput = 'a'; //reusing variable other places so if the value doesn't change, it is an invalid input
}

//Prints and processes the entire customer interface
//This funciton includes the all the others above it excluding printSetup()
int printCustomer()
{
    printf("\n*************************************\n");
    printf("     Welcome to Gas Station 2060\n");
    printf("*************************************\n");
    if (discountCard() == 0)
    {
        return 0;
        //If owner wants to shut down the pump before the first customer, makes sure that it properly
        //exits the printCusomter() funciton and quits program. Compensates for do-while loop in main()
    }
    else
    {
        carWash();
        //Fake credit card processing
        printf("\nInsert credit card\nEnter zip code: ");
        scanf("%d", &zipCode);
        printf("Please Wait... Authorizing...\n\n");
        printf("Lift nozzle and select fuel grade - Regular (1) or Diesel (2): ");
        scanf("%d", &numInput);
        //Checks for valid fuel selection
        while (numInput != 1 && numInput != 2)
        {
            printf("Invalid input... Lift nozzle and select fuel grade - Regular (1) or Diesel (2):  ");
            scanf("%d", &numInput);
        }
        //Regular
        if (numInput == 1)
        {
            gallons = rand() % 30;
            gallons++;
            fueling(gallons, numInput);
        }
        //Diesel
        else if (numInput == 2)
        {
            gallons = rand() % 30;
            gallons++;
            fueling(gallons, numInput);
        }
        printf("Receipt? (Y/N) ");
        scanf(" %c", &ynInput);
        //Checks for valid input
        while (ynInput != 'y' && ynInput != 'Y' && ynInput != 'N' && ynInput != 'n')
        {
            printf("Invalid input... Receipt? (Y/N) ");
            scanf(" %c", &ynInput);
        }
        if (ynInput == 'y' || ynInput == 'Y')
        {
            receipt();
        }
        printf("\nThank you for your business!\n");
        totalSales = totalSales + fuelTotal;
        totalGallons = totalGallons + gallons;
    }
    return 1;
}

//CS2060 Fuel Pump Interface and Interaction
int main(void)
{
    printSetup();
    do
    {
        printCustomer();
        //reset the variables for each time going through the infinite loop
        gallons=0; numInput=0; discount=0; costCarWash=0; saleTotal=0;
    }
    while (!shutDown);
}
