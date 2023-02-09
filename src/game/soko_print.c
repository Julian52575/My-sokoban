/*
** EPITECH PROJECT, 2022
** sokoban game loop
** File description:
** gameing !!!
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


void print_crates(struct crates *c)
{
    while (c) {
        mvaddch(c->y, c->x, 'X');
        c = c->next;
    }
    return;
}

void print_goals(struct goals *g)
{
    while (g) {
        mvaddch(g->y, g->x, 'O');
        g = g->next;
    }
    return;
}

void print_player(struct player *p)
{
    while (p) {
        mvaddch(p->y, p->x, 'P');
        p = p->next;
    }
    return;
}

void print_borders(struct borders *b)
{
    while (b) {
        mvaddch(b->y, b->x, '#');
        b = b->next;
    }
    return;
}
