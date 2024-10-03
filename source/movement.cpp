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
    // Mouse sensitivity (tweak this value to change the speed of camera rotation)
    const float mouseSensitivity = 0.003f;

    // Get mouse movement delta
    Vector2 mouseDelta = GetMouseDelta();

	HideCursor(); //
    // Adjust yaw and pitch based on mouse movement
    static float yaw = 0.0f;    // Horizontal rotation
    static float pitch = 0.0f;  // Vertical rotation
    
    yaw -= mouseDelta.x * mouseSensitivity;
    pitch -= mouseDelta.y * mouseSensitivity; // Invert Y-axis for natural feel

    // Clamp pitch to avoid flipping the camera vertically
    if (pitch > 89.0f * DEG2RAD) pitch = 89.0f * DEG2RAD;
    if (pitch < -89.0f * DEG2RAD) pitch = -89.0f * DEG2RAD;

    // Calculate the new forward vector using yaw and pitch
    Vector3 forward = {
        cosf(pitch) * sinf(yaw),  // X component
        sinf(pitch),              // Y component
        cosf(pitch) * cosf(yaw)   // Z component
    };

    // Normalize the forward vector
    forward = Vector3Normalize(forward);

    // Calculate the right vector for strafing
    Vector3 right = { forward.z, 0.0f, -forward.x };

    // Keyboard movement controls (WASD)
    if (IsKeyDown(KEY_W)) c->camera.position = Vector3Add(c->camera.position, Vector3Scale(forward, 0.2f));
    if (IsKeyDown(KEY_S)) c->camera.position = Vector3Subtract(c->camera.position, Vector3Scale(forward, 0.2f));
    if (IsKeyDown(KEY_A)) c->camera.position = Vector3Add(c->camera.position, Vector3Scale(right, 0.2f));
    if (IsKeyDown(KEY_D)) c->camera.position = Vector3Subtract(c->camera.position, Vector3Scale(right, 0.2f));

    // Update camera target based on new forward vector (relative to position)
    c->camera.target = Vector3Add(c->camera.position, forward);


	// Keep Mouse in window // sorta
	if (c->mousex >= RES_X - 128 || c->mousex <= 128) SetMousePosition(RES_X / 2, c->mousey);
	if (c->mousey >= RES_Y - 128 || c->mousey <= 128) SetMousePosition(c->mousey, RES_Y / 2);
}



