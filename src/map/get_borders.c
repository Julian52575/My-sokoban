/*
** EPITECH PROJECT, 2022
** sokoban get borders.c
** File description:
** analyze the borders of the map passed as a parameter
*/

#include <ncurses.h>
#include <curses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sokoban.h>
#include <my.h>
#include <julian.h>

void get_borders(char map, int y, int x, struct borders **b)
{
    if (map == '#') {
        struct borders *element;
        element = malloc(sizeof(*element));
        element->y = y;
        element->x = x;
        element->next = *b;
        *b = element;
    }
}
