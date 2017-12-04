/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: inputVal.hpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This is the header file the input validation functions in
** inputVal.cpp. The functions here take in as parameters 1. a type to 
** navigate to the needed case and 2. a pointer to a variable 
** so it can verify the input and instead return true or false. Which 
** is used in input verification in other files. 
*********************************************************************/

#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

bool inputVal(char type, int *intInput); 
bool inputVal(char type, char *charInput); 

#endif