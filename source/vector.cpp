//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/source/vector.c                                                ***//
//***     Header Created: Thu Oct 03 2024                                                                                  ***//
//***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***//
//***     Copyright (c) 2024 Daniel Haddington                                                                             ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/program.hpp"

Vector3 Vector3Scale(Vector3 v, float scale) 
{
	return (Vector3){ v.x * scale, v.y * scale, v.z * scale };
}

Vector3	Vector3Subtract(Vector3 v1, Vector3 v2) 
{
	return (Vector3){ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
}

Vector3	Vector3Add(Vector3 v1, Vector3 v2) 
{
	return (Vector3){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
}

float Vector3Magnitude(Vector3 v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3 Vector3Normalize(Vector3 v1) {
	float magnitude = Vector3Magnitude(v1);
	if (magnitude != 0.0f) {
		return (Vector3){ v1.x / magnitude, v1.y / magnitude, v1.z / magnitude };
	}
	return v1;  // Return original vector if magnitude is zero (to avoid division by zero)
}