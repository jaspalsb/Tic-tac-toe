/*******************************************************************************************
 * **Author: Jaspal Bainiwal
 * ***********************************************************************************************/

#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "table.hpp"
#include <string>
class Director
{
private:
	Board gameField;
	char fieldTurn;
public:
	T3Reader(char);
	bool read(std::string);

};
#endif // !DIRECTOR_HPP
