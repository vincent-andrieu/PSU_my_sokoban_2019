/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mange arrows moves
*/

#include "my_sokoban.h"

static void arrow_up(char **map, vector2i_t coord)
{
    if (map[coord.y - 1][coord.x] == BOXE && (map[coord.y - 2][coord.x] == SPACE
    || map[coord.y - 2][coord.x] == TARGET)) {
        map[coord.y - 2][coord.x] = map[coord.y - 1][coord.x];
        map[coord.y - 1][coord.x] = SPACE;
    }
    if (map[coord.y - 1][coord.x] == SPACE
    || map[coord.y - 1][coord.x] == TARGET) {
        map[coord.y - 1][coord.x] = PLAYER;
        map[coord.y][coord.x] = SPACE;
    }
}

static void arrow_down(char **map, vector2i_t coord)
{
    if (map[coord.y + 1][coord.x] == BOXE && (map[coord.y + 2][coord.x] == SPACE
    || map[coord.y + 2][coord.x] == TARGET)) {
        map[coord.y + 2][coord.x] = map[coord.y + 1][coord.x];
        map[coord.y + 1][coord.x] = SPACE;
    }
    if (map[coord.y + 1][coord.x] == SPACE
    || map[coord.y + 1][coord.x] == TARGET) {
        map[coord.y + 1][coord.x] = PLAYER;
        map[coord.y][coord.x] = SPACE;
    }
}

static void arrow_left(char **map, vector2i_t coord)
{
    if (map[coord.y][coord.x - 1] == BOXE && (map[coord.y][coord.x - 2] == SPACE
    || map[coord.y][coord.x - 2] == TARGET)) {
        map[coord.y][coord.x - 2] = map[coord.y][coord.x - 1];
        map[coord.y][coord.x - 1] = SPACE;
    }
    if (map[coord.y][coord.x - 1] == SPACE
    || map[coord.y][coord.x - 1] == TARGET) {
        map[coord.y][coord.x - 1] = PLAYER;
        map[coord.y][coord.x] = SPACE;
    }
}

static void arrow_right(char **map, vector2i_t coord)
{
    if (map[coord.y][coord.x + 1] == BOXE && (map[coord.y][coord.x + 2] == SPACE
    || map[coord.y][coord.x + 2] == TARGET)) {
        map[coord.y][coord.x + 2] = map[coord.y][coord.x + 1];
        map[coord.y][coord.x + 1] = SPACE;
    }
    if (map[coord.y][coord.x + 1] == SPACE
    || map[coord.y][coord.x + 1] == TARGET) {
        map[coord.y][coord.x + 1] = PLAYER;
        map[coord.y][coord.x] = SPACE;
    }
}

void get_arrow_pressed(char **map, vector2i_t p_coord, int key_pressed)
{
    switch (key_pressed) {
        case ARROW_UP:
            arrow_up(map, p_coord);
            break;
        case ARROW_DOWN:
            arrow_down(map, p_coord);
            break;
        case ARROW_LEFT:
            arrow_left(map, p_coord);
            break;
        case ARROW_RIGHT:
            arrow_right(map, p_coord);
            break;
    }
}