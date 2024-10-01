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


#define MAX_PARTICLES 100

typedef struct Particle {
    Vector3 position;
    Color color;
    float size;
    float lifetime;
    float speed;
} Particle;

Particle particles[MAX_PARTICLES];

void InitParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        particles[i].position = (Vector3){0, 0, 0};
        particles[i].color = (Color){255, 100, 0, 255}; // Orange color
        particles[i].size = 1.0f;
        particles[i].lifetime = 0.0f;
        particles[i].speed = 0.1f;
    }
}

void UpdateParticles(float deltaTime) {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].lifetime > 0.0f) {
            particles[i].position.y += particles[i].speed * deltaTime; // Move upwards
            particles[i].lifetime -= deltaTime;
            particles[i].size *= 0.99f; // Reduce size over time
            particles[i].color.a = (unsigned char)(particles[i].lifetime * 255.0f); // Fade out
        }
        else {
            // Reset particle
            particles[i].position = (Vector3){GetRandomValue(-1, 1), 0, GetRandomValue(-1, 1)};
            particles[i].lifetime = 1.0f; // Reset lifetime
            particles[i].size = 1.0f; // Reset size
            particles[i].color = (Color){255, GetRandomValue(100, 255), 0, 255}; // Randomize color
        }
    }
}

void DrawParticles() {
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (particles[i].lifetime > 0.0f) {
            DrawCube(particles[i].position, particles[i].size, particles[i].size, particles[i].size, particles[i].color);
        }
    }
}

void draw_menu(t_program *c)
{
	float deltaTime = GetFrameTime();
    UpdateParticles(deltaTime);
    BeginMode3D((Camera){(Vector3){0, 5, 10}, (Vector3){0, 0, 0}, (Vector3){0, 1, 0}, 45.0f, 0});
    DrawParticles();
    EndMode3D();

	Rectangle play;
	play.height = 128;
	play.width = 512;
	play.x = (RES_X / 2) - (play.width / 2);
	play.y = (RES_Y / 4);
	DrawRectangleRounded(play, 0.32, 1, RAYWHITE);
	DrawText("Project_Neo", play.x + 32, play.y + 32, 42, LIGHTGRAY);

	Rectangle options;
	options.height = 128;
	options.width = 512;
	options.x = (RES_X / 2) - (options.width / 2);
	options.y = (RES_Y / 4) + 196;
	DrawRectangleRounded(options, 0.32, 1, RAYWHITE);
	DrawText("Options", options.x + 32, options.y + 32, 42, LIGHTGRAY);

}