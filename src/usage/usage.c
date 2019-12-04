/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** usage function
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "my_sokoban.h"

off_t get_filesize(char *filepath)
{
    struct stat st;
    stat(filepath, &st);

    return st.st_size;
}

int usage(int exit_value, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int file_size = get_filesize(filepath);
    char *buffer = fd != -1 ? malloc(sizeof(char) * file_size) : NULL;
    int size;

    if (fd == -1 || buffer == NULL)
        return EXIT_ERROR;
    size = read(fd, buffer, file_size);
    close(fd);
    buffer[file_size] = '\0';
    if (size <= 0) {
        free(buffer);
        return EXIT_ERROR;
    }
    write(1, buffer, size);
    free(buffer);
    return exit_value;
}