#include "spaceinvader.h"

#define BULLET_W 5
#define BULLET_H 10

uint8_t bulletLimit = 50;
uint8_t bulletCount = 0;

void handlePlayerMovement(void* playerData)
{
	ZFB_Entity* player = (ZFB_Entity*)playerData;

	if(ZFB_IsKeyPressed(VK_LEFT))
	{
		player->physics.position.x -= player->width;
	}
	if(ZFB_IsKeyPressed(VK_RIGHT))
	{
		player->physics.position.x += player->width;
	}
	if(ZFB_IsKeyPressed(VK_UP))
	{
		player->physics.position.y -= player->height;
	}
	if(ZFB_IsKeyPressed(VK_DOWN))
	{
		player->physics.position.y += player->height;
	}

	return;
}

void handlePlayerShooting(void* playerData)
{
	ZFB_Entity* playerEntity = (ZFB_Entity*)playerData;
	ZFB_Entity bulletEntity =
	{
		.physics =
		{
			.position = playerEntity->physics.position,
			.rotation = playerEntity->physics.rotation,
			.mass = 1,
			.gravity = false,
		},
		.width = BULLET_W,
		.height = BULLET_H,
	};
    bulletCount++;
    bullets = realloc(bullets, sizeof(ZFB_Entity)*bulletCount);
    bullets[bulletCount-1];

	return;
}
