/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "sokoban.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map,\n");
    my_putstr(" containing '#' for walls,");
    my_putstr(" 'P' for the player,");
    my_putstr(" 'X' for boxes and");
    my_putstr(" 'O' for storage locations.");
}
