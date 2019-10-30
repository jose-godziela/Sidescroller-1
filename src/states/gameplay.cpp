#include "gameplay.h"

#include <ctime>

#include "raylib.h"

#include "general/console.h"
#include "game_elements/player.h"
#include "general/background.h"
#include "game_elements/bullet.h"
#include "states/game.h"

float timer;
short foo;
void checkBulletsPlayerCollition();
void updateTimer();

void updateGameplay()
{
	updateTimer();
	updatePlayerSprite();
	if (IsKeyDown(KEY_RIGHT) && !playerCollidesRightWall(player))
	{
		player.ship.x += player.speed.x *GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT) && !playerCollidesLeftWall(player))
	{
		player.ship.x -= player.speed.x *GetFrameTime();
	}
	if (IsKeyDown(KEY_UP) && !playerCollidesRoof(player))
	{
		player.ship.y -= player.speed.y *GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN) && !playerCollidesFloor(player))
	{
		player.ship.y += player.speed.y *GetFrameTime();
	}
	if (IsKeyPressed(KEY_SPACE))
	{
		for (int i = 0; i < max_bullets; i++)
		{
			while(player.bullet[i].exists)i++;
			if (i >= max_bullets) break;
			player.bullet[i].exists = true;
			player.bullet[i].rec.y = player.ship.y;
			if (!player.bullet[i + 1].exists) break;
		}
	}
	updateBackground();
	updateBullets();
	updatePlayerBullets();
	checkBulletsPlayerCollition();
	if (player.lifePoints <= 0)
	{
		resetPlayer();
		resetBullets();
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

	drawPlayerBullets();

	DrawText(TextFormat("Lives Left: %i", player.lifePoints), 10, 10, 20, DARKGRAY);

	EndDrawing();
}

void checkBulletsPlayerCollition()
{
	for (int i = 0; i < bulletAmmount; i++)
	{
		if (CheckCollisionRecs(player.ship, bullet[i].rec) && bullet[i].exists)
		{
			bullet[i].exists = false;
			player.lifePoints--;
		}
		if (CheckCollisionRecs(player.bullet[i].rec, bullet[i].rec) && player.bullet[i].exists && bullet[i].exists)
		{
			player.bullet[i].exists = false;
			bullet[i].exists = false;
		}
	}
}

void updateTimer()
{
	timer = static_cast<float>(clock() / 1000);
}