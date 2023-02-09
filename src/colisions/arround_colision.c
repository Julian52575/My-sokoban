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

void arround_colision(char **map, struct sokoban *soko)
{
    up_colision1(map, soko);
    down_colision1(map, soko);
    left_colision1(map, soko);
    right_colision1(map, soko);
    return;
}
