//
//  main.cpp
//  CS3060
//
//  Created by Danny Wandeler on 3/22/18.
//  Copyright © 2018 Danny Wandeler. All rights reserved.
//

#include <iostream>
#include "Primate.hpp"
#include "Gorilla.hpp"
using namespace std;

int main()
{
    Gorilla harambe; //derived class
    
    harambe.print(); // Prints "I am a primate." from base class
    
    return 0;
}
