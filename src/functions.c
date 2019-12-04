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
    int i = 0;

    for (; map[i] != NULL; i++)
        free(map[i]);
    free(map[i]);
    free(map);
    free(t_coords);
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

bool check_lose(char **map, vector2i_t *coords, int box_nbr, int i)
{
    int count_x = 0;
    int count_y = 0;

    for (int k = 1; map[i][k + 1] != '\0'; k++) {
        if (map[i][k] == BOXE) {
            count_y += map[i - 1][k] == WALL || map[i - 1][k] == BOXE;
            count_y += map[i + 1][k] == WALL || map[i + 1][k] == BOXE;
            count_x += map[i][k - 1] == WALL || map[i][k - 1] == BOXE;
            count_x += map[i][k + 1] == WALL || map[i][k + 1] == BOXE;
            box_nbr++;
        }
        if (map[i][k] == BOXE && (count_x == 0 || count_y == 0))
            return false;
        count_x = 0;
        count_y = 0;
    }
    if (map[i + 1] == NULL || coords[box_nbr].x == -1)
        return true;
    return check_lose(map, coords, box_nbr, i + 1);
}