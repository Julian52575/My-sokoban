/*
** EPITECH PROJECT, 2022
** sokoban get map.c
** File description:
** analyze the map passed as a parameter
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

void get_goals(char map, int y, int x, struct goals **g)
{
    if (map == 'O') {
        struct goals *element;
        element = malloc(sizeof(*element));
        element->y = y;
        element->x = x;
        element->next = *g;
        *g = element;
    }
}

void get_player(char map, int y, int x, struct player **p)
{
    if (map == 'P') {
        struct player *element;
        element = malloc(sizeof(*element));
        element->y = y;
        element->x = x;
        element->next = *p;
        *p = element;
    }
}

void get_crates(char map, int y, int x, struct crates **c)
{
    if (map == 'X') {
        struct crates *element;
        element = malloc(sizeof(*element));
        element->y = y;
        element->x = x;
        element->next = *c;
        *c = element;
    }
}
