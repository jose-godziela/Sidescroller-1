#include "game.h"

#include "raylib.h"

#include "gameplay.h"
#include "menu.h"
#include "console.h"
#include "player.h"
#include "background.h"
#include "bullet.h"
#include "menu.h"
#include "gameOver.h"

States gamestate=menu;
void init();

void executeGame() 
{
	init();

	while (gamestate!=close)
	{
		switch (gamestate)
		{
		case menu:
			updateMenu();
			drawMenu();
			break;

		case gameplay:
			updateGameplay();
			drawGameplay();
			break;

		case gameOver:
			updateGameOver();
			drawGameover();
			break;
		}

	}
	CloseWindow();
}

void init()
{
	initConsole();
	initPlayer();
	initBackground();
	initBullets();
	initMenu();
	initGameOver();
}