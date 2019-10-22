#ifndef GAME_H
#define GAME_H

enum States
{
	menu,
	gameplay,
	gameOver,
	close
};
extern States gamestate;

void executeGame();
#endif // !GAME_H
