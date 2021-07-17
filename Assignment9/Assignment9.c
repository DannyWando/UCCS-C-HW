/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 9
 Due Nov 9th, 2017
*/
/*
 Open input file 1
 Put input file 1's data into an array
 Close file 1
 
 Open input file 2
 Get the data from file 2
     Compare data from file 2 against data array
     If data from file 2 matches a piece of data in the array
         Check to see if that piece of data already exists
             If not, add it to array2
 Close file 2
 
 Open input file 3
 Get the data from file 3
     Compare data from file 3 against data array2
     If data from file 3 matches a piece of data in the array2
         Check to see if that piece of data already exists
         If not, add it to array3
 Close file 3
 
 Write the contents of data array3 to a new file called RepeatCustomers.txt
 Print the contents of data array3
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void writingToNewFile(int* const customers, int count);
void printArrayContents(int* const customers, int count);

int main(void)
{
    const char *locations[] = {"/Users/dannywandeler/Desktop/CS2060/Assignment9/Nov22.txt", "/Users/dannywandeler/Desktop/CS2060/Assignment9/Nov23.txt", "/Users/dannywandeler/Desktop/CS2060/Assignment9/Nov24.txt"};
    FILE *filePtr[3];
    int output[300]; int output2[300]; int output3[300];
    int counter=0; int counter2=0; int counter3=0;
    for (int i=0; i < 3; i++)
    {
        if ((filePtr[i] = fopen(locations[i], "r")) != NULL)
        {
            char input[25];
            while (fgets(input, 27, filePtr[i]) != NULL) //Problems with MAX_LINE so I used 27
            {
                int tmp = atoi(input);
                if (i==0)
                {
                    output[counter] = tmp;
                    counter++;
                }
                else if (i==1)
                {
                    for (int k=0; k < counter; k++)
                    {
                        if (tmp == output[k])
                        {
                            bool check = true;
                            for (int a=0; a < counter2; a++)
                            {
                                if (tmp == output2[a])
                                {
                                    check = false;
                                }
                            }
                            if (check)
                            {
                                output2[counter2] = tmp;
                                counter2++;
                            }
                        }
                    }
                }
                else if (i==2)
                {
                    for (int j=0; j < counter2; j++)
                    {
                        if (tmp == output2[j])
                        {
                            bool check2 = true;
                            for (int b=0; b < counter3; b++)
                            {
                                if (tmp == output3[b])
                                {
                                    check2 = false;
                                }
                            }
                            if (check2)
                            {
                                output3[counter3] = tmp;
                                counter3++;
                            }
                        }
                    }
                }
            }
            fclose(filePtr[i]);
        }
        else
        {
            puts("File could not be opened");
        }
    }
    writingToNewFile(output3, counter3);
    printArrayContents(output3, counter3);
}

void writingToNewFile(int* const customers, int count)
{
    FILE *newFilePtr;
    char path[] = "/Users/dannywandeler/Desktop/CS2060/Assignment9/RepeatCustomers.txt";
    newFilePtr = fopen(path, "w");
    for (int i=0; i < count; i++)
    {
        fprintf(newFilePtr, "%d\n", customers[i]);
    }
    fclose(newFilePtr);
}

void printArrayContents(int* const customers, int count)
{
    puts("RepeatCustomers.txt Contents");
    puts("-----------------------------");
    for (int i=0; i < count; i++)
    {
        printf("%d\n", customers[i]);
    }
}
