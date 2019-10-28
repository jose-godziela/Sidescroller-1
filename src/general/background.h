#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H
#include "raylib.h"

struct Background
{
	Rectangle rec;
	Color color;
	float speed;
	Texture tex;
};
extern Background wall[];
extern Background floor[];


void initBackground();
void resizeBackground(float xMult, float yMult);
void updateBackground();
void drawBackground();

#endif //BACKGROUNDS_H
