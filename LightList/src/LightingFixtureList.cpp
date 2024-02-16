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
    count_ = 0;
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
int LightingFixtureList::FixtureCount() const {
    int sum = 0;
    Node* current = top;
    while (current) {
        current = current->next;
        sum++;        
    }
    
    return sum;
}

//*********************************************************************
// AddToTop
// Adds a new fixture to the top of the linked list.
// new_ID: user provided ID to add.
// Return- No return.
//**********************************************************************
void LightingFixtureList::AddToTop(LightingFixture fixture)
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
void LightingFixtureList::Display() {
    Node* current = top; 
    
    while (current != nullptr) {        // Display fixture details
        std::cout << "Fixture ID: " << current->fixture.fixture_id_ << std::endl
            << current->fixture.fixture_type_ << std::endl
            << "----------------" << std::endl
            << " Barrel Size: " << current->fixture.barrel_size_ << std::endl            
            << " Gobo: " << current->fixture.gobo_ << std::endl
            << " X Position: " << current->fixture.lateral_position_ << "'" << std::endl
            << " Y Position: " << current->fixture.vertical_position_ << "'" << std::endl << std::endl;;
        current = current->next;
    }
}

/*
//*********************************************************************
// AddToBottom (NOT YET IMPLEMENTED)
// adds a fixture to the bottom.
// title: user provided fixture to add
// Return- No return.
//**********************************************************************
void LightingFixtureList::Add_to_Bottom(LightingFixture fixture) {

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
// RemoveFixtureByID
// Removes a node based on FixtureID.
// int fixtureID
// Return- True/ False depending on outcome of the removal function.
//**********************************************************************
signed int LightingFixtureList::RemoveFixtureByID(int fixture_id_) {
    int fixtures_removed = 0; 
    while (fixture_id_ != -1) {
        if (top == nullptr) {
            std::cout << "All fixtures have been removed." << std::endl;
            return fixtures_removed; // Exit if list is empty
        }

        if (top->fixture.fixture_id_ == fixture_id_) {
            // If the fixture to be removed is at the top of the list
            Node* temp = top;
            top = top->next;
            delete temp;
            std::cout << "Deleted fixture: " << fixture_id_ << std::endl;            
            fixtures_removed++;
        }
        else {
            Node* prev = nullptr;
            Node* current = top;

            while (current != nullptr && current->fixture.fixture_id_ != fixture_id_) {
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
                std::cout << "Deleted fixture: " << fixture_id_ << std::endl;
                fixtures_removed++;
            }
        }

        std::cout << "Enter fixtureID to delete, or -1 to exit: ";
        fixture_id_ = get_unsigned_integer_input("");

    }

    return fixtures_removed;
}


//*********************************************************************
// MoveToTop
// moves a node to the top
// fixture_id_: user provided ID to move to top. 
// Return- True/ False depending on success of function.
//**********************************************************************
bool LightingFixtureList::MoveToTop(int fixture_id_) {
    Node* p = top;     //traverse the list
    Node* n = nullptr; //trailing node ptr

    //skips nodes until fixtureID matches or reach the end of the list
    while (p && p->fixture.fixture_id_ != fixture_id_) {
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
// UpdateFixtureSpecs
// Updates a fixture based on a provided ID.
// int fixtureID
// Return- No return.
//**********************************************************************
void LightingFixtureList::UpdateFixtureSpecs(int fixture_id_) {
    unsigned int new_fixture_id = std::abs(fixture_id_);
    unsigned int new_barrel_size = 0;
    std::string new_fixture_type;
    std::string new_gobo;
    signed int new_lateral_position, new_vertical_position = 0;
    
    if (top == nullptr) {
        // Create a new node and set it as the top of the list
        LightingFixture newFixture("Default.", 1, 0, "No gobo.", 0, 0);
        top = new Node(newFixture);        
    }
        
    std::cout << "Enter new fixture Type for fixture with ID " << fixture_id_ << ": ";
    std::cin.ignore(); // Clear any remaining characters from the input buffer
    std::getline(std::cin, new_fixture_type);

    std::cout << "Enter new barrel size for fixture with ID " << fixture_id_ << ": ";
    new_barrel_size = get_unsigned_integer_input("");

    std::cout << "Enter new gobo for fixture with ID " << fixture_id_ << ": ";
    std::cin.ignore(); // Clear any remaining characters from the input buffer
    std::getline(std::cin, new_gobo);   

    std::cout << "Enter new LateralPosition for fixture with ID" << fixture_id_ << ": ";
    new_lateral_position = get_signed_integer_input("");

    std::cout << "Enter new VerticalPosition for fixture with ID" << fixture_id_ << ": ";
    new_vertical_position = get_signed_integer_input("");
    std::cout << std::endl;
    
    // Check if the list is empty
    //     
    Node* current = top;
    while (current != nullptr) {
        if (current->fixture.fixture_id_ == fixture_id_) {
            current->fixture.fixture_type_ = new_fixture_type;
            current->fixture.barrel_size_ = new_barrel_size;           
            current->fixture.lateral_position_ = new_lateral_position;
            current->fixture.vertical_position_ = new_vertical_position;
            current->fixture.gobo_ = new_gobo;
            return; // Exit loop once the fixture is found and updated
        }
        current = current->next;
    }
}


