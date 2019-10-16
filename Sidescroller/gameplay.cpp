#include "gameplay.h"

#include "raylib.h"
#include "console.h"


void updateGameplay()
{
	if (IsKeyDown(KEY_RIGHT)) ship.x += 100.0f*GetFrameTime();
	if (IsKeyDown(KEY_LEFT)) ship.x -= 100.0f*GetFrameTime();
	if (IsKeyDown(KEY_UP)) ship.y -= 100.0f*GetFrameTime();
	if (IsKeyDown(KEY_DOWN)) ship.y += 100.0f*GetFrameTime();

	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

	DrawCircleV(ship, 50, MAROON);

	EndDrawing();
}