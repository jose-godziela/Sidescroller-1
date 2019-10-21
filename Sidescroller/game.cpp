#include "game.h"

#include "raylib.h"

#include "gameplay.h"
#include "menu.h"
#include "console.h"
#include "player.h"
#include "background.h"
#include "bullet.h"

States gamestate;
void executeGame() 
{
	initConsole();
	initPlayer();
	initBackground();
	initBullets();
	while (!WindowShouldClose())
	{
		updateGameplay();
		drawGameplay();
	}
	
	CloseWindow();
}