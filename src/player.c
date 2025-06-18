#include "spaceinvader.h"

#define BULLET_W 15
#define BULLET_H 25

uint8_t bulletLimit = 15;
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
    if(!ZFB_IsKeyPressed(ZFB_Key_Space))
    {
        return;
    }
	ZFB_Entity* playerEntity = (ZFB_Entity*)playerData;
	ZFB_Entity bulletEntity =
	{
		.physics =
		{
			.position = 
                {
                    playerEntity->physics.position.x+(playerEntity->width/2)-(BULLET_W/2),
                    playerEntity->physics.position.y,
                },
			.rotation = playerEntity->physics.rotation,
			.mass = 1,
			.gravity = false,
		},
		.width = BULLET_W,
		.height = BULLET_H,
	};
    bullets[bulletCount % (bulletLimit+1)] = bulletEntity;
    bulletCount++;
    /*if (bulletCount > bulletLimit)
    {
        bulletCount = 0;
    }*/

	return;
}
