#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
struct Bullet
{
	Rectangle rec;
	int damage;
	float speed;
	Color color;
};
extern Bullet bullet[];

void initBullets();
void updateBullets();
void drawBullets();


#endif // !BULLET_H

