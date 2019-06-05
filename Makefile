##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC			=	gcc

CFLAGS		=	-Wall -Wextra -W -I include/ -g3

LIB			=	-L./lib/my -lmy		\
				-lcsfml-audio		\
				-lcsfml-graphics	\
				-lcsfml-network		\
				-lcsfml-window		\
				-lcsfml-system

SRC			=	main.c			\
				event.c			\
				clock.c			\
				list.c			\
				button.c		\
				text.c			\
				callback.c		\
				object.c		\
				scene.c			\
				option.c		\
				music.c			\
				pause.c			\
				game.c			\
				viking_moves.c	\
				viking_animations.c \
				enemies/enemy_obj.c					\
				enemies/enemy_obj_list.c			\
				enemies/enemy_obj_interact.c		\
				enemies/enemy_obj_hithurt.c			\
				enemies/enemy_obj_agro.c			\
				enemies/enemy_obj_agro1.c			\
				enemies/enemy_obj_anim.c			\
				enemies/enemy_obj_mv.c				\
				viking_animations2.c \
				viking_setup.c \
				viking_setup2.c \
				particles.c		\
				particles2.c	\
				collision.c		\
				gravity.c		\
				object2.c		\
				npc_interaction.c	\
				item_animation.c \
				inventory.c \

CRITERION	=	main.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_rpg

all: $(NAME)

$(NAME): $(OBJ)
		make -C lib/my all
		$(CC) $(OBJ) $(LIB) -o $(NAME)

crit:
	make -C lib/my all
	$(CC) $(CRITERION) $(CFLAGS) -L./lib/my -lmy -lcriterion  -o $(NAME)

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all

criterion: fclean crit
