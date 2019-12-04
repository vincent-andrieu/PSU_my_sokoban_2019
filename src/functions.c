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

static int check_boxes_arround(char **map, int x, int y)
{
    int count = 0;

    count += map[y - 1][x] == WALL;
    count += map[y + 1][x] == WALL;
    count += map[y][x - 1] == WALL;
    count += map[y][x + 1] == WALL;
    return count;
}

bool check_lose(char **map)
{
    for (int i = 1; map[i + 1] != NULL; i++)
        for (int k = 1; map[i][k + 1] != '\0'; k++)
            if (map[i][k] == BOXE && check_boxes_arround(map, k, i) >= 2)
                return true;
    return false;
}