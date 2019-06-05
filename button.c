/*
** EPITECH PROJECT, 2018
** buttons.c
** File description:
** buttons gestion
*/

#include "include/my.h"

button_t *c_btn(sfVector2f pos, sfVector2f tpos, char *text)
{
    button_t *button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    button->texture = sfTexture_create(256, 240);
    button->texture = sfTexture_createFromFile("assets/button2.png", NULL);
    button->position = pos;
    button->rect = (REC){0, 0, 256, 80};
    button->scale = (VEC){1, 1};
    button->text = create_text_struct(tpos, text, 30);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setScale(button->sprite, button->scale);
    return (button);
}

void create_title_btn(list_t *list)
{
    list->buttons = malloc(sizeof(button_t *) * 3);
    list->buttons[0] = c_btn((VEC){800, 400}, (VEC){-890, -420}, "Start");
    list->buttons[0]->callback = &play;
    list->buttons[1] = c_btn((VEC){800, 550}, (VEC){-890, -570}, "Options");
    list->buttons[1]->callback = &option_page;
    list->buttons[2] = c_btn((VEC){800, 700}, (VEC){-905, -720}, "Quit");
    list->buttons[2]->callback = &close_window;
}

int button_is_on(button_t *button, sfVector2f clickpos)
{
    int check = 0;
    int posx = sfSprite_getPosition(button->sprite).x;
    int posy = sfSprite_getPosition(button->sprite).y;

    check += clickpos.x < posx + (button->rect.width) * button->scale.x;
    check += clickpos.x > posx;
    check += clickpos.y < posy + (button->rect.height) * button->scale.y;
    check += clickpos.y > posy;
    return (check == 4);
}

void check_buttons_click(sfRenderWindow *w, sfEvent eve, list_t **list, int *i)
{
    sfVector2f coord = {eve.mouseButton.x, eve.mouseButton.y};

    for (int x = 0; x < list[*i]->btn_nbr; x++) {
        if (button_is_on(list[*i]->buttons[x], coord) == 1) {
            list[*i]->buttons[x]->rect.top = 160;
            sfSprite_setTextureRect(list[*i]->buttons[x]->sprite, list[*i]->buttons[x]->rect);
            list[*i]->buttons[x]->callback(w, i, list);
        }
    }
}

void check_buttons_hoover(sfRenderWindow *win, list_t *l, int *i)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)win);
    sfVector2f coord = {mouse.x, mouse.y};
    button_t **buttons = l->buttons;

    (void)i;
    for (int x = 0; x < l->btn_nbr; x++) {
        if (button_is_on(buttons[x], coord) == 1) {
            buttons[x]->rect.top = 80;
            sfSprite_setTextureRect(buttons[x]->sprite, buttons[x]->rect);
        } else {
            buttons[x]->rect.top = 0;
            sfSprite_setTextureRect(buttons[x]->sprite, buttons[x]->rect);
        }
    }
}
