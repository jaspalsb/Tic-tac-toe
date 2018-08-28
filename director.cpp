/***********************************************************************************************
 * ** Author: Jaspal Bainiwal
 * **************************************************************************************************/

#include "director.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**************************************************************************************************
 * The constructor takes in character parameter and sets it equal to the member character variable which
 * player will go first.
 * ****************************************************************************************************/
Director::Director(char fm)
{
	fieldTurn = fm;
}

/****************************************************************************************************
 * The readGameFile function takes in the string name of the fileName and reads the values from that file.
 * It reads two values in and sets it to the row and columns variables. While it is reading after two integers
 * I use series of nested if statements. First I test it the file is still reading and the game is unfinished
 * then I move onto the next if else statement. The inside if statement sends arguments to the Board Class make
 * move member function. If the member function made the move then the function returns true and the inside
 * if the if statement executes, which is to switch the player from o to x and vice versa. Otherwise if makemove
 * is false then that means the move was occupied so then I set positionoccupied to false. Now back to outer if else
 * statement, if the game is still reading values but the game has already finished then positionoccupied flag 
 * is also set to false. Once the while loop ends after reading all the files values, if the positionoccupied flag
 * was triggered to false then, that means either the file made illegal move or there were more values after
 * the game ended as draw, XWON, or OWon. In these scenarios the function closes the file and returns false.
 * Other wise it closes file and returns true.
 * *****************************************************************************************************************/
bool Director::read(std::string fileName)
{
	bool positionOccupied = true;
	int progress;
	int row, col;
	std::ifstream inputFile;

	//progress = gameField.gameState();
	//std::cout << "progress value " << progress << std::endl;

	inputFile.open(fileName);
	while (inputFile >> row >> col)
	{
		progress = gameField.gameState();
		if (progress == UNFINISHED)
		{
			if (gameField.makeMove(row, col, fieldTurn))
			{
				//gameField.print();
				progress = gameField.gameState();

				if (fieldTurn == 'o')
				{
					fieldTurn = 'x';
				}
				else if (fieldTurn == 'x')
				{
					fieldTurn = 'o';
				}

			}
			else
			{
				positionOccupied = false;
			}
		}
		else
		{
			positionOccupied = false;
		}
	}
	//progress = gameField.gameState();
	//std::cout << "progress value at the end " << progress << std::endl;
	if (positionOccupied == false)
	{
		inputFile.close();
		return false;
	}

	else
	{
		inputFile.close();
		return true;
	}

}
