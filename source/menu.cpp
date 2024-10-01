//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/menu.cpp                                                ***//
//***     Header Created: Tue Oct 01 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/program.hpp"

void draw_menu(t_program *c)
{
	Rectangle play;
	play.height = 128;
	play.width = 512;
	play.x = (RES_X / 2) - (play.width / 2);
	play.y = (RES_Y / 4);
	DrawRectangleRounded(play, 0.32, 1, RAYWHITE);
	DrawText("Project_Neo", play.x + 32, play.y + 32, 42, LIGHTGRAY);

	Rectangle options;
	options.height = 128;
	options.width = 512;
	options.x = (RES_X / 2) - (options.width / 2);
	options.y = (RES_Y / 4) + 196;
	DrawRectangleRounded(options, 0.32, 1, RAYWHITE);
	DrawText("Options", options.x + 32, options.y + 32, 42, LIGHTGRAY);

}