/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: Ant.cpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This the function implementation file for the Ant class.
** These functions set up the board and change it's appearance as the ant moves.
** Further they control the Ant's movement and check it's bounds over time.
*********************************************************************/

#include "Ant.hpp"
#include <iostream>

using namespace std;

const char WHITE = ' ';     //Blank space used to represent a white square on the board
const char BLACK = '#';     //# sign represents a black square on the board
const char ANT = '@';       //@ sign represents the Ant's current position
const char N = 'N';         //Holds North for direction
const char S = 'S';         //Holds South for direction
const char E = 'E';         //Holds East for direction
const char W = 'W';         //Holds West for direction
const int ZERO = 0;
const int ONE = 1;

/*********************************************************************
**                           Ant::Ant()
*This is the constructor called for an Ant object. It assigns all the private 
* data members with parameters passed from mainAnt.cpp Further it creates
* a dynamically allocated 2D array with those parameters.
*********************************************************************/


Ant::Ant(int startRow, int startCol, int maxRows, int maxCols, int steps, char startDirect)
{
  //Assigning private data members to be used to create the 2D array
  maxRow = maxRows;
  maxCol = maxCols;
  maxSteps = steps;
  curRow = startRow;
  curCol = startCol; 
  currentColor = WHITE;
  antDirect = startDirect;

  //Creating a dynamic 2D array by creating a 1D array of pointers to another 1D array
  antArray = new char*[maxRow];

  for(int j = ZERO; j < maxRow; ++j)
    {
        antArray[j] = new char [maxCol];
    }
    
      for (int i = ZERO; i < maxRow; ++i)
        {
            for (int j = ZERO; j < maxCol; ++j)
                {
                    antArray[i][j] = WHITE;
                }
        }

    
    // Places the ant in it's starting position
	placeAnt(startRow, startCol);

}

/*********************************************************************
**                           Ant::~Ant()
*This is the destructor called for an Ant object. It deletes the any
* 2D array created from the heap when the Ant object is destroyed. 
*********************************************************************/
Ant::~Ant()
{
    //For loop first deletes the 1D array of rows, then the columns.
    for (int i = ZERO; i < maxRow; ++i)
        {
            delete [] antArray[i];
            
        }
    delete [] antArray;

}

/*********************************************************************
**                           Ant::print()
*This function when called prints out the current state of the 2D array.
* That includes any white or black square and ant position. Additionally
* it prints the current ant location, direction and step count. 
*********************************************************************/

void Ant::print()
{
    //For loop that prints out each element in the array
	for (int i = ZERO; i < maxRow; ++i)
        {
            for (int j = ZERO; j < maxCol; ++j)
                {
                    cout << antArray[i][j];
                }
            cout << endl;
        } 
    // Series of statements to display current status of variables. 
    cout << "Step: " << count++ << endl;
    cout << "Current Ant Position: " << "[" << curRow << "][" << curCol << "]" << endl;
    cout << "Current Ant Direction: " << antDirect << endl;
    cout << "Current Square Color: ";
    if (currentColor == WHITE)
        {
            cout << "WHITE";

        }
    else
        {
            cout << "BLACK";
        }
    cout << endl << endl;
}

/*********************************************************************
**                           Ant::placeAnt()
*This function takes in two paramters, the row and column the Ant needs
* to be placed on and updates the board by adding the Ant character there.
*********************************************************************/
void Ant::placeAnt(int row, int col)
{
	antArray[row][col] = ANT;
}

/*********************************************************************
**                           Ant::checkColor()
*When called this function checks the value held in currentColor. The square
* the ant is currently on. It is either black or white. If white it returns true,
* and returns false if black. 
*********************************************************************/
bool Ant::checkColor()
{

	if (currentColor == WHITE)
	{
		return true;
	}

	else 
	{
		return false; 
	}


}

/*********************************************************************
**                           Ant::checkBounds()
*This is called in order to check if the next Ant move will place the ant
* out of bounds of the 2D array. It splits each case up by the direction 
* the ant is facing. If the move is outside the array it returns false, true if
* the move is valid. 
* If invalid no move is made, only the ant direction remains changed. 
*********************************************************************/

bool Ant::checkBounds()
{
    // Calls check color to determine if the current square the ant is on is white or black
    if(checkColor())
      {
        // Goes to a specific case depending on the current direction of the ant.
        switch(antDirect)
        {
            /*If the ant is facing North on a white square, it must turn
            * right. So it calculates if heading in the east direction 
            *( (current column + 1) is out of bounds of the max columns.
            * If it is, it simply turns east and no move is made.
            * The same applies for all other directions with the checking altered
            * to match the next direction. */
            case N: if((curCol + ONE)> (maxCol - ONE))
                    {
                        antDirect = E;
                        return false;
                    }
                    else
                    {
                        return true;
                    }
            break;
            case S: if((curCol - ONE) < ZERO)
                    {
                        antDirect = W;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
            case E: if((curRow + ONE) > (maxRow - ONE))
                    {
                        antDirect = S;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
            case W: if((curRow - ONE) < ZERO)
                    {
                        antDirect = N;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
        }
       }
    // Same as above, this is activated if the current color is black
    else if (!checkColor())
    {
         switch(antDirect)
        {
            /*Please refer to the explanation above, it is the same concept. */
            case N: if((curCol - ONE)<ZERO)
                    {
                        antDirect = W;
                        return false;
                    }
                    else
                    {
                        return true;
                    }
            break;
            case S: if((curCol + ONE) > (maxCol - ONE))
                    {
                        antDirect = E;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
            case E: if((curRow - ONE) < ZERO)
                    {
                        antDirect = N;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
            case W: if((curRow + ONE) > (maxRow -ONE))
                    {
                        antDirect = S;
                        return false;
                    }
                    else 
                    {
                        return true;
                    }
            break;
        }



    }
    return false;

}   


/*********************************************************************
**                           Ant::saveColor()
* saveColor utilizes checkColor and checkBounds to determine the Ant's next square.
* Because the Ant will be placed in that same array value, the nextColor value will
* hold that square color temporarily so it can be used to determine them ove after.
* It is updated for each move. 
*********************************************************************/

bool Ant::saveColor(int nextRow, int nextCol)

{

	//This initial check determines if the current square is black or white
	if (checkColor())
		{
            //Each case is called based on the Ant's current direction
			switch(antDirect)
			{
                /*Each case is called based on the Ant's current direction.
                * It checks if the next move is valid, via checkBounds. If not
                * only the direction is changed and it rturns false. If the move is
                * valid the next square the ant will be at has it's current color saved
                * within nextColor and the function returns true.*/
				case N:	if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow][nextCol +ONE];
                    	antDirect = E;
                        return true;

                break;
                case S: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow][nextCol -ONE];
                    	antDirect = W;
                        return true;

                break;
                case E: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow+ONE][nextCol]; 
                        antDirect = S;
                        return true;
                break;
                case W: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow-ONE][nextCol]; 
                        antDirect = N;
                        return true;
                break;

			}

		}
    // Same functionality as above, please see the comments there
	else if (!(checkColor()))
		{
			switch(antDirect)
			{
				case N:	if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow][nextCol -ONE];
                        antDirect = W;
                        return true;

                break;
                case S: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow][nextCol +ONE];
                    	antDirect = E;
                        return true;

                break;
                case E: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow-ONE][nextCol]; 
                        antDirect = N;
                        return true;

                break;
                case W: if(!(checkBounds()))
                            {
                                return false;
                            }
                        nextColor = antArray[nextRow+ONE][nextCol]; 
                        antDirect = S;
                        return true; 
                break;


				
			}


		}
    return false; 
}


/*********************************************************************
**                         Ant::updatePosition()
*This function updates the current position variables of the ant. These
* variables are used for checks each move so this function is called for
* updating each move. 
*********************************************************************/
void Ant::updatePosition()
{

    /* The updateType variable is assigned prior to calling within the moveAnt() function
    * The names are arbitrary and simply decide wwhat value to update the ant position to.*/
    switch(updateType)
    {
	 case 'V':  curRow += ONE;
     break;
	 case 'X':  curCol += ONE;
     break;
	 case 'Y':  curCol -= ONE;
     break;
	 case 'Z':  curRow -= ONE;
     break; 
    }
}

/*********************************************************************
**                           Ant::moveAnt()
** This is the main function called to actually move the ant and 
* it encompasses several helper functions to do so. It runs a series of
* checks to determine how to move the ant, updates the color of the squares,
* updates color variables to their new values and changes the current Ant position
* as well. 
*********************************************************************/
void Ant::moveAnt()
{
   /* This check runs saveColor which 1. checks if the next move is valid and
    * 2. updates the current ant direction and nextColor variable*/
   boundFlag = saveColor(curRow, curCol);

/* If the move is valid, this sequence activates, otherwise, the ant makes no moves
   * and only changes directions*/
if(boundFlag == true)
  {	
    if (checkColor())
		{
            /*The checkColor function returns white for the current square, so this turns it
            * to black and assigns the new current color before the ant overwrites that square*/
			antArray[curRow][curCol] = BLACK;
            currentColor = nextColor;

            // The Ant has already turned towards the square it wants to move towards here
			switch(antDirect)
			{
                /*Each case calls placeAnt to actually assign the Ant value and then it
                 * changes updateType so the row and column variables can be changed as well*/
				case E:	placeAnt(curRow, curCol+ONE);
                         updateType = 'X';
                break;
                case W: placeAnt(curRow, curCol-ONE);
                    	 updateType = 'Y';
                break;
                case S: placeAnt(curRow+ONE, curCol); 
                         updateType = 'V';
                break;
                case N: placeAnt(curRow-ONE, curCol);
                        updateType = 'Z';
                        
                break;

			}

		}
    /*Same functionality as above, only for a black square*/
	else if (!(checkColor()))
		{
			antArray[curRow][curCol] = WHITE;
            currentColor = nextColor;
			switch(antDirect)
			{
				case W:	placeAnt(curRow, curCol-ONE);
                         updateType = 'Y';
                
                break;
                case E: placeAnt(curRow, curCol+ONE);
                         updateType = 'X';
                break;
                case N: placeAnt(curRow -ONE, curCol);
                        updateType = 'Z';
                        
                break;
                case S: placeAnt(curRow+ONE, curCol);
                         updateType = 'V';
                break;


				
			}


		}
    // Ant current row and column ar now changed based upon the updateType variable
    updatePosition();
  }


}


/*********************************************************************
**                         Ant::startSimulation()
** Called from mainAnt, initiates the simulation and continues to run and print each
** board till the maxSteps variable is reached.
*********************************************************************/
void Ant::startSimulation()
{

print();

for(int i = ZERO; i < maxSteps; i++)
  {    
    moveAnt();

    print();
  }    

}