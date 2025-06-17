#ifndef SPACEINVADER_H
#define SPACEINVADER_H

#include "ZFB.h"

/* Game */
extern uint8_t level;
void gameOver();
void handleNextLevel();

/* Bullets */
extern uint8_t bulletLimit;
extern uint8_t bulletCount;
extern ZFB_Entity *bullets;

/* Enemy */
extern uint8_t enemyCount;
extern ZFB_Entity *enemies;
void spawnEnemies();
void handleEnemyMovement(void*);
void handleBulletCollision(void* bulletData);
void handlePlayerCollision(void* playerData);

/* Player */
void handlePlayerMovement(void* playerData);
void handlePlayerShooting(void* playerData);

/* Main */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

#endif //!SPACEINVADER_H
