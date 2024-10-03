//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/movement.cpp                                            ***//
//***     Header Created: Thu Oct 03 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/program.hpp"


void update_movement(t_program *c)
{
	Vector3 forward = Vector3Subtract(c->camera.target, c->camera.position);
	forward.y = 0.0f;
	forward = Vector3Normalize(forward);
	Vector3 right = { forward.z, 0.0f, -forward.x }; 
	if (IsKeyDown(KEY_W)) c->camera.position = Vector3Add(c->camera.position, Vector3Scale(forward, 0.2f));
	if (IsKeyDown(KEY_S)) c->camera.position = Vector3Subtract(c->camera.position, Vector3Scale(forward, 0.2f));
	if (IsKeyDown(KEY_A)) c->camera.position = Vector3Add(c->camera.position, Vector3Scale(right, 0.2f));
	if (IsKeyDown(KEY_D)) c->camera.position = Vector3Subtract(c->camera.position, Vector3Scale(right, 0.2f));
	c->camera.target = Vector3Add(c->camera.position, forward);
}
