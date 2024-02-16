// File Name: PositionList.h
#ifndef LIGHTING_FIXTURE_LIST_H
#define LIGHTING_FIXTURE_LIST_H


#include <iostream>
#include <string>
#include <ostream>
#include "LightingFixture.h"


// Defines class LightingFixtureList 

//**********************************************************************
// LightingFixtureList
// Defines linked list class.
//**********************************************************************

class LightingFixtureList {
private:
    class Node {
    public:
        LightingFixture fixture;
        Node* next;

        // Constructor
        Node(const LightingFixture& fixture) : fixture(fixture), next(nullptr) {} // Define the constructor
    };
    
    Node* top;
    int count; //Member variable to store the count of lighting fixtures.
public:
      
    LightingFixtureList(); 
    ~LightingFixtureList();
    
    void display();
    void addToTop(LightingFixture fixture);
    // void addtoBottom(LightingFixture fixture);
    int fixtureCount() const;
    bool moveToTop(int fixtureID);
    void updateFixtureSpecs(int fixtureID);
    signed int removeFixtureByID(int fixtureID);   

};


#endif LIGHTING_FIXTURE_LIST_H