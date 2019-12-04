/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban functions
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_sokoban.h"

void free_tab(char **map, vector2i_t *t_coords)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    free(t_coords);
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
        printw("\n");
    }
}

vector2i_t get_player_coord(char **map, int i)
{
    if (map[i] == NULL)
        return (vector2i_t) {-1, -1};
    for (int k = 0; map[i][k] != '\0'; k++) {
        if (map[i][k] == PLAYER)
            return (vector2i_t) {k, i};
    }
    return get_player_coord(map, i + 1);
}

bool check_win(char **map, vector2i_t *coords)
{
    for (int i = 0; coords[i].x != -1 && coords[i].y != -1; i++)
        if (map[coords[i].y][coords[i].x] != BOXE)
            return false;
    return true;
}

bool check_lose(char **map, int i)
{
    int count_x = 0;
    int count_y = 0;

    if (map[i + 1] == NULL)
        return false;
    for (int k = 0; map[i][k] != '\0'; k++) {
        count_y += map[i - 1][k] == WALL;
        count_y += map[i + 1][k] == WALL;
        count_x += map[i][k - 1] == WALL;
        count_x += map[i][k + 1] == WALL;
        if (map[i][k] == BOXE && count_x >= 1 && count_y >= 1)
            return true;
        count_x = 0;
        count_y = 0;
    }
    return check_lose(map, i + 1);
}