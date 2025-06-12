/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"


char **read_map_lines(FILE *fd, int height)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    char *buffer = NULL;
    size_t size = 0;

    if (map == NULL)
        return NULL;
    for (int i = 0; i < height; i++) {
        if (getline(&buffer, &size, fd) == -1) {
            map[i] = NULL;
            break;
        }
        map[i] = my_strdup(buffer);
        if (map[i] == NULL) {
            free(buffer);
            return NULL;
        }
    }
    map[height] = NULL;
    free(buffer);
    return map;
}

char **load_map(char *filepath, game_t *game)
{
    FILE *fd = fopen(filepath, "r");
    char **map = NULL;

    if (fd == NULL)
        return NULL;
    map = read_map_lines(fd, game->height);
    fclose(fd);
    if (map == NULL)
        return NULL;
    game->map = map;
    return map;
}
