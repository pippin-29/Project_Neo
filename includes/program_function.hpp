//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/includes/program_function.hpp                                  ***//
//***     Header Created: Tue Oct 01 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


#pragma once

// CLEANUP_C
void						cleanup(t_program *c);

// GAME_C
void						draw_game(t_program *c);

// INIT_C
void						init_(t_program *c);

// MAP_C
Color 						GetColorFromChar(char c);
std::vector<std::string>	read_map(std::string map, t_program *c);
void 						RenderGridIn3D(std::vector<std::string> grid, t_program *c);

// MENU_C
void 						draw_menu(t_program *c);

// MOVEMENT_C
void						update_movement(t_program *c);

// VECTOR_C
Vector3 					Vector3Scale(Vector3 v, float scale);
Vector3						Vector3Subtract(Vector3 v1, Vector3 v2);
Vector3						Vector3Add(Vector3 v1, Vector3 v2);
float 						Vector3Magnitude(Vector3 v);
Vector3						Vector3Normalize(Vector3 v1);