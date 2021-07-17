/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 11
 Due Dec 5th, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Start creating of structs
struct Racer
{
    char name[20];
    int results[3];
    int overall;
};

struct Race
{
    char raceName[40];
    int numRacers;
    struct Racer partcipating[4];
};

struct RacerNode
{
    char name[20];
    int results[3];
    int overall;
    struct RacerNode* nextRacer;
};
//End of creating structs

//Prototypes
int findOVR(int input[]);
void printRace(struct Race input[]);
void findBest(struct Race input[]);
void findWorst(struct Race input[]);
struct RacerNode* addNode(struct RacerNode* input, struct RacerNode *head);
void printLinkedList(struct RacerNode *head);

//Main function
int main(void)
{
    // 4a) Create 4 racers
    struct Racer racer1 = {"Sue", {25, 7, 4}};
    struct Racer racer2 = {"Stacy", {81, 3, 9}};
    struct Racer racer3 = {"Betty", {71, 82, 45}};
    struct Racer racer4 = {"Joe", {29, 4, 2}};
    
    // 4b) Create 3 races
    struct Race PP = {"Pikes Peak Ascent", 4, {racer1, racer2, racer3, racer4}};
    struct Race GOG = {"Garden of the Gods 10-Mile", 4, {racer1, racer2, racer3, racer4}};
    struct Race BB = {"Boulder Boulder", 4, {racer1, racer2, racer3, racer4}};
    
    // 4c) Create an array of 3 races
    struct Race races[3] = {PP, GOG, BB};
    
    // 4d) Compute the overall value for each racer
    racer1.overall = findOVR(racer1.results);
    racer2.overall = findOVR(racer2.results);
    racer3.overall = findOVR(racer3.results);
    racer4.overall = findOVR(racer4.results);
    
    // 4e) Print the race array
    printRace(races);
    
    // 4f) Find which friend had the best finish at PP Ascent
    int best=1000;
    int temp=0;
    for (int i=0; i < 4; i++)
    {
        if (PP.partcipating[i].results[0] < best)
        {
            best = PP.partcipating[i].results[0];
            temp=i;
        }
    }
    printf("Best finisher at %s => %s finishing %d\n", PP.raceName, PP.partcipating[temp].name, best);
    
    // 4g) Find which friend had the worst finish at PP Ascent
    int worst=0;
    for (int i=0; i < 4; i++)
    {
        if (PP.partcipating[i].results[0] > worst)
        {
            worst = PP.partcipating[i].results[0];
            temp=i;
        }
    }
    printf("Worse finisher at %s => %s finishing %d\n\n", PP.raceName, PP.partcipating[temp].name, worst);
    
    // 4h) Find which friend had the best finish out of the 3 races
    findBest(races);
    
    // 4i) Find which friend had the worst finish out of the 3 races
    findWorst(races);
    
    //Creating the RacerNodes for each corresponding racer
    struct RacerNode Racer1 = { "Sue", {25, 7, 4}, racer1.overall, NULL };
    struct RacerNode Racer2 = { "Stacy", {81, 3, 9}, racer2.overall, NULL };
    struct RacerNode Racer3 = { "Betty", {71, 82, 45}, racer3.overall, NULL };
    struct RacerNode Racer4 = { "Joe", {29, 4, 2}, racer4.overall, NULL };
    
    // 4j) Add a node to the linked list, using overall as the sorting criteria from lowest to highest
    struct RacerNode* head = NULL;
    head = addNode(&Racer1, head);
    head = addNode(&Racer2, head);
    head = addNode(&Racer3, head);
    head = addNode(&Racer4, head);
    
    // 4k) Print the linked list
    printLinkedList(head);
}

//Finds and returns the overall, which is the sum of results from all races
int findOVR(int input[])
{
    int total=0;
    for (int i=0; i < 3; i++)
    {
        total = total + input[i];
    }
    return total;
}

//Prints the race array and the results for each racer for that race
void printRace(struct Race input[])
{
    for (int i=0; i < 3; i++)
    {
        printf("%s\n", input[i].raceName);
        puts("Racer  Finish\n----------------------");
        for (int k=0; k < input[i].numRacers; k++)
        {
            printf("%s    %d\n", input[i].partcipating[k].name, input[i].partcipating[k].results[i]);
        }
        puts("");
    }
}

// Finds the best finishing results from any of the 3 races and prints the race, runner, and finishing result
void findBest(struct Race input[])
{
    int max=1000; int temp=0; int temp2=0;
    for (int i=0; i < 3; i++)
    {
        for (int k=0; k < input[i].numRacers; k++)
        {
            if (input[i].partcipating[k].results[i] < max)
            {
                max = input[i].partcipating[k].results[i];
                temp=i;
                temp2=k;
            }
        }
    }
    printf("Best finish for the races occurred at %s => %s finishing %d\n", input[temp].raceName, input[temp].partcipating[temp2].name, max);
}

// Finds the worst finishing results from any of the 3 races and prints the race, runner, and finishing result
void findWorst(struct Race input[])
{
    int min=0; int temp=0; int temp2=0;
    for (int i=0; i < 3; i++)
    {
        for (int k=0; k < input[i].numRacers; k++)
        {
            if (input[i].partcipating[k].results[i] > min)
            {
                min = input[i].partcipating[k].results[i];
                temp=i;
                temp2=k;
            }
        }
    }
    printf("Worst finish for the races occurred at %s => %s finishing %d\n\n", input[temp].raceName, input[temp].partcipating[temp2].name, min);
}

//Adds a node to the linked list and returns the head pointer
struct RacerNode* addNode(struct RacerNode* input, struct RacerNode* head)
{
    struct RacerNode* current = NULL;
    struct RacerNode* previous = NULL;
    int added = 0;
    if (head == NULL) //If linked list is empty
    {
        head = input;
    }
    else //If linked list is not empty
    {
        current = head; //New pointer to head to transverse linked list without changing head
        while (current != NULL)
        {
            if (added == 0) //If a node has not been added yet
            {
                if (input->overall < current->overall)
                {
                    input->nextRacer = current;
                    if (previous == NULL) //If the input node should go before the node head points to
                    {
                        head = input;
                        added++;
                    }
                    else //If the input node goes after head but not at the tail (in between)
                    {
                        previous->nextRacer = input;
                        added++;
                    }
                }
            }
            previous = current; //Cycle through linked list to next node
            current = current->nextRacer;
        }
        if (added == 0) //If the input node goes at the tail
        {
            previous->nextRacer = input;
        }
    }
    return head;
}

//Prints a linked list, starting from the head pointer
void printLinkedList(struct RacerNode *head)
{
    puts("The list in order of highest to lowest overall");
    while (head != NULL)
    {
        printf("%s {%d %d %d} --> ", head->name, head->results[0], head->results[1], head->results[2]);
        head = head->nextRacer;
    }
    puts("NULL");
}
