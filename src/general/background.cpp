#include "background.h"
#include "general/console.h"

static const int wallPiecesAmmount = 8;
static const int floorPiecesAmmount = 2;
Background wall[wallPiecesAmmount];
Background floor[floorPiecesAmmount];

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
}

void updateBackground()
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		wall[i].rec.x -= wall[i].speed *GetFrameTime();
		keepBackgroundInScreen(wall[i]);
	}
}

void drawBackground()
{
	for (int i = 0; i < wallPiecesAmmount; i++)
	{
		DrawRectangle(wall[i].rec.x, wall[i].rec.y, wall[i].rec.width, wall[i].rec.height,wall[i].color);
	}
}

void keepBackgroundInScreen(Background &backgroundPiece)
{
	if (backgroundPiece.rec.x + backgroundPiece.rec.width <= 0)
	{
		backgroundPiece.rec.x = screenWidth;
	}
}