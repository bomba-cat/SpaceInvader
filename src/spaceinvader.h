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

/* Player */
void handlePlayerMovement(void* playerData);

/* FrameLimiter */
uint32_t pushFrameLimiter(FrameLimiter newFrameLimit);
void frameTick();

/* Main */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif //!SPACEINVADER_H
