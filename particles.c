/*
** EPITECH PROJECT, 2018
** particles.c
** File description:
** particles
*/

#include "include/particles.h"

static uint newPart(partBuffer *this)
{
    for (uint id = this->size - 1; id != 0; id -= 1)
        if (this->info[id].life <= 0)
            return id;
    return ((uint)(-1));
}

void updatePartBuffer(partBuffer *buffer)
{
    for (uint id = 0; id < buffer->size; id += 1) {
        if (buffer->info[id].life <= 0)
            continue;
        buffer->info[id].life -= 1/1200.;
        if (buffer->info[id].life <= 0) {
            memset(buffer->vertex + (id * 4), 0, sizeof(sfVertex) * 4);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            buffer->vertex[(id * 4) + i].position.x\
             += buffer->info[id].speed.x;
            buffer->vertex[(id * 4) + i].position.y\
             += buffer->info[id].speed.y;
            buffer->vertex[(id * 4) + i].color.a *= buffer->info[id].life;
        }
    }
}

partBuffer *newPartBuffer(int size)
{
    partBuffer *buffer;
    const size_t size_m = (sizeof(partBuffer) + sizeof(sfVertex)\
     * size * 4 + sizeof(t_info) * size);
    void *ptn = malloc(size_m);

    if (ptn == NULL)
        return (NULL);
    memset(ptn, 0, size_m);
    buffer = (partBuffer *)(ptn);
    buffer->size = size;
    buffer->vertex = (sfVertex *)(ptn + sizeof(partBuffer));
    buffer->info = (t_info *)(buffer->vertex + (size * 4));
    return (buffer);
}

void setPart(partBuffer *buffer, uint id, sfVector2f pos, sfColor color)
{
    if (id >= buffer->size)
        return;
    buffer->info->color = color;
    buffer->vertex[id * 4].position = (sfVector2f){pos.x + 0, pos.y + 0};
    buffer->vertex[(id * 4) + 1].position = (sfVector2f){pos.x + 2, pos.y + 0};
    buffer->vertex[(id * 4) + 2].position =\
     (sfVector2f){pos.x + 2, pos.y + 2};
    buffer->vertex[(id * 4) + 3].position = (sfVector2f){pos.x + 0, pos.y + 2};
    buffer->vertex[(id * 4)].color = color;
    buffer->vertex[(id * 4) + 1].color = color;
    buffer->vertex[(id * 4) + 2].color = color;
    buffer->vertex[(id * 4) + 3].color = color;
    buffer->info[id].speed.x = ((float)(rand() % 255) / 255);
    if (rand() % 2 == 0)
        buffer->info[id].speed.x *= -1;
    buffer->info[id].speed.y = ((float)(rand() % 255) / 255);
    if (rand() % 2 == 0)
        buffer->info[id].speed.y *= -1;
    buffer->info[id].life = 1.;
}

void create_particles(sfVector2f pos, partBuffer *buffer, sfColor color)
{
    uint id = 0;

    updatePartBuffer(buffer);
    for (int i = 0; i < 110; i += 1) {
        id = newPart(buffer);
        if (id == (uint)(-1))
            break;
        setPart(buffer, id, pos, color);
    }
}
