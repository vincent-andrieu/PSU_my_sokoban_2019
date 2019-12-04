/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** check if the player win or lose
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my_sokoban.h"
#include "my.h"

static int get_max_lines(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++);
    return i;
}

static int get_max_nbr_columns(char **map)
{
    int max_x = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int k = 0; map[i][k] != '\0'; k++)
            max_x = k > max_x ? k : max_x;
    return max_x;
}

void print_map(char **map)
{
    if (COLS - 2 < get_max_nbr_columns(map) || LINES < get_max_lines(map)) {
        mvprintw(LINES / 2, COLS / 2 - my_strlen(MSG_RESIZE_SCREEN) / 2 < 0 ? 0
                : COLS / 2 - my_strlen(MSG_RESIZE_SCREEN) / 2,
                MSG_RESIZE_SCREEN);
    } else
        for (int i = 0; map[i] != NULL; i++) {
            printw(map[i]);
            printw("\n");
        }
}