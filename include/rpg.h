/*
** EPITECH PROJECT, 2018
** CSFML.h
** File description:
** simon-perraud
*/

#ifndef __CSFML__
#define __CSFML__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "particles.h"
#include "player.h"

#define VEC sfVector2f
#define REC sfIntRect

#define NB(string) (my_getnbr(string))
#define MUSIC ("assets/page_one.ogg")
//-CLOCKS TAB-
#define C_INV 4

typedef struct window_s
{
    sfRenderWindow *win;
    sfEvent eve;
} window_t;

typedef struct clock_s
{
    sfTime time;
    sfClock *clock;
    float seconds;
} clocki_t;

typedef struct back_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    int map;
    int action;
    int dir;
    struct back_s *next;
} back_t;

typedef struct zone_s {
    sfVector2f position;
    sfVector2f scale;
    sfVector2f size;
    sfRectangleShape *zone;
    sfColor color;
    sfFloatRect bounds;
    float radius;
    float outline_thickness;
} zone_t;

typedef struct char_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    zone_t *hurt_box;
    zone_t *hit_box_r;
    zone_t *hit_box_l;
    VEC *hit_box;
    int *tab;
    int action;
    int dir;
    int jump;
    sfIntRect collide;
    struct inventory_s *inv;
    struct clock_s *clock;
} char_t;

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    zone_t *focus_zone;
    zone_t *hit_zone;
    zone_t *hurt_box;
    zone_t *hit_box_r;
    zone_t *hit_box_l;
    sfIntRect Rect;
    sfIntRect *rect_tab;
    VEC origin;
    VEC *hit_box;
    sfVector2f scale;
    sfVector2i size;
    float inv_duration;
    int hp;
    double dexterity;
    int state;
    int speed;
    int dir;
    struct enemy_s *next;
} enemy_t;
typedef struct text_s
{
    sfText *text;
    sfVector2f pos;
    sfFont *font;
    struct text_s *next;
} text_t;

typedef struct npc_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    int action;
    int dir;
    text_t *text;
    struct npc_s *next;
} npc_t;

typedef struct item_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    unsigned int is_in_range;
    struct item_s *next;
} item_t;

typedef struct inventory_s
{
    int nb_items;
    item_t *items;
    struct inventory_s *next;
} inv_t;

typedef struct col_s
{
    char *name;
    char *type;
    int height;
    int width;
    int x;
    int y;
    sfIntRect rect;
    struct col_s *next;
} col_t;

typedef struct object_s
{
    back_t *back;
    char_t *player;
    npc_t *npc;
    item_t *items;
    item_t *inventory;
    enemy_t *enemy_list;
} object_t;

typedef struct music_s
{
	sfMusic *music;
} music_t;


typedef struct list_s
{
    object_t *first;
    struct button_s **buttons;
    int btn_nbr;
    text_t *text;
    sfMusic *music;
    int volume;
    clocki_t **clocks;
} list_t;

typedef struct button_s
{
    sfSprite *sprite;
    sfText *text;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    void (*callback)(sfRenderWindow *, int *, list_t **);
} button_t;


/* Paololib */
void *my_calloc(int size, int nb);
int my_dbstarlen(char **arr);

/* Button.c */
void create_title_btn(list_t *list);
button_t *c_btn(sfVector2f pos, sfVector2f tpos, char *text);
int button_is_on(button_t *button, sfVector2f clickpos);
void check_buttons_hoover(sfRenderWindow *, list_t *, int *);
void check_buttons_click(sfRenderWindow *, sfEvent, list_t **, int *);

/* Option.c */
void create_option_btn(list_t *list);

/* Music.c */
void play_music(list_t *);
void manage_music(list_t *);

/* button_select */
void switch_back(int x, list_t *list);
void create_select_button(list_t *);
button_t *pause_button(char *, sfVector2f, sfIntRect);

/* Clock.c */
clocki_t *create_clock(void);
void get_time(clocki_t **);
clocki_t **get_clocks(void);
void manage_clock(clocki_t **, list_t *, int *);
void move_rect(sfIntRect *rect, int offset, int max_value);
void restart_clocks(clocki_t **clocks);

/* Callback.c */
void select_menu(sfRenderWindow *, int *, list_t **);
void back_menu(sfRenderWindow *, int *, list_t **);
void play(sfRenderWindow *, int *, list_t **);
void close_window(sfRenderWindow *, int *, list_t **);
void option_page(sfRenderWindow *, int *, list_t **);
void score_page(sfRenderWindow *, int *, list_t **);
void continue_game(sfRenderWindow *, int *, list_t **);

/* pause.c */
void create_pause_button(list_t *list);

/* game.c */
void manage_game(clocki_t **clocks, list_t *list, int *);
text_t *game_text(void);

/* Object.c */
object_t *create_object(void);
void create_character(list_t *list);
void create_back(char *ssh, sfVector2f pos, object_t *obj);
void create_map(char *ssh, sfVector2f pos, object_t *obj);
void create_para(char *ssh, sfVector2f pos, object_t *obj);

/* object2.c */
void create_npc(list_t *);
item_t *create_item(int name, sfVector2f pos);
item_t *add_item(item_t *item_list, int name, sfVector2f pos);
void create_items(list_t *);

/* scene.c */
list_t *create_select(void);
list_t *create_title(void);
list_t *create_pause(void);
list_t *create_option(void);
list_t *create_score(void);
list_t *create_game(void);
list_t *create_inventory(void);
list_t **create_list_array(void);

/* game.c */

/* npc_interaction.c */
void npc_interaction(npc_t *, char_t *, list_t *);

/* List.c */
void draw_list(sfRenderWindow *window, list_t *list);
list_t **create_list_array(void);

/* Text.c */
sfText *create_text_struct(sfVector2f, char *, int);
text_t *create_text(sfVector2f, char *, int, text_t *);
text_t *score_text(void);
void draw_text(sfRenderWindow *, list_t *);
text_t *option_text(void);

/* viking moves */
void action_char(list_t *list, char_t *character, col_t *);
void move_char(list_t *list, char_t *character, col_t *);

/* viking animations */
void viking_idle(list_t *list, char_t *character);
void viking_run(list_t *list, char_t *character, col_t *col);
void viking_light_attack(list_t *list, char_t *character);
void viking_jump(list_t *list, char_t *character, col_t *col);
void viking_heavy_attack(list_t *list, char_t *character);

/* viking animations 2 */
void viking_dash(list_t *list, char_t *character, col_t *col);
void viking_block(list_t *list, char_t *character);
void viking_gethit(list_t *list, char_t *character);
void viking_death(list_t *list, char_t *character);


/* viking setup */
void viking_setup_run(char_t *character, int);
void viking_setup_jump(char_t *character);
void viking_setup_attack(char_t *character);
void viking_setup_heavy_attack(char_t *character);

/* viking setup 2 */
void viking_setup_dash(char_t *character);
void viking_setup_block(char_t *character);
void viking_setup_gethit(char_t *character);
void viking_setup_death(char_t *character);

/* Event.c */
void button_released(window_t *win, list_t **list, int *i);
void key_pressed(window_t *win, list_t **list, int *i, partBuffer *);
void key_released(window_t *win, list_t **list, int *i, partBuffer *);

/* collision.c */
col_t *get_file(char *file);
int check_collisions(col_t *, list_t *);
int enemy_collisions(col_t *collisions, enemy_t *e, list_t *);

/* gravity.c */
void gravity(list_t *, col_t *);
void enemy_gravity(list_t *list, col_t *col);

/* item animation */
void item_animation(list_t *list, item_t *list_item);
void item_animate(list_t *list, item_t *item);
int items_interactions(list_t *, item_t *);

void draw_inventory(sfRenderWindow *window, list_t **l, item_t *list);
int can_grab(list_t *list, item_t *tmp);
item_t *grab_object(list_t *list);
void add_in_inventory(list_t *list, item_t *item);

#endif /* __CSFML__ */
