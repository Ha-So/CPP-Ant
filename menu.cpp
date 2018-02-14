/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: menu.cpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This the function definition file for the functions in
** menu.hpp. The functions here run through each neccesary variable needed
** to start the program and obtain user input. User input is then verified
** by sending it to the input validation function (inputVal.cpp) before it is 
** returned to the mainAnt.cpp file. 
*********************************************************************/

#include "menu.hpp"
#include "inputVal.hpp"
#include <iostream>

using namespace std;

/*********************************************************************
**                              menu()
*This is the main menu function. It utilizes switch functionality so it can 
*display multiple menu options to the user depending on the parameter. The 
*parameter entered is a single character which is used to navigate to each
* case. This function is called multiple times by mainAnt.cpp to advance the menu
* and program.
*********************************************************************/

int menu(char mainType)
{
	clearScreen();
	int aChoice;	//This variable is re-used to hold various user integer input
	 
	/*For all cases below, user input is passed to the inputVal function by reference to validate 
	* input. Input is only returned to mainAnt.cpp if the input is deemed valid*/
	switch(mainType)
	{
	  /*Case A is the opening message of the program, here the user can decide to custom select
	  * settings, use pre-set settings or exit.*/
	  case 'A':
		cout <<"Hello! Welcome to Langton's Ant simulation. This program will output" << endl;
    	cout <<"a board based on this Turing machine. " << endl;
    	cout << "Please make a selection below: (Enter 1 ,2 or 3)" << endl;
    	cout << "1. Run Langton's Ant and select settings" << endl << "2. View a pre-set emergent order up to 12,000 steps" << endl;
    	cout <<"3. Quit" << endl;
    	cout << "Selection: "; 
    	
    	inputVal(mainType, &aChoice);
    	return aChoice;
		
	  break;
	  // Case B asks for user input to determine the max rows the array will have
	  case 'B':

            cout <<"Please enter the max number of rows for the matrix." << endl;
            cout << "We suggest no higher than 100." << endl << "Rows: "; 
            inputVal('B', &aChoice);
            return aChoice;
	  break;
	  // Case C asks for user input to determine the max columns the array will have
	  case 'C':        
	  		cout << "Please enter the max number of columns for the matrix." << endl;
            cout << "We suggest no higher than 100." << endl << "Columns: "; 
            inputVal('C', &aChoice);
            return aChoice;

	  break;
	  // Case D asks for user input to determine the starting row of the Ant.
	  case 'D':

	  		cout << "Please enter the starting row of the ant. 0 is the first row. " << endl;
            cout << "Starting row: ";
            inputVal('D', &aChoice);
            return aChoice;

	  break;
	  // Case E asks for user input to determine the starting column of the Ant.
	  case 'E':

            cout << "Please enter the starting column of the ant. 0 is the first column.  " << endl;
            cout << "Starting column: ";
         	inputVal('E', &aChoice);
            return aChoice;
	  break;
	  // Case F asks for user input to determine the  total steps the Ant will move
	  case 'F':

	  		cout << "Please enter the total number of steps the ant should take." << endl;
            cout << "Total steps: ";
            inputVal('F', &aChoice);
            return aChoice;
	  break;


	}
	return 0;
}

/*********************************************************************
**                              charMenu()
*charMenu is similar to menu() in functionality. Where menu focuses on integer
input, charMenu seeks and verifies character input. It is called with a single
* character as a parameter to navigate to the correct menu option. If the user
* input is verified, it returns that value to mainAnt.cpp
*********************************************************************/
char charMenu(char type)
{
	char charChoice;		//Holds user character input

	switch(type)

	 {
	 	//Case A asks the user for the starting direction and passes the function by reference
	 	//to be verified. 
		case 'A':
		cout <<"Please enter the starting Ant direction. North, South, East or West." << endl;
        cout << "Input as N, S, E or W only." << endl << "Direction: "; 
        inputVal('A', &charChoice);
        return charChoice;

		break;

	 }
return charChoice;

}

/*********************************************************************
**                              displaySettings()
*This function is designed to display all of the variable settings in the
* program on screen either decided by the user or pre-set.
*********************************************************************/
void displaySettings(int sRow, int sCol, int uRow, int uCol, int tSteps, char sDirection)
{

	        cout << endl << endl << "Program Settings" << endl << "-----------------" << endl;
            cout << "Matrix size: [" << uRow << "][" << uCol << "]" << endl;
            cout << "Initial ant position: [" << sRow << "][" << sCol << "]" << endl;
            cout << "Total steps: " <<tSteps << endl;
            cout << "Initial Direction: " << sDirection << endl << endl;

}
/*********************************************************************
**                    		  clearScreen()
** Clears the terminal and places the cursor at the bottom of the screen
*********************************************************************/

void clearScreen()
{
	system("clear");
	string newline(100, '\n');
	cout << newline << endl;
}
