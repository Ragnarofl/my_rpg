/*
** EPITECH PROJECT, 2018
** option.c
** File description:
** option gestion
*/

#include "include/my.h"

void volume_up(sfRenderWindow *window, int *i, list_t **list)
{
    int j = 0;

    (void)window;
    (void)i;
    if (list[j]->volume >= 100)
        return;
    for (; list[j]; j++)
        list[j]->volume += 10;
    sfText_setString(list[1]->text->next->text, my_itoa(list[1]->volume));
}

void volume_down(sfRenderWindow *window, int *i, list_t **list)
{
    int j = 0;

    (void)window;
    (void)i;
    if (list[j]->volume <= 0)
        return;
    for (; list[j]; j++)
        list[j]->volume -= 10;
    sfText_setString(list[1]->text->next->text, my_itoa(list[1]->volume));
}

button_t *c_opt_btn(sfVector2f pos, sfVector2f tpos, char *text)
{
    button_t *button = malloc(sizeof(*button));

    button->sprite = sfSprite_create();
    button->texture = sfTexture_create(256, 240);
    button->texture = sfTexture_createFromFile("assets/button2.png", NULL);
    button->position = pos;
    button->rect = (sfIntRect){0, 0, 256, 80};
    button->scale = (sfVector2f){0.25, 1};
    button->text = create_text_struct(tpos, text, 40);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setScale(button->sprite, button->scale);
    return (button);
}

void create_option_btn(list_t *list)
{
    list->buttons = malloc(sizeof(button_t) * 3);
    list->buttons[0] = c_opt_btn((VEC){700, 400}, (VEC){-721, -415}, "-");
    list->buttons[0]->callback = &volume_down;
    list->buttons[1] = c_opt_btn((VEC){1100, 400}, (VEC){-1121, -415}, "+");
    list->buttons[1]->callback = &volume_up;
    list->buttons[2] = c_btn((VEC){0, 985}, (VEC){-85, -1005}, "Back");
    list->buttons[2]->callback = &back_menu;
}
