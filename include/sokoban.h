/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** header
*/

#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__
#include <stdbool.h>
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

typedef struct pos_s {
    int x;
    int y;
    char **map;
} pos_t;

void check_win(char **map, pos_t *pos);
int check_O_full(char **map, int i, int j, int full);
int check_O_empty(char **map, int i, int j, int empty);
void reset(char **map);
void display_map(char **map);
pos_t *init_position(char *map);
void init_game(char **map, pos_t *pos);
void move_down(char **map, pos_t *pos);
void move_up(char **map, pos_t *pos);
void move_left(char **map, pos_t *pos);
void move_right(char **map, pos_t *pos);
void solo_move_down(char **map, pos_t *pos);
void move_box_down(char **map, pos_t *pos);
void move_box_left(char **map, pos_t *pos);
void solo_move_left(char **map, pos_t *pos);
void move_box_right(char **map, pos_t *pos);
void solo_move_right(char **map, pos_t *pos);
void move_box_up(char **map, pos_t *pos);
void solo_move_up(char **map, pos_t *pos);
void get_player(char **map, pos_t *pos);
void manage_keys(char **map, int i, pos_t *pos);
int sokoban(int ac, char **av);
bool check_map(char *map);
char **init_map(char *map);
void copy_str_to_array(char **array, char *str);
char **create_map(char *map);
char *load_map(char const *path);
int get_nb_col(char *map, int i);
int get_nb_lines(char *map);
void check_player(int i, int j, pos_t *pos, char **map);
void get_player(char **map, pos_t *pos);
int char_is_correct(char c);
bool parse_map(char **av);
void help();
#endif
