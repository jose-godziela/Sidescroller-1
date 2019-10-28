#include "player.h"

#include "general/console.h"
#include "general/background.h"

Player player;

const int juanito = 9;

void initPlayer() 
{
	player.ship.x = 200;
	player.ship.y = 200;
	player.ship.width = 50;
	player.ship.height = 10;
	player.speed = { 350.0f,350.0f };
	player.lifePoints = 5;
}

void resizePlayer(float xMult, float yMult)
{
	player.ship.width *= xMult;
	player.ship.height *= yMult;
	player.ship.x *= xMult;
	player.ship.y *= yMult;
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