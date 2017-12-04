/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: menu.hpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This is the header file for menu.cpp 
** It contains the function prototypes, with the definition in menu.cpp
** The menu functions handle user input and menu navigation during the program.
** Please see menu.cpp for more info on each function. 
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

int menu(char type);
char charMenu(char type);
void displaySettings(int sRow, int sCol, int uRow, int uCol, int tSteps, char sDirection);

#endif