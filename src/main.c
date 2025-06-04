#include "spaceinvader.h"

#define PLR_HEIGHT 50
#define PLR_WIDTH 50

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
		frameTick();
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
