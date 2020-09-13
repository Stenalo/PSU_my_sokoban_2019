##
## EPITECH PROJECT, 2019
## Make
## File description:
## files
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c \
		src/help.c	\
		src/load_map.c	\
		src/move_up.c	\
		src/move_left.c	\
		src/move_right.c	\
		src/move_down.c	\
		src/get_coord.c		\
		src/parse_map.c	\
		src/init_game.c	\
		src/get_player.c	\
		src/display_map.c	\
		src/manage_keys.c	\
		src/sokoban.c

LDFLAGS	=	-Wshadow -Wall -W

CFLAGS	=	 -I./include/ -lmy -L./lib/my -g

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_sokoban

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) -lncurses $(LDFLAGS) $(CFLAGS)

clean	:
		$(RM) $(OBJ)
		$(RM) *~
		make -C ./lib/my clean

fclean	:	clean
		$(RM) $(NAME)
		make -C ./lib/my fclean

re	:	 fclean all
