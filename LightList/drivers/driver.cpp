// File Name: driver.cpp//
// Author: Jesse Walser- Castro
// Date: 02/13/2022
// Assignment Number: 1 
// Data Structures & Algorithms Spring 2024
// Contains main function, provides menu for updating, deleting, and displaying fixtures.

#include "main.h"
#include "input_utils.h"
#include "LightingFixtureList.h"

#include <iostream>
#include <string>


int main() {
	//Initialize linked list.
	LightingFixtureList fixtureList;

	//Initialization of objects.
	fixtureList.AddToTop(LightingFixture("Source4", 1, 19, "Flowers", -4, 8));
	fixtureList.AddToTop(LightingFixture("ParCan", 2, 0,  "None", 0, 0));
	fixtureList.AddToTop(LightingFixture("Source4", 3, 0,  "Flowers", 4, 8));
	fixtureList.AddToTop(LightingFixture("MacViper", 4, 0, "None", 8, 0)); 
	
	
	std::cout << "Welcome to Prism." << std::endl;

	signed int temp_fixture_id; //Initializes menu option & base fixture.
	unsigned int removed_fixture = 0,  choice = 1; //0 if no fixture has been removed. Counts amt removed if (>= 1)
	
	//Implement function Menu (WIP)
	while (choice != 0) {
		
		std::cout 	<< "\nPress 1 to update fixtures."
					<< "\nPress 2 to delete fixtures. "
				    << "\nPress 3 to display fixtures." 
					<< "\nPress 0 to exit the program: ";
		
		choice = get_unsigned_integer_input("");
		
		switch (choice) {
			case 0:
				std::cout << "Exiting." << std::endl;
				break;

			case 1: 
				//Call function UpdateFixtureSpecs				
				std::cout << "\nEnter fixtureID to update, or -1 to exit:";
				temp_fixture_id = get_unsigned_integer_input("");
							
				while (temp_fixture_id != -1) {
					fixtureList.UpdateFixtureSpecs(temp_fixture_id);
					std::cout << "\n\n\nEnter fixtureID to update, or -1 to exit:";
					temp_fixture_id = get_unsigned_integer_input("");
				}
				temp_fixture_id = 0; //resets ID
				break;

			case 2:
				// Call function RemoveFixtureByID
				std::cout << "Delete fixtures by ID. -1 to exit. " << std::endl;
				temp_fixture_id = get_unsigned_integer_input("");
				removed_fixture = fixtureList.RemoveFixtureByID(temp_fixture_id); //returns 0 if nothing removed.
				std::cout << "Removed " << removed_fixture << " fixtures." << std::endl;
				break;

			case 3:
				// Call function to display fixtures on the current hang position.
				std::cout << "Current amount of fixtures on hanging position __ is : " << fixtureList.FixtureCount() << std::endl;
				fixtureList.Display();
				break;

			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
				break;
		}		
	}
		
	return 0;
}
	
