/*
 Daniel Wandeler
 CS 2060 - 002
 Assignment 1
 Due Aug 31, 2017
 The program prints out two paragraphs about myself equally spaced. Then, it will solve a system of equations using Cramer's rule.
 
 Pseudocode:
    Print paragraphs about myself and my hobbies
    Initialize variables
    X = (ed-bf)/(ad-bc)
    Y = (af-ec)/(ad-bc)
    Print the values of X and Y
 
 Last edit: 8/30/2017 22:07
*/

#include <stdio.h>

void aboutMe()
{
    printf("    My name is Daniel Wandeler, and the degree I'm working on is the BI in Computer Science. I have some \nexperience with C++ and Python from last year's classes in Boulder. The C programming language is relatively \nnew to me, but I'm excited to learn through it over the semester. I figure it can't be too different from C++, \nso I don't expect to struggle to learn in this class either. My hobbies include basketball, soccer, gaming, \nand hanging out with my friends. I also love movies, and my favorite movies of all-time are the Star Wars \nmovies (except for Episode 1). \n");
    printf("    While I'm taking classes this semester at UCCS, I am also starting my own business. My family owns a bioenergetic \nscanner which we all use to treat our Lyme disease. When we got the scanner, the company that distributes the machines \nin the United States offers an online training program to use the machine commercially. I immediately jumped on this \nopportunity and am now certified to use the machine commercially. I'm going to start as a lab for a few medical \nprofessionals to kickstart business before I try to market myself exclusively. I'm pretty excited for this year and \nwhat it brings me! \n\n");
}

void cramersRule()
{
    double varX, varY, a, b, c, d, e, f; //variable initialization
    a = 3.4; //used the same variable names as on the assignment sheet
    b = 50.2;
    c = 2.1;
    d = .55;
    e = 44.5;
    f = 5.9;
    varX = ((e*d)-(b*f))/((a*d)-(b*c)); // Cramer's Rule
    varY = ((a*f)-(e*c))/((a*d)-(b*c));
    printf("X equals %.2f \n", varX); //set output to two decimal places to keep the output looking clean
    printf("Y equals %.2f \n", varY);
}

int main(void)
{
    aboutMe();
    cramersRule();
    return 0;
}
