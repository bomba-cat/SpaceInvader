#include "spaceinvader.h"

uint32_t frameLimits = 0;
FrameLimiter* frameLimiters = NULL;

uint32_t pushFrameLimiter(FrameLimiter newFrameLimit)
{
	frameLimits++;
	frameLimiters = realloc(frameLimiters, sizeof(FrameLimiter) * frameLimits);
	frameLimiters[frameLimits-1] = newFrameLimit;
	return frameLimits; /* to keep track of the index */
}

void frameTick()
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
}
