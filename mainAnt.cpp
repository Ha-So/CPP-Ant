/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: mainAnt.cpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This program runs a simulation of Langton's Ant, a Turing machine.
The user will input values for the size of the matrix, starting position of the ant, 
initial direction and total steps to run. The program will then print out the array at 
each step until the final step is reached. This mainAnt.cpp file sets up all the
required values and starts the program.  In the terminal type "make" to 
compile this program and "./runAnt" to start it. 
*********************************************************************/

#include <iostream>
#include "inputVal.hpp"
#include "Ant.hpp"
#include "menu.hpp"

using namespace std;


int firstChoice;        //Initial input by user
int userRow;            //Max number of rows in array
int userCol;            //Max number of columns in array
int startRow;           //Starting row of the ant
int startCol;           //Starting column of the ant
int totalSteps;         //Total steps the ant will take
char startDirection;    //Initial direction of the ant. 


int main()
{
    //Calls to menu() to retrieve user selection in menu screen
    firstChoice = menu('A');


    //If user selects 1, they custom set all the settings in the program
    if (firstChoice == 1)
      {
        /*All variables call to the menu functions to retrieve input. The value returned
        * is stored in the variables to later be passed on. See the menu functions for further
        * clarifications. */
            userRow = menu('B');
     
            userCol = menu('C');

            startRow = menu('D');
            
            startCol = menu('E');

            totalSteps = menu('F');

            startDirection = charMenu('A');
     }

    //If the user has selected 2, the program runs with pre-set settings that demonstrate the "highway" 
    else if (firstChoice == 2)
    {
        /*Setting each variable to a pre-set number for the best display of Langton's Ant*/
            userRow = 100;
     
            userCol = 100;

            startRow = 49;
            
            startCol = 49;

            totalSteps = 12000;

            startDirection = 'N';
    }

    //If the user has selected 3, the program exits
    else if (firstChoice == 3)
    {
        cout << "Program exiting, goodbye." << endl;
        return 0; 
    }
    

// Creates an Ant object with all the variables either selected by the user or pre-set
Ant mainAnt(startRow, startCol, userRow, userCol, totalSteps, startDirection);

//Runs the program with the new Ant object
mainAnt.startSimulation();

//Displays the program settings at the end of the simulation
displaySettings(startRow, startCol, userRow, userCol, totalSteps, startDirection);
 

//Indicates successful completion of the porgram and closes it.
cout << "Simulation completed, program exiting." << endl;
return 0;

} 