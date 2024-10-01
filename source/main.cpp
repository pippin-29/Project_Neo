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
    InitWindow(800, 600, "Project_Neo");
	
	t_program *c = new t_program;
	*c = t_program{0};
	init_(c);

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw some text
        DrawText("Welcome to Project_Neo", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
	cleanup(c);
    return 0;
}
