/*********************************************************************
** Program name: Langton's Ant (Turing Machine)
** File name: Ant.hpp
** Author: Haris Sohail
** Date: 04/14/2017
** Description: This the header file for the Ant class. The Ant class
** data members hold the board along with the board color and size, ant position
**, ant direction and total steps to be taken. The functions here can alter the 
** board changing squares from black to white, placing the ant as needed, correctly
** moving the ant based on the rules and overrall running the entire simulation.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

 
class Ant

{
    private:
        char **antArray;    // 2D board array for ant to travel on
        int maxRow;         // Total rows on board
        int maxCol;         // Total columns on board
        char antDirect;     // Holds the N,S,W or E  direction the ant is facing
        int curRow;         // Ant's current row
        int curCol;         // Ant's current column
        int maxSteps;       // Hold the total steps the program will run for
        char currentColor;  // Color of square ant is currently on
        char nextColor;     // Holds the color the ant will be on next
        char updateType;    // Used to update the next move of the ant
        bool boundFlag;     // Used to check if the ant is moving off the set array
       int count = 0;       // Holds the steps taken by the ant

        
    //Function prototypes for the Ant class. Please see Ant.cpp for definitions and explanations 
    public:
        Ant(int startRow, int startCol, int maxRow, int maxCol, int steps, char startDirect);
        ~Ant();
        void print();
        void placeAnt(int startR, int startC);
        bool checkColor();
        bool saveColor(int nextRow, int nextCol);
        void moveAnt();
        void updatePosition();
        bool checkBounds();
        void startSimulation();
       

        
};
#endif 