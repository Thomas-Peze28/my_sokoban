/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

int argc_error_handling(int argc, char **argv)
{
    if (argc > 3) {
        my_putstr("Error: Invalid number of arguments.\n");
        my_putstr("Use -h for help.\n");
        return 84;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    return 1;
}
