/*
** EPITECH PROJECT, 2022
** sokoban colision
** File description:
** map [y] [x] -> crate
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

int check_crates(struct sokoban *s, int y, int x)
{
    struct crates *tmp = s->c;
    while (tmp) {
        if (y == tmp->y && x == tmp->x) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
