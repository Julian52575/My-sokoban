/*
** EPITECH PROJECT, 2022
** msokoban main
** File description:
** analyze the map passed as a parameter
*/

#include <ncurses.h>
#include <curses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "sokoban.h"
#include "my.h"
#include "julian.h"

void free_crates(struct crates *c)
{
    if (c) {
        free_crates(c->next);
    }
    free(c);
    return;
}

void free_goals(struct goals *g)
{
    if (g) {
        free_goals(g->next);
    }
    free(g);
    return;
}
