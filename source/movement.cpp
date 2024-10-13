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
    const float mouseSensitivity = 0.003f;

    // Get mouse movement delta
    Vector2 mouseDelta = GetMouseDelta();
    HideCursor();  // Hide the mouse cursor

    static float yaw = 0.0f;
    static float pitch = 0.0f;

    yaw -= mouseDelta.x * mouseSensitivity;
    pitch -= mouseDelta.y * mouseSensitivity;

    // Clamp pitch to avoid camera flipping vertically
    if (pitch > 89.0f * DEG2RAD) pitch = 89.0f * DEG2RAD;
    if (pitch < -89.0f * DEG2RAD) pitch = -89.0f * DEG2RAD;

    // Forward vector based on yaw and pitch
    Vector3 forward = {
        cosf(pitch) * sinf(yaw),   // X component
        sinf(pitch),               // Y component
        cosf(pitch) * cosf(yaw)    // Z component
    };

    forward = Vector3Normalize(forward);

    // Right vector for strafing (perpendicular to forward)
    Vector3 right = { forward.z, 0.0f, -forward.x };

    static float initialY = 0.0f;
    if (initialY == 0.0f)
    {
        initialY = c->camera.position.y;
    }
	Vector3 oldPosition = c->camera.position;
    Vector3 newPosition = c->camera.position;

    // Process input for movement (forward/backward and strafing)
    if (IsKeyDown(KEY_W)) newPosition = Vector3Add(newPosition, Vector3Scale(forward, 0.15f));
    if (IsKeyDown(KEY_S)) newPosition = Vector3Subtract(newPosition, Vector3Scale(forward, 0.15f));
    if (IsKeyDown(KEY_A)) newPosition = Vector3Add(newPosition, Vector3Scale(right, 0.15f));
    if (IsKeyDown(KEY_D)) newPosition = Vector3Subtract(newPosition, Vector3Scale(right, 0.15f));


    // Check for collisions before updating position
    if (!CheckCollisionWithGrid(newPosition, c->grid)) {
        c->camera.position = newPosition;  // Update position only if no collision
    }

    c->camera.position.y = initialY;  // Maintain Y position to avoid floating

    // Update camera target based on new forward vector
    c->camera.target = Vector3Add(c->camera.position, forward);

    // Keep mouse within the window to prevent it from leaving
    if (c->mousex >= RES_X - 128 || c->mousex <= 128) SetMousePosition(RES_X / 2, c->mousey);
    if (c->mousey >= RES_Y - 128 || c->mousey <= 128) SetMousePosition(c->mousex, RES_Y / 2);
}

bool CheckCollisionWithGrid(Vector3 playerPos, std::vector<std::string> grid) {
    int gridX = (int)(playerPos.x / CUBE_SIZE);
    int gridZ = (int)(playerPos.z / CUBE_SIZE);

    // Ensure the grid coordinates are within bounds
    if (gridX < 0 || gridZ < 0 || gridZ >= grid.size() || gridX >= grid[0].size())
        return true;  // Treat out of bounds as a collision

    char cell = grid[gridZ][gridX];

    // Collide with specific wall characters (like '-')
    if (cell == '-') {
        return true;  // Collision detected
    }

    return false;  // No collision
}
