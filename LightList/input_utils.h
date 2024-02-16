// File Name: input_utils.h
//
// Author: Jesse Walser- Castro
// Date: 02/13/2022
// Assignment Number: 1 
// Data Structures & Algorithms Spring 2024
// Declares functions to provide input validation.  

#pragma once
#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <limits>

//*********************************************************************
// get_signed_integer_input
// Validates an user-provided integer input.
// prompt: user provided integer input.
// Return- validated signed input.
//**********************************************************************
inline int get_signed_integer_input(const std::string& prompt) {
    int input;
    std::cout << prompt;
    std::cin >> input;

    // Validate input
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid signed integer: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cin >> input; // Try reading again
    }

    return input;
}

//*********************************************************************
// get_unsigned_integer_input
// Validates an user-provided integer unsigned input.
// prompt: user provided integer input.
// Return- validated unsigned input.
//**********************************************************************
inline unsigned int get_unsigned_integer_input(const std::string& prompt) {
    unsigned int input;
    std::cout << prompt;
    std::cin >> input;

    // Validate input
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid signed integer: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cin >> input; // Try reading again
    }

    return input;
}

#endif INPUT_UTILS_H

