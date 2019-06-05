/*
** EPITECH PROJECT, 2019
** Game object header file
** File description:
** object
*/

#ifndef OBJECT_H_
#define OBJECT_H_
/*INCLUDES*/
#include "my.h"

/*DEFINES*/
//-STATES-
#define BUSY 0
#define AVAIBLE 1
//-ACTIONS-
#define E_MOVE 0
#define E_ATTACK 1
#define E_HURT 2
#define E_DEATH 3
#define E_INVICIBLE 4
//-HIT BOXES-
#define E_HIT_BOX_R 0
#define E_HIT_BOX_L 1
//-ANIMATION-
#define E_LEFT 0
#define E_RIGHT 1
#define IDLE_R 0
#define IDLE_L 1
#define MOVE_R 2
#define MOVE_L 3
#define ATTACK_R 4
#define ATTACK_L 5
#define HURT_R 6
#define HURT_L 7
#define DEATH_R 8
#define DEATH_L 9

/*PROTOTYPES*/
//enemy_obj.c
enemy_t *set_enemy(sfVector2f position);
enemy_t *set_basic_obj(enemy_t *obj, char *texture_path);
zone_t *set_zone(float radius, sfVector2f position);
sfIntRect *get_rect_tab(void);
VEC *get_hit_box_pos_tab(sfVector2f position);
//enemy_obj_interact.c
void enemies_interactions(list_t **list);
void enemy_spawn_at_grab(list_t **l, window_t *window);
void enemy_spawn_at_mpos(list_t **l, window_t *window);
void update_clocks(list_t *list, enemy_t *enemy);
clocki_t *get_clock_time(clocki_t *clock);
//enemy_obj_hithurt.c
void set_hurt(list_t *list, enemy_t *enemy);
void set_hit(list_t *list, enemy_t *enemy);
//enemy_obj_list.c
enemy_t *add_enemy(sfVector2f position, enemy_t *enemy_list);
void update_enemy_list(enemy_t *enemies, sfRenderWindow *window);
VEC *update_hit_box_pos(VEC *hit_box, VEC player);
//enemy_obj_mv.c
void move_enemy(sfVector2f m_pos, enemy_t *enemy, clocki_t **clock_tab);
//enemy_obj_agro.c
void set_agro(list_t *game, enemy_t *enemy);
//enemy_obj_agro1.c
int is_obj_in_zone(sfVector2f position, enemy_t *enemy, zone_t *zone);
int focus_mouse(list_t *game, enemy_t *enemy);
int hit_zone(list_t *game, enemy_t *enemy);
//enemy_obj_anim.c
void move_rect_b(sfIntRect *rect, int max_value, int start_at_maxv);
void set_avaible_state(enemy_t *enemy, int anim);
void animate_object(list_t *game, enemy_t *enemy,  int anim, int max_value, int start_at_maxv);
#endif /* !OBJECT_H_ */
