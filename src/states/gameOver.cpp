#include "gameOver.h"

#include "raylib.h"

#include "states/game.h"

static Vector2 loseTextPos;
static int loseTextFont;

void initGameOver()
{
	loseTextPos.x = 40.0f;
	loseTextPos.y = 200.0f;
	loseTextFont = 40;
}
void updateGameOver()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		gamestate = close;
	}
}
void drawGameover()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("YOU LOSE... press enter to close", loseTextPos.x, loseTextPos.y, loseTextFont, WHITE);
	EndDrawing();
}