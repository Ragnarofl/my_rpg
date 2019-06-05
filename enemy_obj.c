/*
** EPITECH PROJECT, 2019
** Game objects related function for csfml project
** File description:
** object
*/

#include "include/object.h"

enemy_t *set_enemy(sfVector2f position)
{
    enemy_t *new_enemy = malloc(sizeof(enemy_t));
    char texture_path[256] = \
    "assets/Undead/SHEETS/Undead_all_sheet.png";
    VEC origin = {24, 37};
    sfVector2i size = {32, 27};
    VEC scale = {3, 3};

    new_enemy->rect_tab = get_rect_tab();
    new_enemy->speed = 3;
    new_enemy->hp = 100;
    new_enemy->dexterity = 0.07;
    new_enemy->dir = 1;
    new_enemy->scale = scale;
    new_enemy->state = AVAIBLE;
    new_enemy->position = position;
    new_enemy->origin = origin;
    new_enemy->size = size;
    new_enemy->focus_zone = set_zone(80, new_enemy->position);
    new_enemy->hit_zone = set_zone(10, new_enemy->position);
    new_enemy = set_basic_obj(new_enemy, texture_path);
    return (new_enemy);
}

enemy_t *set_basic_obj(enemy_t *obj, char *texture_path)
{
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect_tab[IDLE_R]);
    sfSprite_setPosition(obj->sprite, obj->position);
    sfSprite_setScale(obj->sprite,  obj->scale);
    sfSprite_setOrigin(obj->sprite, obj->origin);
    return (obj);
}

focus_zone_t *set_zone(float radius, sfVector2f position)
{
    focus_zone_t *new = malloc(sizeof(focus_zone_t));

    new->zone = sfRectangleShape_create();
    new->position = position;
    new->radius = radius;
    new->scale = (sfVector2f){6, 6};
    new->outline_thickness = 1;
    new->color = sfRed;
    new->size = (sfVector2f){radius, 20};
    sfRectangleShape_setOrigin(new->zone, (sfVector2f){(radius / 2), 10});
    sfRectangleShape_setPosition(new->zone, new->position);
    sfRectangleShape_setOutlineThickness(new->zone, new->outline_thickness);
    sfRectangleShape_setFillColor(new->zone, sfTransparent);
    sfRectangleShape_setSize(new->zone, new->size);
    sfRectangleShape_setScale(new->zone, new->scale);
    new->bounds = sfRectangleShape_getGlobalBounds(new->zone);
    return (new);
}

sfIntRect *get_rect_tab(void)
{
    REC *rect_tab = malloc(sizeof(REC) * 10);
    REC idle_r = {.width = 48, .height = 49, .left = 0, .top = 0};
    REC idle_l = {.width = 48, .height = 49, .left = 0, .top = 49};
    REC walk_r = {.width = 56, .height = 48, .left = 0, .top = 97};
    REC walk_l = {.width = 56, .height = 48, .left = 0, .top = 145};
    REC attack_r = {.width = 56, .height = 48, .left = 0, .top = 192};
    REC attack_l = {.width = 56, .height = 48, .left = 0, .top = 240};
    REC hit_r = {.width = 56, .height = 48, .left = 0, .top = 288};
    REC hit_l = {.width = 56, .height = 48, .left = 0, .top = 336};
    REC death_r = {.width = 72, .height = 32, .left = 0, .top = 384};
    REC death_l = {.width = 72, .height = 32, .left = 0, .top = 432};

    rect_tab[IDLE_R] = idle_r;
    rect_tab[IDLE_L] = idle_l;
    rect_tab[MOVE_R] = walk_r;
    rect_tab[MOVE_L] = walk_l;
    rect_tab[ATTACK_R] = attack_r;
    rect_tab[ATTACK_L] = attack_l;
    rect_tab[HIT_R] = hit_r;
    rect_tab[HIT_L] = hit_l;
    rect_tab[DEATH_R] = death_r;
    rect_tab[DEATH_L] = death_l;
    return (rect_tab);
}

void destroy_object(enemy_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    free(enemy);
}
