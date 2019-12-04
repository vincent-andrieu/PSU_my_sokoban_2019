/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** do a sokoban in the terminal
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"

static void game(char **map, vector2i_t *t_coords)
{
    vector2i_t p_coord;
    int key_pressed = -1;

    while (key_pressed != ' ') {
        p_coord = get_player_coord(map, 0);
        key_pressed = getch();
        get_arrow_pressed(map, p_coord, key_pressed);
        refresh_targets(map, t_coords);
        clear();
        print_map(map);
    }
}

static int my_sokoban(char **map)
{
    vector2i_t *t_coords = get_targets_coords(map);

    if (t_coords == NULL)
        return EXIT_ERROR;
    initscr();
    attron(A_NORMAL);
    print_map(map);
    game(map, t_coords);
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