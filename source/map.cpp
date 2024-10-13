//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/map.cpp                                                 ***//
//***     Header Created: Sun Oct 06 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


#include "../includes/program.hpp"

std::vector<std::string>	read_map(std::string map, t_program *c)
{
	std::ifstream file(map);


	if (!file.is_open())
	{
		std::cerr << "Error: Could not open the file" << std::endl;
		return c->grid;
	}

	std::string line;
	while (std::getline(file, line))
		c->grid.push_back(line);

	
	file.close();

	int i;
	int j;

	i = 0;
	while (i < c->grid.size())
	{
		j = 0;
		while (j < c->grid[i].size())
		{
			std::cout << c->grid[i][j];
			j++;
		}
		std::cout << std::endl;
	i++;
	}

	return (c->grid);
}

