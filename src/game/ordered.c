/*
** EPITECH PROJECT, 2022
** sokoban colision
** File description:
** can you move there ? No you can't.
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
static int ordered_crates2(struct crates *c, struct goals *g);

static int ordered_crates2(struct crates *c, struct goals *g)
{
    if (c->x == g->x && c->y == g->y) {
        return 1;
    }
    return 0;
}

int ordered_crates(struct sokoban *s)
{
    struct goals *g = s->g;
    struct crates *c = s->c;
    int a = 0;
    while (g) {
        while (c) {
            a += ordered_crates2(c, g);
            c = c->next;
        }
        c = s->c;
        g = g->next;
    }
    if (a != goals_len(s)) {
        return -1;
    }
    return 1;
}
