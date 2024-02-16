// File Name: LightingFixtureList.cpp
//
// Author: Jesse Walser- Castro
// Date: 02/13/2022
// Assignment Number: 1 
// Data Structures & Algorithms Spring 2024
// This is the implementation of class functions from the class LightingFixtureList. 

#include "LightingFixtureList.h"
#include "input_utils.h"
#include <string>
#include <cmath>

//*********************************************************************
// LightingFixtureList()
// Constructor for class LightingFixtureList, which builds the starting node.
// Intializes count (Function not yet implemented)
// Parameters- None.
// Return- No return.
//**********************************************************************
LightingFixtureList::LightingFixtureList() {
    top = nullptr;
    count = 0;
}

//*********************************************************************
// ~LightingFixtureList:
// Destroys the nodes after it passes out of scope
// Parameters- None.
// Return- No return.
//**********************************************************************
LightingFixtureList::~LightingFixtureList() {
   
    Node* current = top;
   
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    top = nullptr;
}

//*********************************************************************
// FixtureCount
// Returns the total number of fixtures currently stored in the linked list.
// Parameters- None.
// Return- integer of count
//**********************************************************************
int LightingFixtureList::fixtureCount() const {
    int sum = 0;
    Node* current = top;
    while (current) {
        current = current->next;
        sum++;        
    }
    
    return sum;
}

//*********************************************************************
// addToTop
// Adds a new fixture to the top of the linked list.
// new_ID: user provided ID to add.
// Return- No return.
//**********************************************************************
void LightingFixtureList::addToTop(LightingFixture fixture)
{
    //Allocation
    Node* temp = new Node(fixture);
    if (top == nullptr) {
        top = temp;
    } else {
        Node* current = top;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }    
}

//*********************************************************************
// display
// Outputs data to screen
// Parameters- None.
// Return- No return.
//**********************************************************************
void LightingFixtureList::display() {
    Node* current = top; 
    
    while (current != nullptr) {        // Display fixture details
        std::cout << "Fixture ID: " << current->fixture.fixtureID << std::endl
            << current->fixture.fixtureType << std::endl
            << "----------------" << std::endl
            << " Barrel Size: " << current->fixture.barrelSize << std::endl            
            << " Gobo: " << current->fixture.gobo << std::endl
            << " X Position: " << current->fixture.lateralPosition << "'" << std::endl
            << " Y Position: " << current->fixture.verticalPosition << "'" << std::endl << std::endl;;
        current = current->next;
    }
}

/*
//*********************************************************************
// addToBottom (NOT YET IMPLEMENTED)
// adds a fixture to the bottom.
// title: user provided fixture to add
// Return- No return.
//**********************************************************************
void LightingFixtureList::add_to_Bottom(LightingFixture fixture) {

    //Allocation
    Node* new_node;
    new_node = new Node;


    new_node->fixture = fixture;
    new_node->next = nullptr;

    if (top == nullptr) {
        top = new_node;
    }
    else {
        Node* p = top;
        while (p->next != nullptr) {
            p = p->next;
        }
        //now p points to last node
        p->next = new_node;
    }
}

*/

//*********************************************************************
// removeFixtureByID
// Removes a node based on FixtureID.
// int fixtureID
// Return- True/ False depending on outcome of the removal function.
//**********************************************************************
signed int LightingFixtureList::removeFixtureByID(int fixtureID) {
    int fixtures_removed = 0; 
    while (fixtureID != -1) {
        if (top == nullptr) {
            std::cout << "List is empty." << std::endl;
            return fixtures_removed; // Exit if list is empty
        }

        if (top->fixture.fixtureID == fixtureID) {
            // If the fixture to be removed is at the top of the list
            Node* temp = top;
            top = top->next;
            delete temp;
            std::cout << "Deleted fixture: " << fixtureID << std::endl;
            fixtures_removed++;
        }
        else {
            Node* prev = nullptr;
            Node* current = top;

            while (current != nullptr && current->fixture.fixtureID != fixtureID) {
                // Traverse the list
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                std::cout << "Fixture not found." << std::endl;
            }
            else {
                prev->next = current->next;
                delete current;
                std::cout << "Deleted fixture: " << fixtureID << std::endl;
                fixtures_removed++;
            }
        }

        std::cout << "Enter fixtureID to delete, or -1 to exit: ";
        fixtureID = getUnsignedIntegerInput("");

    }

    return fixtures_removed;
}


//*********************************************************************
// moveToTop
// moves a node to the top
// title: user provided title to move
// Return- True/ False depending on success of function.
//**********************************************************************
bool LightingFixtureList::moveToTop(int fixtureID) {
    Node* p = top;     //traverse the list
    Node* n = nullptr; //trailing node ptr

    //skips nodes until fixtureID matches or reach the end of the list
    while (p && p->fixture.fixtureID != fixtureID) {
        n = p;           //saves it
        p = p->next;    //advances it
    }

    if (p == nullptr)   //Fixture not found
        return false;
    if (p == top) {
        //do nothing, because it's already at top
        return true;
    }
    else {  //p must be pointing to a non top node
        n->next = p->next;
        p->next = top;
        top = p;
        return true;
    }
}


//*********************************************************************
// updateFixtureSpecs
// Updates a fixture based on a provided ID.
// int fixtureID
// Return- No return.
//**********************************************************************
void LightingFixtureList::updateFixtureSpecs(int fixtureID) {
    unsigned int newFixtureID = std::abs(fixtureID);
    unsigned int newBarrelSize = 0;
    std::string newFixtureType;
    std::string newGobo;
    signed int newLateralPosition, newVerticalPosition = 0;
    
    if (top == nullptr) {
        // Create a new node and set it as the top of the list
        LightingFixture newFixture("Default.", 1, 0, "No gobo.", 0, 0);
        top = new Node(newFixture);        
    }
        
    std::cout << "Enter new fixture Type for fixture with ID " << fixtureID << ": ";
    std::cin.ignore(); // Clear any remaining characters from the input buffer
    std::getline(std::cin, newFixtureType);

    std::cout << "Enter new barrel size for fixture with ID " << fixtureID << ": ";
    newBarrelSize = getUnsignedIntegerInput("");

    std::cout << "Enter new gobo for fixture with ID " << fixtureID << ": ";
    std::cin.ignore(); // Clear any remaining characters from the input buffer
    std::getline(std::cin, newGobo);   

    std::cout << "Enter new LateralPosition for fixture with ID" << fixtureID << ": ";
    newLateralPosition = getSignedIntegerInput("");

    std::cout << "Enter new VerticalPosition for fixture with ID" << fixtureID << ": ";
    newVerticalPosition = getSignedIntegerInput("");
    std::cout << std::endl;
    
    // Check if the list is empty
    //     
    Node* current = top;
    while (current != nullptr) {
        if (current->fixture.fixtureID == fixtureID) {
            current->fixture.fixtureType = newFixtureType;
            current->fixture.barrelSize = newBarrelSize;           
            current->fixture.lateralPosition = newLateralPosition;
            current->fixture.verticalPosition = newVerticalPosition;
            current->fixture.gobo = newGobo;
            return; // Exit loop once the fixture is found and updated
        }
        current = current->next;
    }
}


