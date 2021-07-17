/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 2
 Due Sep 7, 2017
 The program is a pseudo computer science department bookstore. You can only purchase on type of book at a time, 
 and depending on how much you order, your shipping cost will change as well a possible price reduction.
 
 Last edit: 8/31/17 9:32
*/

#include <stdio.h>

int avMath = 325; //global variables
int avEnglish = 475;
int avHistory = 1000;
const float costMath = 37.50;
const float costEnglish = 27.75;
const float costHistory = 42.00;

void printMenu(int avMat, int avEng, int avHis) //prints the initial menu
{
    printf("Welcome to the CS2060 Limited Bulk Bookstore \n \n");
    printf("Option   Book     Cost     Available Copies \n ---------------------------------------- \n");
    printf("1        Math     $37.50   %d \n", avMat);
    printf("2        English  $27.75   %d \n", avEng);
    printf("3        History  $42.00   %d \n", avHis);
}

void CostCalculation(int orderNum, int selection) //takes the number of ordered books and calculates all of the costs for the order
{
    float totalCost = 0.0; float shipping = 0.0; float taxes = 0.0; float savings = 0.0; float amountDue = 0.0; //local variables
    if (selection == 1) //Math book order
    {
        totalCost = costMath*orderNum;
        printf("\n CS2060 Limited Bulk Bookstore Order Details \n");
        printf("   Number books ordered: %d \n", orderNum);
        if (orderNum > avMath)
        {
            printf("   Number books shipped: %d \n", avMath);
            printf("   Number books back ordered: %d \n", orderNum - avMath);
        }
        printf("\n");
        if (orderNum >= 101) //calculates the shipping and savings based on the number of books ordered
        {
            savings = totalCost*0.3;
            shipping = 0.00;
        }
        else if (orderNum >= 51 && orderNum <=100)
        {
            savings = totalCost*0.2;
            shipping = 25.00;
        }
        else if (orderNum >= 21 && orderNum <= 50)
        {
            savings = totalCost*0.1;
            shipping = 50.00;
        }
        else if (orderNum >= 1 && orderNum <= 20)
        {
            savings = 0.00;
            shipping = orderNum*2.99;
        }
        taxes = (totalCost-savings)*.075;
        amountDue = totalCost-savings+shipping+taxes;
        printf("   Total cost     :  $%.2f \n", totalCost);
        printf("   Shipping       :  $%.2f \n", shipping);
        printf("   Taxes          :  $%.2f \n", taxes);
        if (savings > 0)
        {
            printf("   Savings        : -$%.2f \n", savings);
        }
        printf("------------------------------- \n");
        printf("   Amount Due     :  $%.2f \n", amountDue);
        avMath = avMath - orderNum; //added this in case I get to adding that extra part
        if (avMath < 0)
        {
            avMath = 0;
        }
    }
    else if (selection == 2) //English book order
    {
        totalCost = costEnglish*orderNum;
        printf("\n CS2060 Limited Bulk Bookstore Order Details \n");
        printf("   Number books ordered: %d \n", orderNum);
        if (orderNum > avEnglish)
        {
            printf("   Number books shipped: %d \n", avEnglish);
            printf("   Number books back ordered: %d \n", orderNum - avEnglish);
        }
        printf("\n");
        if (orderNum >= 101)
        {
            savings = totalCost*0.3;
            shipping = 0.00;
        }
        else if (orderNum >= 51 && orderNum <=100)
        {
            savings = totalCost*0.2;
            shipping = 25.00;
        }
        else if (orderNum >= 21 && orderNum <= 50)
        {
            savings = totalCost*0.1;
            shipping = 50.00;
        }
        else if (orderNum >= 1 && orderNum <= 20)
        {
            savings = 0.00;
            shipping = orderNum*2.99;
        }
        taxes = (totalCost-savings)*.075;
        amountDue = totalCost-savings+shipping+taxes;
        printf("   Total cost     :  $%.2f \n", totalCost);
        printf("   Shipping       :  $%.2f \n", shipping);
        printf("   Taxes          :  $%.2f \n", taxes);
        if (savings > 0)
        {
            printf("   Savings        : -$%.2f \n", savings);
        }
        printf("------------------------------- \n");
        printf("   Amount Due     :  $%.2f \n", amountDue);
        avEnglish = avEnglish - orderNum;
        if (avEnglish < 0)
        {
            avEnglish = 0;
        }
    }
    else if (selection == 3) //History book order
    {
        totalCost = costHistory*orderNum;
        printf("\n CS2060 Limited Bulk Bookstore Order Details \n");
        printf("   Number books ordered: %d \n", orderNum);
        if (orderNum > avHistory)
        {
            printf("   Number books shipped: %d \n", avHistory);
            printf("   Number books back ordered: %d \n", orderNum - avHistory);
        }
        printf("\n");
        if (orderNum >= 101)
        {
            savings = totalCost*0.3;
            shipping = 0.00;
        }
        else if (orderNum >= 51 && orderNum <=100)
        {
            savings = totalCost*0.2;
            shipping = 25.00;
        }
        else if (orderNum >= 21 && orderNum <= 50)
        {
            savings = totalCost*0.1;
            shipping = 50.00;
        }
        else if (orderNum >= 1 && orderNum <= 20)
        {
            savings = 0.00;
            shipping = orderNum*2.99;
        }
        taxes = (totalCost-savings)*.075;
        amountDue = totalCost-savings+shipping+taxes;
        printf("   Total cost     :  $%.2f \n", totalCost);
        printf("   Shipping       :  $%.2f \n", shipping);
        printf("   Taxes          :  $%.2f \n", taxes);
        if (savings > 0)
        {
            printf("   Savings        : -$%.2f \n", savings);
        }
        printf("------------------------------- \n");
        printf("   Amount Due     :  $%.2f \n", amountDue);
        avHistory = avHistory - orderNum;
        if (avHistory < 0)
        {
            avHistory = 0;
        }
    }
}

int main(void)//pseudo CS2060 bookstore program
{
    int option = 0; int orderedCopies = 0;
    printMenu(avMath, avEnglish, avHistory); //greets the user with the store menu
    printf("\n \nWhat book would you like to purchase? Select option 1, 2, or 3: ");
    scanf("%d", &option);
    if (option!=1 && option!=2 && option!=3) //ends program if the option number is not valid
    {
        printf("Menu selection %d is not a valid menu option.\nRun program to try again - Good bye! \n", option);
        return 0;
    }
    printf("How many copies do you want? ");
    scanf("%d", &orderedCopies);
    if (orderedCopies<=0) //ends the program if the number of copies ordered is zero or less
    {
        printf("Number of copies must be greater than zero.\nRun program to try again - Good bye! \n");
        return 0;
    }
    CostCalculation(orderedCopies, option);
}
