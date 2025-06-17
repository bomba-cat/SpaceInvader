#include "spaceinvader.h"

#define PLR_HEIGHT 50
#define PLR_WIDTH 50

ZFB_Entity *bullets;
ZFB_Entity *enemies;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	ZFB_Device dev =
	{
		.width = 1280,
		.height = 720,
		.title = "SpaceInvader"
	};
	ZFB_Event event = {};

	ZFB_InitFrameLimiter();
	ZFB_InitFB(&dev);
	ZFB_EventInit();
	ZFB_CreateWindow(&dev, hInstance, hPrevInstance, lpCmdLine, nShowCmd);

    bullets = malloc(sizeof(ZFB_Entity)*bulletLimit);
    enemies = malloc(sizeof(ZFB_Entity)*enemyCount);

	/* Create Entities and Rects */
	ZFB_Entity player =
	{
		.physics =
		{
			.position =
                {
                    dev.width/2-(PLR_WIDTH/2),
                    dev.height-(PLR_HEIGHT*3)
                },
			.rotation = 0,
			.gravity = false,
		},
		.width = PLR_WIDTH,
		.height = PLR_HEIGHT,
	}; ZFB_Rect playerRect = {};

	/* Frame Limiters */
	uint32_t fHandlePlayerMovement = ZFB_PushFrameLimiter((ZFB_FrameLimiter)
	{
		.frame = 0,
		.limit = 5,
		.params = (void*)&player,
		.func = handlePlayerMovement
	});
	uint32_t fHandlePlayerShooting = ZFB_PushFrameLimiter((ZFB_FrameLimiter)
	{
		.frame = 0,
		.limit = 15,
		.params = (void*)&player,
		.func = handlePlayerShooting
	});
    uint32_t fHandleEnemyMovement = ZFB_PushFrameLimiter((ZFB_FrameLimiter)
    {
        .frame = 0,
        .limit = 15,
        .params = NULL,
        .func = handleEnemyMovement
    });
    uint32_t fHandleBulletCollision = ZFB_PushFrameLimiter((ZFB_FrameLimiter)
    {
        .frame = 0,
        .limit = 0,
        .params = NULL,
        .func = handleBulletCollision
    });

    while(!ZFB_IsKeyPressed(ZFB_Key_Enter))
    {
        ZFB_WinMessage();
        ZFB_DrawBG(dev, &ZFB_Purple, NULL);
        Sleep(32);
    }
	bool quit = false;
    spawnEnemies();
	while(quit != true)
	{
		ZFB_FrameTick();
		ZFB_WinMessage();
        ZFB_PollEvent(&event);

		switch(event.type)
		{
			case ZFB_EVENT_QUIT:
				quit = true;
		}

		/* Responsible for keeping Rects and Entities on sync */
		ZFB_SyncEntity(&playerRect, player);

		/* Draw the background */
		ZFB_DrawBG(dev, &ZFB_Purple, NULL);

        /* Draw and Update bullets */
        for (int i = 0; i < bulletCount; i++)
        {
            bullets[i].physics.position.y -= 15;

            ZFB_Rect bullet = {};
            ZFB_SyncEntity(&bullet, bullets[i]);
            ZFB_DrawRect(dev, bullet, &ZFB_Yellow);
        }

        /* Draw Enemies */
        for (int i = 0; i < enemyCount; i++)
        {
            ZFB_Rect enemy = {};
            if(!enemies[i].physics.gravity)
            {
                ZFB_SyncEntity(&enemy, enemies[i]);
                ZFB_DrawRect(dev, enemy, &ZFB_Red);
            }
        }

		/* Draw Rects right here */
		ZFB_DrawRect(dev, playerRect, &ZFB_Black);

		ZFB_Present(dev);

		Sleep(16); /* ~60 fps */
	}
    free(bullets);
}
