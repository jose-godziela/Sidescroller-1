#include "gameplay.h"

#include <ctime>

#include "raylib.h"

#include "general/console.h"
#include "game_elements/player.h"
#include "general/background.h"
#include "game_elements/bullet.h"
#include "states/game.h"

float timer;

void checkBulletsPlayerCollition();
void updateTimer();

void updateGameplay()
{
	updateTimer();
	updatePlayerSprite();
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

	//DrawRectangle(player.ship.x, player.ship.y, player.ship.width, player.ship.height, MAROON);

	DrawTexture(player.texture.actualTex, texturePos(player.ship.x, player.texture.xOffset), texturePos(player.ship.y, player.texture.yOffset), player.texture.color);

	drawBullets();

	DrawText(TextFormat("Lives Left: %i",player.lifePoints), 10, 10, 20, DARKGRAY);

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

void updateTimer() 
{
	timer = static_cast<float>(clock() / 1000);
}