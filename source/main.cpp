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
    // Initialization
    InitWindow(RES_X, RES_Y, "Project_Neo");
	SetTargetFPS(60);
	t_program *c = new t_program;
	*c = t_program{0};
	init_(c);

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK);
		if (c->menuToggle == true)
		{
			draw_menu(c);
		}
		else if (c->menuToggle == false)
		{
			draw_game(c);
		}
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
	cleanup(c);
    return 0;
}
