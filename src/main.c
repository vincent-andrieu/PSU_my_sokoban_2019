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

bool check_map_char(char **map, int i)
{
    char list[] = " XOP#";
    bool is_valid = false;

    for (int k = 0; map[i][k] != '\0'; k++) {
        for (int j = 0; list[j] != '\0'; j++) {
            if (map[i][k] == list[j]) {
                is_valid = true;
                break;
            }
        }
        if (!is_valid)
            return true;
        is_valid = false;
    }
    if (map[i + 1] == NULL)
        return false;
    return check_map_char(map, i + 1);
}

static int game(char **map, vector2i_t *t_coords)
{
    vector2i_t p_coord;
    int key_pressed = -1;

    do {
        if (check_lose(map, t_coords, 1))
            return EXIT_LOSE;
        p_coord = get_player_coord(map, 0);
        key_pressed = getch();
        get_arrow_pressed(map, p_coord, key_pressed);
        refresh_targets(map, t_coords);
        clear();
        print_map(map);
    } while (key_pressed != ' ' && !check_win(map, t_coords));
    if (key_pressed == ' ')
        return EXIT_RESET;
    return EXIT_SUCCESS;
}

static int my_sokoban(char **map, char **argv)
{
    vector2i_t *t_coords = get_targets_coords(map);
    int exit_value;

    if (t_coords == NULL)
        return EXIT_ERROR;
    initscr();
    attron(A_NORMAL);
    print_map(map);
    exit_value = game(map, t_coords);
    clear();
    endwin();
    free_tab(map, t_coords);
    if (exit_value == EXIT_RESET)
        return main(2, argv);
    return exit_value;
}

int main(int argc, char **argv)
{
    char **map;

    if (argc != 2) {
        my_put_error_str(MSG_INVALID_ARG_NBR);
        return EXIT_ERROR;
    }
    if (!my_strcmp(argv[1], "-h"))
        return usage(EXIT_ERROR, HEADER_FILEPATH);
    map = get_map(argv[1]);
    if (map == NULL)
        return EXIT_ERROR;
    if (check_map_char(map, 0))
        return EXIT_ERROR;
    return my_sokoban(map, argv);
}