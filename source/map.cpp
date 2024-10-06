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

Color GetColorFromChar(char c)
{
	switch (c)
	{
		case '-': return BLACK;
		case '_': return BLUE;
		default: return GREEN;
	}
}

#define CUBE_SIZE 1.0f

void RenderGridIn3D(std::vector<std::string> grid, t_program *c)
{
	int i;
	int j;

	i = 0;
	while (i < grid.size())
	{
		j = 0;
		while (j < grid[i].size())
		{
			char c = grid[i][j];
			Color color = GetColorFromChar(c);

			Vector3 position = { j * CUBE_SIZE, 0, i * CUBE_SIZE };
			DrawCube(position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, color);
			if (c == '-')
			{
				int h = 0;
				while (h < 5)
				{
					Vector3 position = { j * CUBE_SIZE, h * CUBE_SIZE, i * CUBE_SIZE };
					DrawCube(position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, color);					
					h++;
				}
			}
            DrawCubeWires(position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
			j++;
		}
	i++;
	}
}


