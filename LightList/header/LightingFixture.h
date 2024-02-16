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

//**********************************************************************
// LightingFixture
// Defines class LightingFixture.
//**********************************************************************
class LightingFixture {
public:    
    unsigned int fixture_id_, barrel_size_;
    signed int lateral_position_, vertical_position_;     
    std::string gobo_; //Name of "texture" that is cast by lighting fixture
    std::string fixture_type_; 

    // Constructor
    LightingFixture(const std::string& fixture_type_, unsigned int fixture_id_, 
        unsigned int barrel_size_, const std::string& gobo_, 
        signed int lateral_position_, signed int vertical_position_) {

        this->fixture_type_ = fixture_type_;
        this->fixture_id_ = fixture_id_;
        this->barrel_size_ = barrel_size_;      
        this->gobo_ = gobo_;
        this->lateral_position_ = lateral_position_;
        this->vertical_position_ = vertical_position_;
    }
};

#endif // LIGHTING_FIXTURE_H