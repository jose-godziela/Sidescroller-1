#include "game.h"

#include "raylib.h"

#include "states/gameplay.h"
#include "states/menu.h"
#include "general/console.h"
#include "game_elements/player.h"
#include "general/background.h"
#include "game_elements/bullet.h"
#include "states/menu.h"
#include "states/gameOver.h"

States gamestate=menu;
void init();

void executeGame() 
{
	init();
	resize(1200,675);
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