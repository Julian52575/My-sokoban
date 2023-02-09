/*
** EPITECH PROJECT, 2022
** msokoban error
** File description:
** is the map good ?
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


int map_error_handling(struct sokoban *soko)
{
    int c_len = crates_len(soko);
    int g_len = goals_len(soko);
    int p_len = player_len(soko);
    if (c_len <= 0 || g_len <= 0) {
        return 84;
    }
    if (c_len != g_len) {
        return 84;
    }
    if (p_len != 1) {
        return 84;
    }
    return 1;
}

int ac_error_handling(int ac, char **av)
{
    if (ac == 1 ) {
        return 84;
    }
    if (av[1][0] == '-') {
        my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
        my_putstr("\tmap file representing the warehouse map,");
        my_putstr("containing ‘#’ for walls,\n");
        my_putstr("\t‘P’ for the player, ‘X’ for boxes and");
        my_putstr("‘O’ for storage locations.\n");
        return 0;
    }
    return 1;
}
