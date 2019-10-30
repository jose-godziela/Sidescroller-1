#include "player.h"

#include "general/console.h"
#include "general/background.h"
#include "states/gameplay.h"

Player player;
static float oldTimer;

void initPlayer() 
{
	player.ship.x = 200;
	player.ship.y = 200;
	player.ship.width = 50;
	player.ship.height = 20;
	player.speed = { 350.0f,350.0f };
	player.lifePoints = 5;
	player.texture.tex1= LoadTexture("images/Evil-flying-dude-1.png");
	player.texture.tex2= LoadTexture("images/Evil-flying-dude-2.png");
	player.texture.tex1.height = 55;
	player.texture.tex1.width = 70;
	player.texture.tex2.height = 55;
	player.texture.tex2.width = 70;
	player.texture.xOffset = -10;
	player.texture.actualTex = player.texture.tex1;
	player.texture.frame = 1;
	player.texture.yOffset = -18;
	player.texture.color = WHITE;
	player.texture.swappingTime = 0.5f;
	oldTimer = timer;
}

void resizePlayer(float xMult, float yMult)
{
	player.ship.width *= xMult;
	player.ship.height *= yMult;
	player.ship.x *= xMult;
	player.ship.y *= yMult;
	player.texture.tex1.width *= xMult;
	player.texture.tex1.height *= yMult;
	player.texture.tex2.width *= xMult;
	player.texture.tex2.height *= yMult;
	player.texture.xOffset *= xMult;
	player.texture.yOffset *= yMult;
}

float playerTopSideY(Player player)
{
	return player.ship.y;
}

float playerBottomSideY(Player player)
{
	return player.ship.y + player.ship.height;
}

float playerLeftSideX(Player player)
{
	return player.ship.x;
}

float playerRightSide(Player player)
{
	return player.ship.x + player.ship.width;
}


bool playerCollidesRoof(Player player)
{
	if (playerTopSideY(player)<=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool playerCollidesFloor(Player player)
{
	if (playerBottomSideY(player) >= floor[0].rec.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool playerCollidesLeftWall(Player player)
{
	if (playerLeftSideX(player) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool playerCollidesRightWall(Player player)
{
	if (playerRightSide(player) >= screenWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int texturePos(float originalPos, int texOffset) 
{
	return originalPos + texOffset;
}
 
void updatePlayerSprite()
{
	if (timer >= oldTimer + player.texture.swappingTime )
	{
		switch (player.texture.frame)
		{
		case 1:
			player.texture.frame = 2;
			player.texture.actualTex = player.texture.tex2;
			break;
		case 2:
			player.texture.frame = 1;
			player.texture.actualTex = player.texture.tex1;
			break;
		}
		oldTimer = timer;
	}
}
