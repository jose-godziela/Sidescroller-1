#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

struct Player
{
	Rectangle ship;
	Vector2 speed;
	int lifePoints;
};
extern Player player;

void initPlayer();
float playerTopSideY(Player player);
float playerBottomSideY(Player player);
float playerLeftSideX(Player player);
float playerRightSide(Player player);

bool playerCollidesRoof(Player player);
bool playerCollidesFloor(Player player);
bool playerCollidesLeftWall(Player player);
bool playerCollidesRightWall(Player player);

#endif // !PLAYER_H
