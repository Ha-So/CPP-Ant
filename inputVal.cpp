// Coded using reference: http://www.cplusplus.com/forum/beginner/26821/
/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: inputVal.cpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This is the function implementation file for inputVal.hpp
** The functions here verify user input passed as a pointer and returns
** true if the input is valid. Otherwise they loop until the user entry is 
** valid for that needed case. 
*********************************************************************/

#include <iostream>
#include <string>
#include "inputVal.hpp"


using namespace std;


  

/*********************************************************************
**                          inputVal(char type, int *input)
*This do-while statement first sets the bool flag to false. Then it asks for user input. 
  * The appropriate display message is shown via the menu.cpp file before this function call
  * is made. It has two checks. The first all user input goes through, to see if the input can
  * be stored in the correct data type, if not all other checks are skipped and the user is 
  * prompted to enter again. If the data type is correct, it then checks is that value is within
  * the proper bounds. True is returned when the input is verified, false otherwise.
*********************************************************************/

bool inputVal(char type, int *input)
 
{
   
  
   bool validIn;        //Hold the boolean return value. True if valid, false otherwise.
   static int maxRow;   //Holds the user entered total rows for later use to verify the starting row
   static int maxCol;   //Holds the user entered total columns for later use to verify the starting column
   const int ZERO = 0;
   const int ONE = 1;
   const int TWO = 2;
   const int THREE = 3;
   const int ARRLIMIT = 100;    //ARRLIMIT holds the max rows and columns the user can enter


        do
            {
                validIn = false;
                cin >> *input;
                
                // Initial check of input data type. 
                if (cin.fail())
                    {
                        cin.clear();
                         cin.ignore();
                        
                        cout << "Invalid input, please try again: " << endl;
                    }
                // Type A only allows 1, 2 or 3 for entry for menu navigation
                else if (type == 'A')
                    {
                        if (*input == ONE || *input == TWO || *input == THREE)
                        {
                            validIn = true; 
                             return validIn;
                        }
                        else
                        {
                            cout << "Invalid input, please try 1 or 2 or 3: " << endl;
                            validIn = false;
                        }
                    
                    }
                 // Type B only allows a total row entry between 1 and 100
                 else if (type == 'B') 
                    {  
                        if (*input >= ONE && *input <= ARRLIMIT)
                        {
                            validIn = true; 
                            maxRow = *input;
                            return validIn;
                        }
                        
                        else
                        {
                            cout << "Invalid input, please try from 1 to 100: " << endl;
                            validIn = false;
                        }
                    
                    }
                // Type C only allows a total column entry between 1 and 100
                else if (type == 'C')
                    {
                        if (*input >= ONE && *input <= ARRLIMIT)
                             {
                                validIn = true; 
                                maxCol = *input;
                                return validIn;
                             }
                        else
                             {
                                cout << "Invalid input, please try from 1 to 100: " << endl;
                                validIn = false;
                             }

                    }
                // Type D only allows a total row entry between 1 and the maxRow variable set above
                else if (type == 'D')
                    {
                        if ((*input >= ZERO) && (*input < maxRow))
                                {

                                    validIn = true; 
                                    return validIn;
                                }
                        else
                                {
                                    cout << "Invalid input, please try from 0 to " << maxRow - 1 << ":"<< endl;
                                    validIn = false;
                                } 
                        
                    }
                // Type E only allows a total column entry between 1 and the maxCol variable set above
                else if (type == 'E')
                    {
                        if ((*input >= ZERO) && (*input < maxCol))
                                {
                                    validIn = true; 
                                    return validIn;
                                }
                        else
                                {
                                    cout << "Invalid input, please try from 0 to " << maxCol - 1 << ":"<< endl;
                                    validIn = false;
                                } 
                        
                    }
                //Type F verifies total ant steps, accepts any integer above 0
                else if (type == 'F')
                    {
                        if ((*input >= ZERO))
                                {
                                    validIn = true; 
                                    return validIn;
                                }
                        else
                                {
                                    cout << "Invalid input, please a value 0 and above: " << endl;
                                    validIn = false;
                                } 
                        
                    }
                    
                    
                    
                } while (validIn != true);
  // Loop ends here if no type is matched, indicating verification has failed
  return validIn = false;
}
   

/*********************************************************************
**                          inputVal(char type, char *charInput)
*This do-while statement first sets the bool flag to false. Then it asks for user input. 
  * The appropriate display message is shown via the menu.cpp file before this function call
  * is made. It has two checks. The first all user input goes through, to see if the input can
  * be stored in the correct data type, if not all other checks are skipped and the user is 
  * prompted to enter again. If the data type is correct, it then checks is that value is within
  * the proper bounds. True is returned when the input is verified, false otherwise.
  * Note - This function works just as the inputVal function above. Hwoever this one
  * checks for characters and the other for integers.
*********************************************************************/
bool inputVal(char type, char *charInput)
{
    bool validIn;
    do
            {
                validIn = false;
                cin >> *charInput;
                

                if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        
                        cout << "Invalid input, please try again: " << endl;
                    }
                // Type A verifies the Ant direction for North South, East or West
                 else if (type == 'A')

                    {
                        //A lowercase entry is stored as an uppercase for comparison
                        *charInput = toupper(*charInput);

                        if (*charInput == 'N' || *charInput =='S' || *charInput == 'E' || *charInput == 'W')
                        {
                            
                            validIn = true; 
                             return validIn;
                        }
                        else
                        {
                            cout << "Invalid input, please try N, S, E, or W: " << endl;
                            validIn = false;
                        }

                    }
            } while (validIn != true);
  return validIn = false;

}
 
