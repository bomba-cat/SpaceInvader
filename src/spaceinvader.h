#ifndef SPACEINVADER_H
#define SPACEINVADER_H

#include "ZFB.h"

extern uint8_t bulletLimit;
extern uint8_t bulletCount;
extern ZFB_Entity* bullets;

/* Enemy */


/* Player */
void handlePlayerMovement(void* playerData);
void handlePlayerShooting(void* playerData);

/* Main */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif //!SPACEINVADER_H
