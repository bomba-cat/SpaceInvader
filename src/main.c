#include "spaceinvader.h"

#define PLR_HEIGHT 50
#define PLR_WIDTH 50

uint32_t frameLimits = 0;
FrameLimiter* frameLimiters = NULL;

uint32_t pushFrameLimiter(FrameLimiter newFrameLimit)
{
	frameLimits++;
	frameLimiters = realloc(frameLimiters, sizeof(FrameLimiter) * frameLimits);
	frameLimiters[frameLimits-1] = newFrameLimit;
	return frameLimits; /* to keep track of the index */
}

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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	ZFB_Device dev =
	{
		.width = 1280,
		.height = 720,
		.title = "SpaceInvader"
	};
	ZFB_Event event = {};

	ZFB_InitFB(&dev);
	ZFB_EventInit();
	ZFB_CreateWindow(&dev, hInstance, hPrevInstance, lpCmdLine, nShowCmd);

	/* Create Entities and Rects */
	ZFB_Entity player =
	{
		.physics =
		{
			.position = { dev.width/2-(PLR_WIDTH/2), dev.height-(PLR_HEIGHT*3) },
			.rotation = 0,
			.gravity = false,
		},
		.width = PLR_WIDTH,
		.height = PLR_HEIGHT,
	}; ZFB_Rect playerRect = {};

	/* Frame Limiters */
	frameLimiters = malloc(sizeof(FrameLimiter) * frameLimits);
	uint32_t fHandlePlayerMovement = pushFrameLimiter((FrameLimiter)
	{
			.frame = 0,
			.limit = 5,
			.params = (void*)&player,
			.func = handlePlayerMovement
	});

	bool quit = false;
	MSG msg = {};
	while(msg.message != WM_QUIT && quit != true)
	{
		/* Increment all frames from the FrameLimiters */
		for(int i = 0; i < frameLimits; i++)
		{
			if(frameLimiters[i].frame < frameLimiters[i].limit)
			{
				frameLimiters[i].frame++;	
			} else
			{
				frameLimiters[i].func(frameLimiters[i].params);
				frameLimiters[i].frame = 0;
			}
		}

		ZFB_WinMessage(&msg);

		switch(event.type)
		{
			case ZFB_EVENT_QUIT:
				quit = true;
		}

		/* Responsible for keeping Rects and Entities on sync */
		ZFB_SyncEntity(&playerRect, player);

		/* Draw the background */
		ZFB_DrawBG(dev, &ZFB_Purple, NULL);

		/* Draw all Rects right here */
		ZFB_DrawRect(dev, playerRect, &ZFB_Black);

		ZFB_Present(dev);

		Sleep(16); /* ~60 fps */
	}
}
