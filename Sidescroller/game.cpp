#include "game.h"

#include "raylib.h"

#include "gameplay.h"
#include "menu.h"
#include "console.h"
States gamestate;
void executeGame() 
{
	initConsole();
	while (!WindowShouldClose())
	{
		updateGameplay();
	}
	CloseWindow();
}