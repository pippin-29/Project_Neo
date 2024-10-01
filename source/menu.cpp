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
	c->mousex = GetMouseX();
	c->mousey = GetMouseY();

	// me
	Rectangle play;
	play.height = 128;
	play.width = 512;
	play.x = (RES_X / 2) - (play.width / 2);
	play.y = (RES_Y / 4);
	
	if (c->mousex > play.x && c->mousex < (play.x + play.width)
		&& c->mousey > play.y && c->mousey < (play.y + play.height))
	{
		DrawRectangleRounded(play, 0.64, 1, PURPLE);
		DrawText("Project_Neo", play.x + 32, play.y + 32, 42, LIGHTGRAY);
	}
	else
	{
		DrawRectangleRounded(play, 0.32, 1, RAYWHITE);
		DrawText("Project_Neo", play.x + 32, play.y + 32, 42, LIGHTGRAY);
	}
		

	Rectangle options;
	options.height = 128;
	options.width = 512;
	options.x = (RES_X / 2) - (options.width / 2);
	options.y = (RES_Y / 4) + 196;
	if (c->mousex > options.x && c->mousex < (options.x + options.width)
		&& c->mousey > options.y && c->mousey < (options.y + options.height))
	{
		DrawRectangleRounded(options, 0.64, 1, PURPLE);
		DrawText("Options", options.x + 32, options.y + 32, 42, LIGHTGRAY);
	}
	else
	{
		DrawRectangleRounded(options, 0.32, 1, RAYWHITE);
		DrawText("Options", options.x + 32, options.y + 32, 42, LIGHTGRAY);
	}


}