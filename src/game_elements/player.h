#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"


struct FullTexture
{
	Texture actualTex;
	int xOffset;
	int yOffset;
	Color color;
	float swappingTime;
	int frame;
	Texture tex1;
	Texture tex2;
};

struct Player
{
	Rectangle ship;
	Vector2 speed;
	int lifePoints;
	FullTexture texture;
};

extern Player player;

void initPlayer();
void resizePlayer(float xMult, float yMult);

float playerTopSideY(Player player);
float playerBottomSideY(Player player);
float playerLeftSideX(Player player);
float playerRightSide(Player player);

bool playerCollidesRoof(Player player);
bool playerCollidesFloor(Player player);
bool playerCollidesLeftWall(Player player);
bool playerCollidesRightWall(Player player);
int texturePos(float originalPos, int texOffset);
void updatePlayerSprite();
#endif //PLAYER_H
