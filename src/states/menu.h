#ifndef MENU_H
#define MENU_H

#include "raylib.h"

struct Button
{
	Rectangle button;
	Color color;
	Vector2 textPosition;
	Color textColor;
	int textFont;
};
extern Button play;
extern Button exit;

void initMenu();
void updateMenu();
void drawMenu();

#endif // !MENU_H
