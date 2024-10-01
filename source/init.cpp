//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/init.cpp                                                ***//
//***     Header Created: Tue Oct 01 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


#include "../includes/program.hpp"

void	init_(t_program *c)
{
    InitWindow(RES_X, RES_Y, "Project_Neo");
	SetTargetFPS(60);

	c->menuToggle = true;
	c->mousex = 0;
	c->mousey = 0;


	c->camera = {0};

	c->camera.position = (Vector3){0.0f, 2.0f, 4.0f};
	c->camera.target = (Vector3){0.0f, 2.0f, 0.0f};
	c->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
	c->camera.fovy = 60.0f;
	c->camera.projection = CAMERA_PERSPECTIVE;


}