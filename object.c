/*
** EPITECH PROJECT, 2018
** object.c
** File description:
** object gestion
*/

#include "include/my.h"

object_t *create_object(void)
{
    object_t *new = malloc(sizeof(*new));

    if (new) {
        new->back = NULL;
        new->player = NULL;
        new->npc = NULL;
        new->enemy_list = NULL;
        new->items = NULL;
    }
    return (new);
}

void create_back(char *ssh, sfVector2f pos, object_t *obj)
{
    back_t *new = malloc(sizeof(*new));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_create(1920, 1080);
    new->texture = sfTexture_createFromFile(ssh, NULL);
    new->position = pos;
    new->rect = (REC){0, 0, 1920, 1080};
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    new->map = 1;
    new->scale = (sfVector2f){1, 1};
    new->next = obj->back;
    obj->back = new;
}

void create_map(char *ssh, sfVector2f pos, object_t *obj)
{
    back_t *new = malloc(sizeof(*new));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_create(920, 272);
    new->texture = sfTexture_createFromFile(ssh, NULL);
    new->position = pos;
    new->rect = (REC){0, 0, 470, 272};
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    new->map = 1;
    new->scale = (sfVector2f){4, 4};
    new->next = obj->back;
    obj->back = new;
}

void character_init(char_t *character)
{
    character->jump = 0;
    character->action = 0;
    character->dir = RIGHT;
    character->collide = (REC){0, 0, 20, 40};
    character->hit_box = get_hit_box_pos_tab(character->position);
    character->hurt_box = set_zone(5, character->position);
    character->hit_box_r = set_zone(6, character->hit_box[E_HIT_BOX_R]);
    character->hit_box_l = set_zone(6, character->hit_box[E_HIT_BOX_L]);
    character->clock = create_clock();
}

void create_character(list_t *list)
{
    char_t *character = malloc(sizeof(*character));

    character->tab = malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
        character->tab[i] = 0;
    character_init(character);
    character->scale = (sfVector2f){3, 3};
    character->rect = (sfIntRect){0, 0, 40, 40};
    character->position = (sfVector2f){260, 703};
    character->sprite = sfSprite_create();
    character->texture = sfTexture_createFromFile("assets/viking13.png", NULL);
    sfSprite_setTexture(character->sprite, character->texture, sfTrue);
    sfSprite_setTextureRect(character->sprite, character->rect);
    sfSprite_setPosition(character->sprite, character->position);
    sfSprite_setScale(character->sprite, character->scale);
    sfSprite_setOrigin(character->sprite, (VEC){20, 20});
    character->inv = malloc(sizeof(*character->inv));
    character->inv->items = malloc(sizeof(item_t));
    character->inv->items = NULL;
    list->first->player = character;
}
