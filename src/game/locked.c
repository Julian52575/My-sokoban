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
static int locked_crates2(char **map, struct crates *tmp);
//is crate == 1
static int locked_crates2(char **map, struct crates *tmp)
{
    int x = tmp->x;
    int y = tmp->y;
    int a = 0;
    if (map[y - 1][x] == '#' || map[y + 1][x] == '#') {
        a++;
    }
    if (map[y][x - 1] == '#' || map[y][x + 1] == '#') {
        a++;
    }
    return a;
}

int locked_crates(char **map, struct sokoban *soko)
{
    struct crates *tmp = soko->c;
    while (tmp) {
        if (locked_crates2(map, tmp) != 2) {
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}
