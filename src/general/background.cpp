#include "background.h"
#include "general/console.h"

static const int piecesAmmount = 8;
Background backgroundPiece[piecesAmmount];

void keepBackgroundInScreen(Background &backgroundPiece);

void initBackground()
{
	for (int i = 0; i < piecesAmmount; i++)
	{
		backgroundPiece[i].speed = 50.0f;
		backgroundPiece[i].rec.height = screenHeight;
		backgroundPiece[i].rec.width = screenWidth / (piecesAmmount-1);
		backgroundPiece[i].rec.y = 0.0f;
		backgroundPiece[i].rec.x = i * backgroundPiece[i].rec.width;
		if (i%2==0)
		{
			backgroundPiece[i].color = GRAY;
		}
		else
		{
			backgroundPiece[i].color = WHITE;
		}
	}
}

void updateBackground()
{
	for (int i = 0; i < piecesAmmount; i++)
	{
		backgroundPiece[i].rec.x -= backgroundPiece[i].speed *GetFrameTime();
		keepBackgroundInScreen(backgroundPiece[i]);
	}
}

void drawBackground()
{
	for (int i = 0; i < piecesAmmount; i++)
	{
		DrawRectangle(backgroundPiece[i].rec.x, backgroundPiece[i].rec.y, backgroundPiece[i].rec.width, backgroundPiece[i].rec.height,backgroundPiece[i].color);
	}
}

void keepBackgroundInScreen(Background &backgroundPiece)
{
	if (backgroundPiece.rec.x + backgroundPiece.rec.width <= 0)
	{
		backgroundPiece.rec.x = screenWidth;
	}
}