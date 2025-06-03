#ifndef SPACEINVADER_H
#define SPACEINVADER_H

#include "ZFB.h"

typedef struct
{
	uint32_t frame;
	uint32_t limit;
	void* params;
	void (*func)(void* params);
} FrameLimiter;

extern uint32_t frameLimits;
extern FrameLimiter* frameLimiters;

void handlePlayerMovement(void* playerData);

uint32_t pushFrameLimiter(FrameLimiter newFrameLimit);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif //!SPACEINVADER_H
