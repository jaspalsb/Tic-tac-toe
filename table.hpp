/********************************************************************************
 * ** Author: Jaspal Bainiwal
 * *********************************************************************************/


#ifndef table_HPP
#define table_HPP

enum game {X_WON, O_WON, DRAW, UNFINISHED};

class Table
{
private:
	char arrayOfChars[3][3];

public:
	Table();
	bool move(int, int, char);
	game game();
	void print();
};
#endif // !TABLE_HPP
