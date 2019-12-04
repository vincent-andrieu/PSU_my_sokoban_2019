/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage targets
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_sokoban.h"

static int get_targets_nbr(char **map, int count, int i)
{
    if (map[i] == NULL)
        return count;
    for (int k = 0; map[i][k] != '\0'; k++)
        count += map[i][k] == TARGET;
    return get_targets_nbr(map, count, i + 1);
}

vector2i_t *get_targets_coords(char **map)
{
    int count = get_targets_nbr(map, 0, 0);
    vector2i_t *coords = malloc(sizeof(vector2i_t) * (count + 1));
    int i = 0;

    if (coords == NULL)
        return NULL;
    for (int y = 0; map[y] != NULL; y++)
        for (int x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == TARGET)
                coords[i++] = (vector2i_t) {x, y};
        }
    coords[i] = (vector2i_t) {-1, -1};
    return coords;
}

void refresh_targets(char **map, vector2i_t *coords)
{
    for (int i = 0; coords[i].x != -1 && coords[i].y != -1; i++)
        if (map[coords[i].y][coords[i].x] == SPACE)
            map[coords[i].y][coords[i].x] = TARGET;
}