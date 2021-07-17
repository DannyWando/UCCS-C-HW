/*
Daniel Wandeler
CS 2060 - 002
Assignment 6
Due Oct 21th, 2017
*/
/*
 Open file and read in data to an array
 Sort the array into smaller arrays by section
 
 Display concert menu
 Prompt the user for their concert choice
     Check for valid input
     Return input once it is valid
 Display section menu
 Prompt the user for their section choice
     Check for valid input
     Return input once it is valid
 Prompt the user for how many seats they would like
     Checks for valid input
     Returns input once it is valid
 Check corresponding section array for number of corresponding adjacent seats
     If yes,
         Displays the purchase menu
         Starts timer
         Prompts user to confirm purchase within 30 seconds
             Checks for valid input
             If yes, returns true
             If no, returns false and exits program
     If no,
         Displays prompt saying that there is no availability for their request
         Repeats displaying the section menu and seat prompt until seats are found
 Asks user if they would like to make another purchase for the same show
     Checks for valid input
     If yes,
         Repeat process starting at the section menu
     If no,
         Displays prompt showing total total sales for that customer
 Exits program
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Global constants
const float SERVICEFEE = 23.50; const float FLOOR = 400.00; const float SEC100 = 325.00;
const float SEC200 = 250.00; const float SEC300 = 100.00;
char GROUP1[] = "Rolling Stones"; char GROUP2[] = "Imagine Dragons"; char GROUP3[] = "U2";
char *GROUPS[] = {"Rolling Stones", "Imagine Dragons", "U2"};
int secFloor[5][10]; int sec100[5][10]; int sec200[5][10]; int sec300[5][10];
//Global variable
int row=0;


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
    printf("0: Floor          $%.2f\n1: Section 102    $%.2f\n", FLOOR, SEC100);
    printf("2: Section 202    $%.2f\n3: Section 302    $%.2f\n", SEC200, SEC300);
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

float ticketCost(int row, int section, int numSeats, int seatNum)
{
    int secNum=0; float totalCost=0;
    printf("\nQuantity    Section    Row    Seats        Seat Price     Total\n");
    printf("-------------------------------------------------------------------\n");
    if (section == 0)
    {
        totalCost = numSeats*(FLOOR+SERVICEFEE);
        if (numSeats > 1)
        {
            printf("%d           Floor       %d       %d-%d         $%.2f       $%.2f\n", numSeats, row, seatNum, (seatNum+numSeats-1), FLOOR, numSeats*FLOOR);
        }
        else
        {
            printf("%d           Floor       %d       %d        $%.2f       $%.2f\n", numSeats, row, seatNum, FLOOR, numSeats*FLOOR);
        }
    }
    else if (section == 1)
    {
        totalCost = numSeats*(SEC100+SERVICEFEE);
        secNum = 102;
        if (numSeats > 1)
        {
            printf("%d           %d          %d      %d-%d         $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, (seatNum+numSeats-1), SEC100, numSeats*SEC100);
        }
        else
        {
            printf("%d           %d          %d      %d        $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, SEC100, numSeats*SEC100);
        }
    }
    else if (section == 2)
    {
        totalCost = numSeats*(SEC200+SERVICEFEE);
        secNum = 202;
        if (numSeats > 1)
        {
            printf("%d           %d          %d      %d-%d         $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, (seatNum+numSeats-1), SEC200, numSeats*SEC200);
        }
        else
        {
            printf("%d           %d          %d      %d         $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, SEC200, numSeats*SEC200);
        }
    }
    else if (section == 3)
    {
        totalCost = numSeats*(SEC300+SERVICEFEE);
        secNum = 302;
        if (numSeats > 1)
        {
            printf("%d           %d          %d      %d-%d         $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, (seatNum+numSeats-1), SEC300, numSeats*SEC300);
        }
        else
        {
            printf("%d           %d          %d      %d        $%.2f       $%.2f\n", numSeats, secNum, row, seatNum, SEC300, numSeats*SEC300);
        }
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
    while (ynInput != 'y' && ynInput != 'Y' && ynInput != 'n' && ynInput != 'N')
    {
        printf("%c is not valid. Please enter Y or N: ", ynInput);
        scanf(" %c", &ynInput);
    }
    if (time(NULL) > start + 30)
    {
        puts("Sorry, this order expired, please try again");
        return false;
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

void nextLine (FILE *filePntr, char line[])
{
    int row=0; int seat=0;
    while (fgets(line, 27, filePntr) != NULL) //MAX_LINE wasn't working correctly for some unknown reason
    {
        if (line[0] == '0')
        {
            row = line[4] - '0';
            for (int i=6; i<=15; i++)
            {
                secFloor[row-1][seat] = line[i] - '0';
                seat++;
            }
        }
        else if (line[0] == '1')
        {
            row = line[4] - '0';
            for (int i=6; i<=15; i++)
            {
                sec100[row-1][seat] = line[i] - '0';
                seat++;
            }
        }
        else if (line[0] == '2')
        {
            row = line[4] - '0';
            for (int i=6; i<=15; i++)
            {
                sec200[row-1][seat] = line[i] - '0';
                seat++;
            }
        }
        else if (line[0] == '3')
        {
            row = line[4] - '0';
            for (int i=6; i<=15; i++)
            {
                sec300[row-1][seat] = line[i] - '0';
                seat++;
            }
        }
        seat=0;
    }
}

int seatAvailable(int section, int seats)
{
    int temp=0;
    switch (section)
    {
        case 0:
            for (int i=0; i<5; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (secFloor[i][j] == 0)
                    {
                        temp=1;
                        int k=j;
                        while (secFloor[i][k+1] == 0 && k<9)
                        {
                            temp++;
                            k++;
                        }
                    }
                    if (temp >= seats)
                    {
                        for (int a=0; a < seats; a++)
                        {
                            secFloor[i][j+a] = 1;
                        }
                        row = i+1;
                        return j+1;
                    }
                }
            }
            break;
        case 1:
            for (int i=0; i<5; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (sec100[i][j] == 0)
                    {
                        temp=1;
                        int k=j;
                        while (sec100[i][k+1] == 0 && k<9)
                        {
                            temp++;
                            k++;
                        }
                    }
                    if (temp >= seats)
                    {
                        for (int a=0; a < seats; a++)
                        {
                            sec100[i][j+a] = 1;
                        }
                        row = i+1;
                        return j+1;
                    }
                }
            }
            break;
        case 2:
            for (int i=0; i<5; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (sec200[i][j] == 0)
                    {
                        temp=1;
                        int k=j;
                        while (sec200[i][k+1] == 0 && k<9)
                        {
                            temp++;
                            k++;
                        }
                    }
                    if (temp >= seats)
                    {
                        for (int a=0; a < seats; a++)
                        {
                            sec200[i][j+a] = 1;
                        }
                        row = i+1;
                        return j+1;
                    }
                }
            }
            break;
        case 3:
            for (int i=0; i<5; i++)
            {
                for (int j=0; j<10; j++)
                {
                    if (sec300[i][j] == 0)
                    {
                        temp=1;
                        int k=j;
                        while (sec300[i][k+1] == 0 && k<9)
                        {
                            temp++;
                            k++;
                        }
                    }
                    if (temp >= seats)
                    {
                        for (int a=0; a < seats; a++)
                        {
                            sec300[i][j+a] = 1;
                        }
                        row = i+1;
                        return j+1;
                    }
                }
            }
            break;
    }
    temp=0;
    return 0;
}

int main(void)
{
    FILE *filePtr;
    char input[100];
    bool check; bool ynInput=false; float finalCost=0.00;
    //if ((filePtr = fopen("/Users/dannywandeler/Desktop/CS2060/concert.txt", "r")) != NULL)
    if ((filePtr = fopen("C:/concert.txt", "r")) != NULL)
    {
        nextLine(filePtr, input);
        int concert = displayConcertMenu();
        do
        {
            int section = getSection(concert);
            int seats = getNumberOfSeats(concert);
            int seatNum = seatAvailable(section, seats);
            //printf("\n%d\n", seatNum);
            if (seatNum == 0)
            {
                check = false;
            }
            else
            {
                check = true;
            }
            while (!check)
            {
                puts("There are no tickets available that meet your request.");
                puts("Please select a different quantity or choose another price range.\n");
                section = getSection(concert);
                seats = getNumberOfSeats(concert);
                seatNum = seatAvailable(section, seats);
                //printf("\n%d\n", seatNum);
                if (seatNum == 0)
                {
                    check = false;
                }
                else
                {
                    check = true;
                }
            }
            float purchaseTotal = ticketCost(row, section, seats, seatNum);
            bool test = purchaseTickets(purchaseTotal);
            if (test)
            {
                char tempInput;
                printf("\nWould you like to purchase more concert tickets? ");
                scanf(" %c", &tempInput);
                while (tempInput != 'y' && tempInput != 'Y' && tempInput != 'n' && tempInput != 'N')
                {
                    printf("%c is not valid. Please enter Y/y or N/n: ", tempInput);
                    scanf(" %c", &tempInput);
                }
                if (tempInput == 'Y' || tempInput == 'y')
                {
                    ynInput = true;
                }
                else
                {
                    ynInput = false;
                }
                finalCost = finalCost + purchaseTotal;
            }
            else
            {
                ynInput = false;
            }
        } while (ynInput);
        if (finalCost > 0.00)
        {
            printf("\nThe total sales for the %s is $%.2f \n", GROUPS[concert-1], finalCost);
        }
        fclose(filePtr);
    }
    else
    {
        puts("File could not be opened");
    }
}
