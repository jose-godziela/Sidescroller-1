#include "background.h"
#include "general/console.h"

static const int wallPiecesAmmount = 8;
static const int floorPiecesAmmount = 16;
Background wall[wallPiecesAmmount];
Background floor[floorPiecesAmmount];
Rectangle floorBack;
void keepBackgroundInScreen(Background &backgroundPiece);

void initBackground()
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		wall[i].speed = 50.0f;
		wall[i].rec.height = screenHeight;
		wall[i].rec.width = screenWidth / (wallPiecesAmmount-1);
		wall[i].rec.y = 0.0f;
		wall[i].rec.x = i * wall[i].rec.width;
		if (i%2==0)
		{
			wall[i].color = GRAY;
		}
		else
		{
			wall[i].color = WHITE;
		}
	}
	for (int i = 0; i < floorPiecesAmmount; i++)
	{
		floor[i].speed = 250.0f;
		floor[i].rec.height = 50.0;
		floor[i].rec.width = screenWidth / (floorPiecesAmmount-1);
		floor[i].rec.y = 400.0f;
		floor[i].rec.x = i * floor[i].rec.width;
		if (i % 2 == 0)
		{
			floor[i].color = VIOLET;
		}
		else
		{
			floor[i].color = RED;
		}
	}
	floorBack.x = 0;
	floorBack.y = floor[0].rec.y;
	floorBack.width = screenWidth;
	floorBack.height = floor[0].rec.height;
}

void resizeBackground(float xMult, float yMult)
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		wall[i].rec.width *= xMult;
		wall[i].rec.height *= yMult;
		wall[i].rec.x *= xMult;
		wall[i].rec.y *= yMult;
	}
	for (int i = 0; i < floorPiecesAmmount; i++)
	{
		floor[i].rec.width *= xMult;
		floor[i].rec.height *= yMult;
		floor[i].rec.x *= xMult;
		floor[i].rec.y *= yMult;
	}
	floorBack.x *= xMult;
	floorBack.y *= yMult;
	floorBack.width *= xMult;
	floorBack.height *= yMult;
}

void updateBackground()
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		wall[i].rec.x -= wall[i].speed *GetFrameTime();
		keepBackgroundInScreen(wall[i]);
	}
	for (int i = 0; i < floorPiecesAmmount; i++)
	{
		floor[i].rec.x -= floor[i].speed *GetFrameTime();
		keepBackgroundInScreen(floor[i]);
	}
}

void drawBackground()
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		DrawRectangle(wall[i].rec.x, wall[i].rec.y, wall[i].rec.width, wall[i].rec.height,wall[i].color);
	}
	DrawRectangleRec(floorBack, VIOLET);
	for (int i = 0; i < floorPiecesAmmount; i++)
	{
		DrawRectangle(floor[i].rec.x, floor[i].rec.y, floor[i].rec.width, floor[i].rec.height, floor[i].color);
	}
}

void keepBackgroundInScreen(Background &backgroundPiece)
{
	if (backgroundPiece.rec.x + backgroundPiece.rec.width <= 0)
	{
		backgroundPiece.rec.x = screenWidth;
	}
}