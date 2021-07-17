/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 5
 Due Oct 5th, 2017
*/
/*
Displays the concert menu
     Can change the groups by changing the global constant arrays in the program
     Gets input for which group to buy tickets for
         Checks for valid input
     Returns that choice
Displays different section choices and corresponding prices
     Gets input for section choice
         Checks for valid input
Asks the user for how many seats they want
     Checks for valid input
Displays order details
     Prints a character for section if they selected a floor section seat
     Calculates the total cost, including tickets and service fee
Prompt the user to confirm the purchase within 30 seconds
     Checks for valid input
     If invalid input, continues prompting
     If 30 seconds passes without a "Y" or "y" input, end the program
     If yes
         Displays the tickets with section, row and seat number
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Global constants
const float SERVICEFEE = 23.50; const float FLOOR = 400.00; const float SEC100 = 325.00;
const float SEC200 = 250.00; const float SEC300 = 100.00;
char GROUP1[] = "Rolling Stones"; char GROUP2[] = "Imagine Dragons"; char GROUP3[] = "U2";
char floorSec[] = {'A', 'B', 'C', 'D', 'E', 'F'};

//Displays the concert menu and prompts customer for desired concert and returns selected concert
int displayConcertMenu()
{
    int groupChoice=0;
    printf("CS 2060 Concert Ticket Vendor");
    printf("\n------------------------------\n1: %s \n2: %s \n", GROUP1, GROUP2);
    printf("3: %s \n------------------------------\nWhich concert would you like to attend? ", GROUP3);
    scanf("%d", &groupChoice);
    while (groupChoice != 1 && groupChoice != 2 && groupChoice != 3)
    {
        printf("%d is not a valid option. Please try again. ", groupChoice);
        scanf("%d", &groupChoice);
    }
    return groupChoice;
}

//Displays the sections and prices associated with those sections
//Prompts customer for desired section for selected concert and returns selected selection
int getSection(int whichConcert)
{
    int sectionInput;
    printf("\n-------------------------------------------\nSection           Price\n-------------------------------------------\n");
    printf("0: Floor A - F           $%.2f\n1: Section 102 - 148     $%.2f\n", FLOOR, SEC100);
    printf("2: Section 202 - 260     $%.2f\n3: Section 302 - 380     $%.2f\n", SEC200, SEC300);
    printf("-------------------------------------------\n");
    if (whichConcert == 1)
    {
        printf("In what section would you like to view %s? ", GROUP1);
    }
    else if (whichConcert == 2)
    {
        printf("In what section would you like to view %s? ", GROUP2);
    }
    else if (whichConcert == 3)
    {
        printf("In what section would you like to view %s? ", GROUP3);
    }
    scanf("%d", &sectionInput);
    while (sectionInput != 0 && sectionInput != 1 && sectionInput != 2 && sectionInput != 3)
    {
        printf("%d is not a valid section. Please try again. ", sectionInput);
        scanf("%d", &sectionInput);
    }
    return sectionInput;
}

// Prompts customer for the number of seats they want for the selected concert.
// The customer can purchase between 1 and 6 seats.
int getNumberOfSeats(int whichConcert)
{
    int seatInput;
    if (whichConcert == 1)
    {
        printf("How many seats for %s? ", GROUP1);
    }
    else if (whichConcert == 2)
    {
        printf("How many seats for %s? ", GROUP2);
    }
    else if (whichConcert == 3)
    {
        printf("How many seats for %s? ", GROUP3);
    }
    scanf("%d", &seatInput);
    while (seatInput != 1 && seatInput != 2 && seatInput != 3 && seatInput != 4 && seatInput != 5 && seatInput != 6)
    {
        printf("%d seats is not valid. Please select between 1 and 6 seats. ", seatInput);
        scanf("%d", &seatInput);
    }
    return seatInput;
}

// Generate a random section number and returns that section number.
int generateRandomSectionNumber(int section)
{
    srand(time(NULL)); //seeds the rand()
    int randomSec=0;
    switch (section) //gets a random number for whatever needed section
    {
        case 0:
            randomSec = (rand() % sizeof(floorSec));
            //another function uses this number to call from the floorSec array to get a character section
            break;
        case 1:
            randomSec = (rand() % 47) + 102; //between 102 and 148
            break;
        case 2:
            randomSec = (rand() % 59) + 202; //between 202 and 260
            break;
        case 3:
            randomSec = (rand() % 79) + 302; // between 302 and 380
            break;
    }
    return randomSec;
}

// Generate a random row number and returns that row.
int generateRandomRowNumber()
{
    srand(time(NULL)); //seeds the rand()
    int row = (rand() % 30) + 1;
    return row;
}

// Generates a random seat number and returns that seat.
int generateRandomSeatNumber()
{
    srand(time(NULL)); //seeds the rand()
    int seat = (rand() % 15) + 1;
    return seat;
}

// Calculate the total cost and display order information.
float ticketCost(int section, int numSeats, int sectionNumber, int row, int seat)
{
    float totalCost = 0.0;
    int seat1=0; int seat2=0; //needed to find the ends of seats requested
    if (numSeats > 1)
    {
        seat2 = seat+numSeats-1;
        seat1 = seat;
    }
    printf("\nQuantity    Section    Row    Seats        Seat Price     Total\n");
    printf("-------------------------------------------------------------------\n");
    switch (section)
    {
        case 0:
            totalCost = numSeats*(FLOOR+SERVICEFEE);
            if (numSeats > 1)
            {
                printf("%d           %c          %d      %d-%d         $%.2f       $%.2f\n", numSeats, floorSec[sectionNumber], row, seat1, seat2, FLOOR, numSeats*FLOOR);
            }
            else
            {
                printf("%d           %c          %d      %d         $%.2f       $%.2f\n", numSeats, floorSec[sectionNumber], row, seat, FLOOR, numSeats*FLOOR);
            }
            break;
        case 1:
            totalCost = numSeats*(SEC100+SERVICEFEE);
            if (numSeats > 1)
            {
               printf("%d           %d          %d      %d-%d         $%.2f       $%.2f\n", numSeats, sectionNumber, row, seat1, seat2, SEC100, numSeats*SEC100);
            }
            else
            {
                printf("%d           %d          %d      %d        $%.2f       $%.2f\n", numSeats, sectionNumber, row, seat, SEC100, numSeats*SEC100);
            }
            break;
        case 2:
            totalCost = numSeats*(SEC200+SERVICEFEE);
            if (numSeats > 1)
            {
                printf("%d           %d          %d      %d-%d         $%.2f       $%.2f\n", numSeats, sectionNumber, row, seat1, seat2, SEC200, numSeats*SEC200);
            }
            else
            {
               printf("%d           %d          %d      %d      $%.2f       $%.2f\n", numSeats, sectionNumber, row, seat, SEC200, numSeats*SEC200);
            }
            break;
        case 3:
            totalCost = numSeats*(SEC300+SERVICEFEE);
            if (numSeats > 1)
            {
                printf("%d           %d            %d       %d-%d          $%.2f          $%.2f\n", numSeats, sectionNumber, row, seat1, seat2, SEC300, numSeats*SEC300);
            }
            else
            {
                printf("%d           %d            %d       %d       $%.2f          $%.2f\n", numSeats, sectionNumber, row, seat, SEC300, numSeats*SEC300);
            }
            break;
    }
    printf("\n                               Service Fee & Taxes(x%d)    $%.2f \n", numSeats, numSeats*SERVICEFEE);
    printf("-------------------------------------------------------------------\n");
    printf("                                                Total:    $%.2f \n", totalCost);
    return totalCost;
}

// Prompts customer to purchase tickets.  Starts a timer.  If customer doesn't purchase
// tickets within 30 seconds, then void the order, otherwise charge credit card.
bool purchaseTickets(float totalCost)
{
    time_t start = time(NULL); //starts timer
    char ynInput;
    printf("You have 30 seconds to decide if you want to purchase these tickets (Y/N)? ");
    scanf(" %c", &ynInput);
    while (1) //continues running until the break is reached
    {
        while (ynInput != 'y' && ynInput != 'Y' && ynInput != 'n' && ynInput != 'N')
        {
            printf("%c is not valid. Please enter Y or N: ", ynInput);
            scanf(" %c", &ynInput);
            if (time(NULL) > start + 30)
            {
                puts("Sorry, this order expired, please try again");
                return false;
            }
        }
        break;
    }
    if (ynInput == 'Y' || ynInput == 'y')
    {
        printf("Thank you for your purchase. Your credit card will be charged $%.2f", totalCost);
        return true;
    }
    else
    {
        return false;
    }
}

// Print tickets for each seat purchased
void printTickets(int whichConcert, int section, int numberSeats, int sectionNumber, int row, int seat)
{
    int seat1=0;
    if (seat+(numberSeats-1) > 15)
    {
        seat1 = 16 - numberSeats;
    }
    else
    {
        seat1 = seat;
    }
    for (int i=1; i<=numberSeats; i++)
    {
        switch (whichConcert)
        {
            case 1:
                printf("\n\n%s\n", GROUP1);
                break;
            case 2:
                printf("\n\n%s\n", GROUP2);
                break;
            case 3:
                printf("\n\n%s\n", GROUP3);
                break;
        }
        printf("-------------------------\nSection |  Row  |  Seat | \n-------------------------\n");
        if (section == 0)
        {
            printf("%c          %d       %d\n", floorSec[sectionNumber], row, seat1+i-1);
        }
        else
        {
            printf("%d          %d       %d\n", sectionNumber, row, seat1+i-1);
        }
        printf("-------------------------\n");
    }
}

//Main funciton
int main(void)
{
    int concertChoice = displayConcertMenu();
    int sectionChoice = getSection(concertChoice);
    int numSeats = getNumberOfSeats(concertChoice);
    int sectionNum = generateRandomSectionNumber(sectionChoice);
    int row = generateRandomRowNumber();
    int seat = generateRandomSeatNumber();
    int totalCost = ticketCost(sectionChoice, numSeats, sectionNum, row, seat);
    if (!purchaseTickets(totalCost))
    {
        return 0;
    }
    else
    {
        printTickets(concertChoice, sectionChoice, numSeats, sectionNum, row, seat);
    }
}
