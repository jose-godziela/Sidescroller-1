#include "gameplay.h"

#include "raylib.h"

#include "general/console.h"
#include "game_elements/player.h"
#include "general/background.h"
#include "game_elements/bullet.h"
#include "states/game.h"

void checkBulletsPlayerCollition();

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
	checkBulletsPlayerCollition();
	if (player.lifePoints<=0)
	{
		gamestate = gameOver;
	}
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

void checkBulletsPlayerCollition()
{
	for (int i = 0; i < bulletAmmount; i++)
	{
		if (CheckCollisionRecs(player.ship,bullet[i].rec)&&bullet[i].exists)
		{
			bullet[i].exists = false;
			player.lifePoints--;
		}
	}
}