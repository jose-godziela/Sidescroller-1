#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"

extern const int bulletAmmount;

struct Bullet
{
	Rectangle rec;
	int damage;
	float speed;
	Color color;
	bool exists;
};
extern Bullet bullet[];

void initBullets();
void updateBullets();
void drawBullets();


#endif // !BULLET_H

