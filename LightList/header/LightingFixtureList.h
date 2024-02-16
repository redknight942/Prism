// File Name: PositionList.h
// Author: Jesse Walser- Castro
// Date: 02/13/2022
// Assignment Number: 1 
// Data Structures & Algorithms Spring 2024
// Declares class LightingFixtureList, which represents a hanging position to store objects from
// class LightingFixture

#ifndef LIGHTING_FIXTURE_LIST_H
#define LIGHTING_FIXTURE_LIST_H


#include <iostream>
#include <string>
#include <ostream>
#include "LightingFixture.h"


//**********************************************************************
// LightingFixtureList
// Defines linked list class LightingFixtureList.
//**********************************************************************

class LightingFixtureList {
private:
    class Node {
    public:
        LightingFixture fixture;
        Node* next;

        // Constructor initializes node & sets "next" ptr to end of list.
        Node(const LightingFixture& fixture) : fixture(fixture), next(nullptr) {} 
    };
    
    Node* top;
    int count_; //Member variable to store the count of lighting fixtures.

public:
      
    LightingFixtureList(); 
    ~LightingFixtureList();
    int FixtureCount() const;

    void Display();
    void AddToTop(LightingFixture fixture);
    void UpdateFixtureSpecs(int fixtureID_);
    
    bool MoveToTop(int fixtureID_);    
    signed int RemoveFixtureByID(int fixtureID_);   
    // void AddToBottom(LightingFixture fixture);
};


#endif LIGHTING_FIXTURE_LIST_H