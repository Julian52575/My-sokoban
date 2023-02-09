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

int goals_len(struct sokoban *soko)
{
    struct goals *tmp = soko->g;
    int n = 0;
    while (tmp) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

int crates_len(struct sokoban *soko)
{
    struct crates *tmp = soko->c;
    int n = 0;
    while (tmp) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

int player_len(struct sokoban *soko)
{
    struct player *tmp = soko->p;
    int n = 0;
    while (tmp) {
        n++;
        tmp = tmp->next;
    }
    return n;
}
