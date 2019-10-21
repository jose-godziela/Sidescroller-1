#include "player.h"
#include "console.h"

Player player;

const int juanito = 9;

void initPlayer() 
{
	player.ship.x = 200;
	player.ship.y = 200;
	player.ship.width = 50;
	player.ship.height = 10;
	player.speed = { 350.0f,350.0f };
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
	if (playerBottomSideY(player) >= screenHeight)
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