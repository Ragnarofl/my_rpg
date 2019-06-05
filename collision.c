/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** Collision gestion
*/

#include "include/my.h"

char **check_info(char **info, char **tmp)
{
    if (my_strcmp(tmp[0], "name") == 0)
        info[0] = tmp[1];
    if (my_strcmp(tmp[0], "type") == 0)
        info[1] = tmp[1];
    if (my_strcmp(tmp[0], "height") == 0)
        info[2] = tmp[1];
    if (my_strcmp(tmp[0], "width") == 0)
        info[3] = tmp[1];
    if (my_strcmp(tmp[0], "x") == 0)
        info[4] = tmp[1];
    if (my_strcmp(tmp[0], "y") == 0)
        info[5] = tmp[1];
    return (info);
}

char **get_info(char **buff, int *index)
{
    char **tmp = NULL;
    char **info = malloc(sizeof(char *) * 6);

    for (char *save; buff[*index]; *index += 1) {
        tmp = my_str_to_word_array(buff[*index], "\":");
        info = check_info(info, tmp);
        save = tmp[0];
        if (my_strcmp(save, "y") == 0)
            break;
    }
    return (info);
}

col_t *new_collision(col_t *collisions, char **info)
{
    col_t *new = malloc(sizeof(*new));

    new->name = info[0];
    new->type = info[1];
    new->height = my_getnbr(info[2]);
    new->width = my_getnbr(info[3]);
    new->x = my_getnbr(info[4]);
    new->y = my_getnbr(info[5]);
    new->next = collisions;
    new->rect = (REC){new->x * 4, new->y * 4, new->width * 4, new->height * 4};
    return (new);
}

col_t *get_file(char *file)
{
    int i = 0;
    char **buff = my_str_to_word_array(read_file(file), "{} ,\n");
    col_t *collisions = NULL;

    for (; my_strcmp(buff[i++], "\"name\":\"collision\"") != 0;);
    i++;
    for (char **info; my_strcmp(buff[i], "]") != 0; i++) {
        info = get_info(buff, &i);
        collisions = new_collision(collisions, info);
    }
    return (collisions);
}

int enemy_collisions(col_t *collisions, enemy_t *e, list_t *list)
{
    REC e_rec = {e->position.x - 24, e->position.y - 42, 0, 0};
    back_t *back = list->first->back;

    for (; back->next; back = back->next);
    e_rec.left += back->rect.left * 4;
    e_rec.width = 16 * 3;
    e_rec.height = 26 * 3;
    for (col_t *col = collisions; col; col = col->next) {
        if (col->rect.left + col->rect.width < e_rec.left)
            continue;
        else if (col->rect.left > e_rec.left + e_rec.width)
            continue;
        if (sfIntRect_intersects(&col->rect, &e_rec, NULL) == sfTrue)
            return (1);
    }
    return (0);
}

int check_collisions(col_t *collisions, list_t *list)
{
    char_t *p = list->first->player;
    REC p_rec = {p->position.x + 30, p->position.y, 0, 0};
    back_t *back = list->first->back;

    for (; back->next; back = back->next);
    p_rec.left += back->rect.left * 4 - (p->rect.width * 3 / 2);
    p_rec.top -= (p->collide.height * 3 / 2);
    p_rec.width = p->collide.width * 3;
    p_rec.height = p->collide.height * 3;
    for (col_t *col = collisions; col; col = col->next) {
        if (col->rect.left + col->rect.width < p_rec.left)
            continue;
        else if (col->rect.left > p_rec.left + p_rec.width)
            continue;
        if (sfIntRect_intersects(&col->rect, &p_rec, NULL) == sfTrue)
            return (1);
    }
    return (0);
}
