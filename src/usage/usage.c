/*
** EPITECH PROJECT, 2019
** my_screensaver
** File description:
** usage function
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"

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
    char *buffer = malloc(sizeof(char) * file_size);
    int size = read(fd, buffer, file_size);

    buffer[file_size] = '\0';
    close(fd);
    if (size <= 0)
        return 84;
    write(1, buffer, size);
    free(buffer);
    return exit_value;
}