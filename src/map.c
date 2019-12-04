/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage maps
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "my_sokoban.h"

static int check_entities(char **map)
{
    int player = 0;
    int boxes = 0;
    int targets = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int k = 0; map[i][k] != '\0'; k++) {
            player += map[i][k] == PLAYER ? 1 : 0;
            boxes += map[i][k] == BOXE ? 1 : 0;
            targets += map[i][k] == TARGET ? 1 : 0;
        }
    if (player != 1 || boxes != targets)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int check_map(char **map)
{
    int count = 0;
    int k;

    for (int i = 0; map[0][i] != '\0'; i++)
        if (map[0][i] != WALL)
            return EXIT_ERROR;
    for (; map[count] != NULL; count++);
    for (int i = 0; map[count - 1][i] != '\0'; i++)
        if (map[count - 1][i] != WALL)
            return EXIT_ERROR;
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i][0] != WALL)
            return EXIT_ERROR;
        for (k = 0; map[i][k] != '\n' && map[i][k] != '\0'; k++);
        if (map[i][k - 1] != WALL)
            return EXIT_ERROR;
    }
    return check_entities(map);
}

static char *get_buffer_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int file_size = get_filesize(filepath);
    char *buffer = fd != -1 ? malloc(sizeof(char) * (file_size + 1)) : NULL;
    int size;

    if (fd == -1 || buffer == NULL)
        return NULL;
    size = read(fd, buffer, file_size);
    close(fd);
    if (size <= 0) {
        free(buffer);
        return NULL;
    }
    buffer[file_size] = '\0';
    return buffer;
}

static bool is_split_char(char const c)
{
    return c == '\n' || c == '\0';
}

char **get_map(char *filepath)
{
    char *map = get_buffer_map(filepath);
    char **tab;

    if (map == NULL)
        return NULL;
    tab = my_str_to_array(map, &is_split_char, false);
    free(map);
    if (check_map(tab) != EXIT_SUCCESS)
        return NULL;
    return tab;
}