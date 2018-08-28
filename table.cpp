/********************************************************************************
 * ** Author: Jaspal Bainiwal
 * ***********************************************************************************/

#include "table.hpp"
#include <iostream>
/****************************************************************************************
 * The default constructor makes the array of characters set equal to empty spaces
 * *********************************************************************************************/
Table::Table()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			arrayOfChars[x][y] = ' ';
		}
	}
}
/***********************************************************************************************
 * The makeMove function takes in three parameters, two integers and character value. The two integer
 * values are used to index the array of characters. If the indexed element is equal to empty space then
 * that means the piece is empty on the game board. Therefore I set the element to the characer argument and
 * return true. Otherwise if the indexed element has any value other than a empty character ' ' the function
 * doesn't make any move and returns false.
 * *********************************************************************************************************/
bool Table::move(int row, int column, char XorY)
{
	if (arrayOfChars[row][column] == ' ')
	{
		arrayOfChars[row][column] = XorY;
		return true;
	}

	else
	{
		return false;
	}
}
/**********************************************************************************************
 * The gamestate function first has a counter to calculate the number of turns that have already occured.
 * This is done by having a turncounter variable and then using a nested for loop to find any values in 
 * the array of characters that contain either an x or an o. If the array does then I increment the turn
 * counter.
 * Next I test for every winning scenario in the game of tic tac toe, if player x or o wins has
 * any of the three combinations then I return the enum value xwon or owon. If after testing
 * all the if elseif statements and there are no winning combinations then I test if the game has
 * ended in a draw. If the number of turns that have already occurred is at 9 that means the game has
 * ended in a draw and then return the enum value DRAW. Otherwise after zero winning combinations and not
 * a draw that means the game has not finished, so I return the enum value UNFINISHED.
 * *******************************************************************************************************/

game Table::game()
{
	int turnCounter = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if ((arrayOfChars[row][column] == 'o') || (arrayOfChars[row][column] == 'x'))
				turnCounter++;
		}
	}


	if ((arrayOfChars[0][0] == 'o') && (arrayOfChars[0][1] == 'o') && (arrayOfChars[0][2] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][0] == 'x') && (arrayOfChars[0][1] == 'x') && (arrayOfChars[0][2] == 'x'))
		return X_WON;
	else if ((arrayOfChars[1][0] == 'o') && (arrayOfChars[1][1] == 'o') && (arrayOfChars[1][2] == 'o'))
		return O_WON;
	else if ((arrayOfChars[1][0] == 'x') && (arrayOfChars[1][1] == 'x') && (arrayOfChars[1][2] == 'x'))
		return X_WON;
	else if ((arrayOfChars[2][0] == 'o') && (arrayOfChars[2][1] == 'o') && (arrayOfChars[2][2] == 'o'))
		return O_WON;
	else if ((arrayOfChars[2][0] == 'x') && (arrayOfChars[2][1] == 'x') && (arrayOfChars[2][2] == 'x'))
		return X_WON;
	else if ((arrayOfChars[0][0] == 'o') && (arrayOfChars[1][0] == 'o') && (arrayOfChars[2][0] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][0] == 'x') && (arrayOfChars[1][0] == 'x') && (arrayOfChars[2][0] == 'x'))
		return X_WON;
	else if ((arrayOfChars[0][1] == 'o') && (arrayOfChars[1][1] == 'o') && (arrayOfChars[2][1] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][1] == 'x') && (arrayOfChars[1][1] == 'x') && (arrayOfChars[2][1] == 'x'))
		return X_WON;
	else if ((arrayOfChars[0][2] == 'o') && (arrayOfChars[1][2] == 'o') && (arrayOfChars[2][2] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][2] == 'x') && (arrayOfChars[1][2] == 'x') && (arrayOfChars[2][2] == 'x'))
		return X_WON;
	else if ((arrayOfChars[0][0] == 'o') && (arrayOfChars[1][1] == 'o') && (arrayOfChars[2][2] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][0] == 'x') && (arrayOfChars[1][1] == 'x') && (arrayOfChars[2][2] == 'x'))
		return X_WON;
	else if ((arrayOfChars[0][2] == 'o') && (arrayOfChars[1][1] == 'o') && (arrayOfChars[2][0] == 'o'))
		return O_WON;
	else if ((arrayOfChars[0][2] == 'x') && (arrayOfChars[1][1] == 'x') && (arrayOfChars[2][0] == 'x'))
		return X_WON;
	if (turnCounter == 9)
	{
		return DRAW;
	}
	else
	{
		return UNFINISHED;
	}
}
/*****************************************************************************************************************
 * optional print board ( •_•) ( •_•)>⌐■-■ (⌐■_■)	
 * ****************************************************************************************************************/
void Table::print()
{
	std::cout << "   0      1    2" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "0|" << arrayOfChars[0][0] << "   |" << arrayOfChars[0][1] << "   |" << arrayOfChars[0][2] << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1|" << arrayOfChars[1][0] << "   |" << arrayOfChars[1][1] << "   |" << arrayOfChars[1][2] << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "2|" << arrayOfChars[2][0] << "   |" << arrayOfChars[2][1] << "   |" << arrayOfChars[2][2] << std::endl;
}
