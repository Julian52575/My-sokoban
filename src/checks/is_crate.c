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

int is_crate(struct crates *c, int y, int x)
{
    struct crates *tmp = c;
    while (tmp) {
        if (tmp->y == y && tmp->x == x) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
