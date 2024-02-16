// File Name: LightingFixture.h
// Author: Jesse Walser- Castro
// Date: 02/13/2022
// Assignment Number: 1 
// Data Structures & Algorithms Spring 2024
// Declares class LightingFixture, which represents a lighting fixture
// with user specified attributes.

#pragma once
#ifndef LIGHTING_FIXTURE_H
#define LIGHTING_FIXTURE_H

#include <string>

class LightingFixture {
public:    
    unsigned int fixtureID, barrelSize;
    signed int lateralPosition, verticalPosition;     
    std::string gobo; //Name of "texture" that is cast by lighting fixture
    std::string fixtureType; 

    // Constructor
    LightingFixture(const std::string& fixtureType, unsigned int fixtureID, 
        unsigned int barrelSize, const std::string& gobo, signed int lateralPosition, 
        signed int verticalPosition)
    {
        this->fixtureType = fixtureType;
        this->fixtureID = fixtureID;
        this->barrelSize = barrelSize;      
        this->gobo = gobo;
        this->lateralPosition = lateralPosition;
        this->verticalPosition = verticalPosition;

    }

};

#endif // LIGHTING_FIXTURE_H