//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/main.cpp                                                ***//
//***     Header Created: Tue Oct 01 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/program.hpp"

int main() {
	t_program *c = new t_program;
	*c = t_program{0};
	init_(c);

    // Main game loop
    while (!WindowShouldClose()) 
	{
        c->mousex = GetMouseX();
		c->mousey = GetMouseY();
		if (c->menuToggle == true)
		{
			draw_menu(c);
		}
		else if (c->menuToggle == false)
		{
			// Update position in game
			if (IsKeyDown(KEY_W)) c->camera.position.z -= 0.1f;
			if (IsKeyDown(KEY_S)) c->camera.position.z += 0.1f;
			if (IsKeyDown(KEY_A)) c->camera.position.x -= 0.1f;
			if (IsKeyDown(KEY_D)) c->camera.position.x += 0.1f;
			draw_game(c);
		}
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
	cleanup(c);
    return 0;
}
