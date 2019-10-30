#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#include "bullet.h"
#include "general/console.h"
#include "general/background.h"
#include "states/gameplay.h"


const int max_bullets = 10;

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
	Vector2 posInicial;
	Rectangle ship;
	Vector2 speed;
	int lifePoints;
	FullTexture texture;
	Bullet bullet[max_bullets];
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
void drawPlayerBullets();
void updatePlayerBullets();
void resetPlayer();

#endif //PLAYER_H
