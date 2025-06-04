#include "spaceinvader.h"

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
