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
    my_putstr("     ./my_sokoban <map_file> <options>\n");
    my_putstr("OPTIONS\n");
    my_putstr("     -h      display this help and exit\n");
    my_putstr("     -csfml  run the game in CSFML mode\n");
    my_putstr("     -r      generate a random map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map,\n");
    my_putstr("     containing '#' for walls,");
    my_putstr(" 'P' for the player,");
    my_putstr(" 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
}
