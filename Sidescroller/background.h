#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H
#include "raylib.h"

struct Background
{
	Rectangle rec;
	Color color;
	float speed;
};
extern Background backgroundPiece[];

void initBackground();
void updateBackground();
void drawBackground();


#endif // !BACKGROUNDS_H
