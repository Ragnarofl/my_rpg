#pragma once
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

typedef struct s_info
{
    sfVector2f speed;
    float life;
    sfColor color;
}t_info;

typedef struct s_partBuffer
{
    sfVertex *vertex;
    t_info *info;
    uint size;
}partBuffer;

void create_particles(sfVector2f, partBuffer *, sfColor);
partBuffer *newPartBuffer(int);
void updatePartBuffer(partBuffer *);
void drawPartBufer(partBuffer *,sfRenderWindow *);
