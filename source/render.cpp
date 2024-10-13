//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Clones/Project_Neo/source/RENDER.CPP                                                   ***//
//***     Header Created: Mon Oct 14 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/program.hpp"

Color GetColorFromChar(char c)
{
	switch (c)
	{
		case '-': return BLACK;
		case '_': return BLUE;
		default: return GREEN;
	}
}

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
                	Vector3 wallSize = { CUBE_SIZE, CUBE_SIZE, CUBE_SIZE };
                	DrawCube(position, wallSize.x, wallSize.y, wallSize.z, color);		
					h++;
				}
			}
            DrawCubeWires(position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
			j++;
		}
	i++;
	}
}
