#include "menu.h"
#include "game.h"
Button play;
Button exit;
static const Color notSelectedColor = YELLOW;
static const Color selectedColor = WHITE;
static int opciones=1;

void initMenu() 
{
	play.button.height = 100;
	play.button.width = 200;
	play.button.x = 300;
	play.button.y = 100;
	play.color = YELLOW;
	play.textPosition.x = 350.0f;
	play.textPosition.y = 120.0f;
	play.textColor = BLACK;
	play.textFont = 40;
	exit.button.height = 100;
	exit.button.width = 200;
	exit.button.x = 300;
	exit.button.y = 250;
	exit.color = YELLOW;
	exit.textPosition.x = 350.0f;
	exit.textPosition.y = 260.0f;
	exit.textColor = BLACK;
	exit.textFont = 40;
}

void updateMenu()
{
	if (IsKeyPressed(KEY_UP)&&opciones>1)
	{
		opciones--;
	}
	if (IsKeyPressed(KEY_DOWN)&&opciones<2)
	{
		opciones++;
	}
	if (opciones ==1)
	{
		play.color = selectedColor;
		exit.color = notSelectedColor;
		if (IsKeyPressed(KEY_ENTER))
		{
			gamestate = gameplay;
		}
	}
	if (opciones ==2)
	{
		play.color = notSelectedColor;
		exit.color = selectedColor;
		if (IsKeyPressed(KEY_ENTER))
		{
			gamestate = close;
		}
	}
}

void drawMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawRectangle(play.button.x, play.button.y, play.button.width, play.button.height, play.color);
	DrawRectangle(exit.button.x, exit.button.y, exit.button.width, exit.button.height, exit.color);
	DrawText("Play", play.textPosition.x, play.textPosition.y, play.textFont, play.textColor);
	DrawText("Exit", exit.textPosition.x, exit.textPosition.y, exit.textFont, exit.textColor);
	EndDrawing();
}