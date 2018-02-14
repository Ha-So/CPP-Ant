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
#include <sstream>
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
   
  
   bool validIn = false;        //Hold the boolean return value. True if valid, false otherwise.
   string strInput = " ";     //Convert user input to string
   int temp;
   static int maxRow;   //Holds the user entered total rows for later use to verify the starting row
   static int maxCol;   //Holds the user entered total columns for later use to verify the starting column
   const int ZERO = 0;
   const int ONE = 1;
   const int TWO = 2;
   const int THREE = 3;
   const int ARRLIMIT = 100;    //ARRLIMIT holds the max rows and columns the user can enter

   do
   {
      getline(cin, strInput);
      stringstream convert(strInput);
      if (!(convert >> temp))
      {
        temp = -1;
      }
  
   switch(type)
   {
   


      // Type A only allows 1, 2 or 3 for entry for menu navigation
      case 'A':
       if (temp == ONE || temp == TWO || temp == THREE)
                        {
                            *input =  temp;
                            validIn = true; 
                             return validIn;
                        }
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please try 1 or 2 or 3: " << endl;
                            validIn = false;
                        }

      break;

      case 'B':
       if (temp >= ONE && temp <= ARRLIMIT)
                        {
                          *input =  temp;
                            validIn = true; 
                            maxRow = *input;
                            return validIn;
                        }
                        
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please try from 1 to 100: " << endl;
                            validIn = false;
                        }

      break;
      case 'C':
       if (temp >= ONE && temp <= ARRLIMIT)
                        {
                          *input =  temp;
                            validIn = true; 
                            maxCol = *input;
                            return validIn;
                        }
                        
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please try from 1 to 100: " << endl;
                            validIn = false;
                        }

      break;
       case 'D':
       if ((temp >= ZERO) && (temp < maxRow))
                        {
                          *input =  temp;
                          validIn = true; 
                          maxCol = *input;
                          return validIn;
                        }
                        
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please try from 0 to " << maxRow - 1 << ":"<< endl;
                            validIn = false;
                        } 

      break;
       case 'E':
       if ((temp >= ZERO) && (temp < maxCol))
                        {
                          *input =  temp;
                          validIn = true; 
                          maxCol = *input;
                          return validIn;
                        }
                        
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please try from 0 to " << maxCol - 1 << ":"<< endl;
                            validIn = false;
                        } 

      break;
       case 'F':
       if (temp > ZERO)
                        {
                           *input =  temp;
                            validIn = true; 
                            maxCol = *input;
                            return validIn;
                        }
                        
                        else
                        {
                            *input =  temp;
                            cout << "Invalid input, please a value 0 and above: " << endl;
                            validIn = false;
                        }

      break;

   }
   cin.sync();
 }while(validIn == false);

   return validIn;

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
   bool validIn = false;        //Hold the boolean return value. True if valid, false otherwise.
   string strInput = " ";     //Convert user input to string
   char temp;

   do
   {
      getline(cin, strInput);
      if (!(temp = strInput[0]))
      {
        temp = 'Z';
      }
  
   switch(type)
   {
   


      // Type A only allows 1, 2 or 3 for entry for menu navigation
      case 'A':
        temp = toupper(temp);
        if (temp == 'N' || temp =='S' || temp == 'E' || temp == 'W')
                        {
                            *charInput =  temp;
                            validIn = true; 
                             return validIn;
                        }
                        else
                        {
                            *charInput =  temp;
                              cout << "Invalid input, please try N, S, E, or W: " << endl;
                            validIn = false;
                        }

      break;

   }
   cin.sync();
 }while(validIn == false);

   return validIn;

}
 
