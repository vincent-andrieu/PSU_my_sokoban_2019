/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** do a sokoban in the terminal
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"

static void free_tab(char **map, vector2i_t *t_coords)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    free(t_coords);
}

static void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
        printw("\n");
    }
}

static vector2i_t get_player_coord(char **map, int i)
{
    if (map[i] == NULL)
        return (vector2i_t) {-1, -1};
    for (int k = 0; map[i][k] != '\0'; k++) {
        if (map[i][k] == PLAYER)
            return (vector2i_t) {k, i};
    }
    return get_player_coord(map, i + 1);
}

static int my_sokoban(char **map)
{
    vector2i_t p_coord;
    vector2i_t *t_coords = get_targets_coords(map);
    int key_pressed = -1;

    if (t_coords == NULL)
        return EXIT_ERROR;
    initscr();
    attron(A_NORMAL);
    print_map(map);
    while (key_pressed != ' ') {
        p_coord = get_player_coord(map, 0);
        key_pressed = getch();
        get_arrow_pressed(map, p_coord, key_pressed);
        refresh_targets(map, t_coords);
        clear();
        print_map(map);
    }
    endwin();
    free_tab(map, t_coords);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    char **map;
    int error;

    if (argc != 2) {
        my_put_error_str(MSG_INVALID_ARG_NBR);
        return EXIT_ERROR;
    }
    if (!my_strcmp(argv[1], "-h"))
        return usage(EXIT_ERROR, HEADER_FILEPATH);
    map = get_map(argv[1]);
    if (map == NULL)
        return EXIT_ERROR;
    error = check_map(map);
    if (error != EXIT_SUCCESS)
        return error;
    return my_sokoban(map);
}