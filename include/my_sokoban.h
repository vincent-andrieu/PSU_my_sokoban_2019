/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban header
*/

#include <stdlib.h>
#include <stdbool.h>

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#define MSG_INVALID_ARG_NBR "Invalid argument number\n"
#define MSG_RESIZE_SCREEN "Enlarge the screen"
#define HEADER_FILEPATH "usage/header.txt"
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84
#define EXIT_LOSE 1

#define WALL '#'
#define BOXE 'X'
#define PLAYER 'P'
#define TARGET 'O'
#define SPACE ' '
#define ARROW_UP 65
#define ARROW_DOWN 66
#define ARROW_LEFT 68
#define ARROW_RIGHT 67

typedef struct vector2i_s
{
    int x;
    int y;
} vector2i_t;

off_t get_filesize(char *filepath);
int usage(int exit_value, char *filepath);
char **get_map(char *filepath);
int check_map(char **map);
void get_arrow_pressed(char **map, vector2i_t p_coord, int key_pressed);
vector2i_t *get_targets_coords(char **map);
void refresh_targets(char **map, vector2i_t *coords);
void free_tab(char **map, vector2i_t *t_coords);
vector2i_t get_player_coord(char **map, int i);
bool check_win(char **map, vector2i_t *coords);
bool check_lose(char **map, int i);
void print_map(char **map);

#endif