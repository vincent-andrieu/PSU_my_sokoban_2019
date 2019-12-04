/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mange arrows moves
*/

#include <SFML/Graphics.h>
#include "my_sokoban.h"

static void arrow_up(char **map, vector2i_t coord, int i)
{
    if (map[coord.y - i][coord.x] == BOXE)
        arrow_up(map, coord, i + 1);
    if (map[coord.y - i][coord.x] == SPACE
        || map[coord.y - i][coord.x] == TARGET) {
        map[coord.y - i][coord.x] = map[coord.y - i + 1][coord.x];
        map[coord.y - i + 1][coord.x] = SPACE;
    }
}

static void arrow_down(char **map, vector2i_t coord, int i)
{
    if (map[coord.y + i][coord.x] == BOXE)
        arrow_down(map, coord, i + 1);
    if (map[coord.y + i][coord.x] == SPACE
        || map[coord.y + i][coord.x] == TARGET) {
        map[coord.y + i][coord.x] = map[coord.y + i - 1][coord.x];
        map[coord.y + i - 1][coord.x] = SPACE;
    }
}

static void arrow_left(char **map, vector2i_t coord, int i)
{
    if (map[coord.y][coord.x - i] == BOXE)
        arrow_left(map, coord, i + 1);
    if (map[coord.y][coord.x - i] == SPACE
        || map[coord.y][coord.x - i] == TARGET) {
        map[coord.y][coord.x - i] = map[coord.y][coord.x - i + 1];
        map[coord.y][coord.x - i + 1] = SPACE;
    }
}

static void arrow_right(char **map, vector2i_t coord, int i)
{
    if (map[coord.y][coord.x + i] == BOXE)
        arrow_right(map, coord, i + 1);
    if (map[coord.y][coord.x + i] == SPACE
        || map[coord.y][coord.x + i] == TARGET) {
        map[coord.y][coord.x + i] = map[coord.y][coord.x + i - 1];
        map[coord.y][coord.x + i - 1] = SPACE;
    }
}

void get_arrow_pressed(char **map, vector2i_t p_coord, int key_pressed)
{
    switch (key_pressed) {
        case ARROW_UP:
            arrow_up(map, p_coord, 1);
            break;
        case ARROW_DOWN:
            arrow_down(map, p_coord, 1);
            break;
        case ARROW_LEFT:
            arrow_left(map, p_coord, 1);
            break;
        case ARROW_RIGHT:
            arrow_right(map, p_coord, 1);
            break;
    }
}