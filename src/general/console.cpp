#include "console.h"

#include "raylib.h"

#include "game_elements/bullet.h"
#include "game_elements/player.h"
#include "states/menu.h"
#include "general/background.h"
#include "states/gameOver.h"

int screenWidth = 800;
int screenHeight = 450;
static float newSizeMultiplierX;
static float newSizeMultiplierY;

void initConsole()
{
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
}

void resize(int newWidth, int newHeight)
{
	newSizeMultiplierX = static_cast<float>(newWidth) / screenWidth;
	newSizeMultiplierY = static_cast<float>(newHeight) / screenHeight;
	SetWindowSize(newWidth, newHeight);
	screenWidth = newWidth;
	screenHeight = newHeight;
	resizeBackground(newSizeMultiplierX,newSizeMultiplierY);
	resizeBullets(newSizeMultiplierX, newSizeMultiplierY);
	resizePlayer(newSizeMultiplierX, newSizeMultiplierY);
	resizeMenu(newSizeMultiplierX, newSizeMultiplierY);
	resizeGameOver(newSizeMultiplierX, newSizeMultiplierY);
}