/*
** EPITECH PROJECT, 2018
** text.c
** File description:
** text gestion
*/

#include "include/my.h"

sfText *create_text_struct(sfVector2f pos, char *str, int size)
{
    sfText *text = NULL;
    sfFont *font = NULL;

    text = sfText_create();
    font = sfFont_createFromFile("assets/viking_younger_runes_bold.ttf");
    sfText_setString(text, str);
    sfText_setOrigin(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    return (text);
}

text_t *create_text(sfVector2f pos, char *str, int size, text_t *next)
{
    text_t *text = malloc(sizeof(*text));

    text->pos = pos;
    text->text = create_text_struct(pos, str, size);
    text->next = next;
    return (text);
}

text_t *score_text(void)
{
    text_t *text = malloc(sizeof(*text));

    text = create_text((VEC){-10, 0}, "score : ", 30, NULL);
    text = create_text((VEC){-150, 0}, "0", 30, text);
    text = create_text((VEC){-660, -40}, "SCORE", 80, text);
    return (text);
}

text_t *option_text(void)
{
    text_t *text = malloc(sizeof(*text));
    text_t *volume = malloc(sizeof(*volume));

    text->pos = (VEC){-750, -40};
    text->text = create_text_struct(text->pos, "Options", 80);
    volume->pos = (VEC){-890, -390};
    volume->text = create_text_struct(volume->pos, "50", 80);
    text->next = volume;
    volume->next = NULL;
    return (text);
}

void draw_text(sfRenderWindow *window, list_t *list)
{
    text_t *text = list->text;

    for (; text; text = text->next)
        sfRenderWindow_drawText(window, text->text, NULL);
}
