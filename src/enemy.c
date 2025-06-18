#include "spaceinvader.h"

#define ENEMY_WIDTH 50
#define ENEMY_HEIGHT 50
#define ENEMY_MARGIN 15

uint8_t enemyCount = 5;

void handleEnemyMovement(void*)
{
    for (int i = 0; i < enemyCount; i++)
    {
        if (enemies[i].physics.gravity)
        {
            return;
        }
        
        enemies[i].physics.position.x += ENEMY_WIDTH+ENEMY_MARGIN;
        if (enemies[i].physics.position.x >= 1280-ENEMY_WIDTH)
        {
            enemies[i].physics.position.x = ENEMY_MARGIN;
            enemies[i].physics.position.y += ENEMY_HEIGHT + ENEMY_MARGIN;
        }
    }
}

void handleBulletCollision(void*)
{

    for (int i = 0; i < enemyCount; i++)
    {
        for(int j = 0; j < bulletCount; j++)
        {
            if(ZFB_CheckCollision(bullets[j], enemies[i]))
            {
                enemies[i].physics.gravity = true;
                enemies[i].physics.position.x = -ENEMY_WIDTH;


                bullets[j].physics.gravity = true;
                bullets[j].physics.position.x = -ENEMY_WIDTH;
            }
        }
    }
}

void spawnEnemies()
{
    for (int i = 0; i < enemyCount; i++)
    {
        ZFB_Entity enemy =
            {
                .physics =
                {
                    .position =
                    {
                        (i * ENEMY_WIDTH) + (i * ENEMY_MARGIN),
                        ENEMY_MARGIN,
                    },
                    .rotation = 0,
                    .mass = 1,
                    .gravity = false,
                },
                .width = ENEMY_WIDTH,
                .height = ENEMY_HEIGHT,
            };
        enemies[i] = enemy;
    }
}
