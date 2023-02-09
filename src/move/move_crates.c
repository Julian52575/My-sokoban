/*
** EPITECH PROJECT, 2022
** sokoban colision
** File description:
** up
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
static void move_crates2(struct crates *tmp, int movement);

static void move_crates2(struct crates *tmp, int movement)
{
    switch (movement) {
        case (8):
            tmp->y -= 1;
            break;
        case (2):
            tmp->y += 1;
            break;
        case (4):
            tmp->x -= 1;
            break;
        case (6):
            tmp->x += 1;
            break;
    }
}

void move_crates(struct sokoban *s, int y, int x, int movement)
{
    struct crates *tmp = s->c;
    while (tmp) {
        if (tmp->y == y && tmp->x == x) {
            move_crates2(tmp, movement);
        }
        tmp = tmp->next;
    }
}
