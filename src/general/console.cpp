#include "console.h"

#include "raylib.h"

int screenWidth = 800;
int screenHeight = 450;

void initConsole()
{
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
}