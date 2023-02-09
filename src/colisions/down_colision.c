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

int down_colision1(char **map, struct sokoban *s)
{
    int y1 = s->p->y + 1;
    int x1 = s->p->x;
    if (map[y1][x1] == '#' || x1 < 0 || y1 < 0
    || x1 + 1 > my_strlen(map[y1])) {
        return 3;
    }
    if (check_crates(s, y1, x1) == 1) {
        int y2 = s->p->y + 2;
        int x2 = s->p->x;
        if (map[y2][x2] == '#' || x2 < 0 || y2 < 0) {
            return 3;
        }
        if (check_crates(s, y2, x2) == 0 && map[y2][x2] == ' ') {
            move_crates(s, y1, x1, 2);
            return 1;
        } else {
            return 3;
        }
    }
    return 0;
}
