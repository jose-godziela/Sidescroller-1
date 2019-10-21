#include "gameplay.h"

#include "raylib.h"
#include "console.h"
#include "player.h"
#include "background.h"
#include "bullet.h"


void updateGameplay()
{
	if (IsKeyDown(KEY_RIGHT)&&!playerCollidesRightWall(player))
	{
		player.ship.x += player.speed.x *GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT)&&!playerCollidesLeftWall(player))
	{
		player.ship.x -= player.speed.x *GetFrameTime();
	}
	if (IsKeyDown(KEY_UP)&&!playerCollidesRoof(player))
	{
		player.ship.y -= player.speed.y *GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN)&&!playerCollidesFloor(player))
	{
		player.ship.y += player.speed.y *GetFrameTime();
	}
	updateBackground();
	updateBullets();
}

void drawGameplay()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	drawBackground();

	DrawRectangle(player.ship.x, player.ship.y, player.ship.width, player.ship.height, MAROON);

	DrawText("move the ship with arrow keys", 10, 10, 20, DARKGRAY);

	drawBullets();

	EndDrawing();
}