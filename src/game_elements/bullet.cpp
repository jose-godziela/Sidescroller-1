#include "bullet.h"
#include "general/console.h"
const int bulletAmmount = 20;
Bullet bullet[bulletAmmount];
void resetBulletInScreen(Bullet &bullet);


void initBullets() 
{
	for (int i = 0; i < bulletAmmount; i++)
	{
		if (i%2==0)
		{
			bullet[i].color = RED;
			bullet[i].damage = 2;
		}
		else
		{
			bullet[i].color = ORANGE;
			bullet[i].damage = 1;
		}
		bullet[i].exists = true;
		bullet[i].rec.height = 10.0f;
		bullet[i].rec.width = 20.0f;
		bullet[i].rec.x = screenWidth + i * screenWidth/bulletAmmount;
		bullet[i].rec.y = GetRandomValue(0,screenHeight-bullet[i].rec.height);
		bullet[i].speed = 300.0f;
	}
}

void updateBullets()
{
	for (int i = 0; i < bulletAmmount; i++)
	{
		bullet[i].rec.x -= bullet[i].speed * GetFrameTime();
		resetBulletInScreen(bullet[i]);
	}
}

void drawBullets()
{
	for (int i = 0; i < bulletAmmount; i++)
	{
		if(bullet[i].exists) DrawRectangle(bullet[i].rec.x, bullet[i].rec.y, bullet[i].rec.width, bullet[i].rec.height, bullet[i].color);
	}
}

void resetBulletInScreen(Bullet &bullet)
{
	if (bullet.rec.x + bullet.rec.width <= 0)
	{
		bullet.rec.x = screenWidth;
		bullet.rec.y = GetRandomValue(0, screenHeight - bullet.rec.height);
		bullet.exists = true;
	}
}