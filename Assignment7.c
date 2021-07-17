/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 7
 Due Oct 26th, 2017
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Declaration of variables
    int intValue; double doubleValue; char charValue; int intArray[5];
    //Assigning values to variables
    intValue = 1234; doubleValue = 367.70; charValue = 'A';
    for (int i=0; i<5; i++)
    {
        intArray[i] = 1+(2*i);
    }
    //Declaration of pointers
    int* intValuePtr = &intValue;
    double* doubleValuePtr = &doubleValue;
    char* charValuePtr = &charValue;
    int *intArrayPtr;
    intArrayPtr = intArray;
    //Integer pointer to an integer pointer
    int** pointerToIntValuePtr = &intValuePtr;
    //Printing header for the table
    puts("----------------------------------------------------------------------------\n| Type  | Name               | Address   | Value      | Size | Comment     |\n----------------------------------------------------------------------------");
    //Prints info for the table
    printf("int     intValue             %p    %d         %lu\n", &intValue, intValue, sizeof intValue);
    printf("int*    intValuePtr          %p    %p     %lu      pointer to integer value\n\n", &intValuePtr, intValuePtr, sizeof intValuePtr);
    printf("double  doubleValue          %p    %.2f       %lu\n", &doubleValue, doubleValue, sizeof doubleValue);
    printf("double* doubleValuePtr       %p    %p     %lu      pointer to double value\n\n", &doubleValuePtr, doubleValuePtr, sizeof doubleValuePtr);
    printf("char    charValue            %p    %c            %lu\n", &charValue, charValue, sizeof charValue);
    printf("char*   charValuePtr         %p    %p     %lu      pointer to character value\n\n", &charValuePtr, charValuePtr, sizeof charValuePtr);
    printf("int     intArray             %p    %p     %lu     array name address of 1st element\n", &intArray, intArray, sizeof intArray);
    for (int i=0; i<5; i++)
    {
        printf("int     intArray[%d]          %p    %d            %lu\n", i, &intArray[i], intArray[i], sizeof(int));
    }
    puts("");
    //Don't understand how you get the NULL value and the address of the intArray back to back?
    printf("int*    intArrayPtr          %p    %p     %lu      pointer set to NULL\n", &intArrayPtr, NULL, sizeof intArrayPtr);
    printf("int*    intArrayPtr          %p    %p     %lu      pointer to array\n", &intArrayPtr, intArrayPtr, sizeof intArrayPtr);
    for (int i=0; i<5; i++)
    {
        printf("int*    intArrayPtr          %p    %d            %lu      access intArray[%d] through pointer\n", &*(intArrayPtr+i), *(intArrayPtr+i), sizeof(int), i);
    }
    printf("\nint**   pointerToIntValuePtr %p    %p     %lu      pointer to integer value pointer\n\n", &pointerToIntValuePtr, pointerToIntValuePtr, sizeof pointerToIntValuePtr);
    puts("Accessing value using a pointer then pointer to pointer\n-------------------------------------------------------");
    printf("Accessing intValue though intValuePtr = %d\n", *intValuePtr);
    printf("Accessing intValue through a pointer to intValuePtr - 2 levels of indirection = %d\n", **pointerToIntValuePtr);
}
