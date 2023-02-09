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
static void freeing(struct sokoban *soko);

char **start(char *file)
{
    struct stat sfile;
    stat(file, &sfile);
    int size = sfile.st_size;

    char map[size + 1];
    get_map(file, map, size);
    return my_str_to_word_array(map);
}

static void freeing(struct sokoban *soko)
{
    free_crates(soko->c);
    free_goals(soko->g);
    free(soko->p);
    free(soko);
    return;
}

int main(int ac, char **av)
{
    int a = ac_error_handling(ac, av);
    if (a != 1) {
        return a;
    }
    char **map_array = start(av[1]);
    struct sokoban *soko;
    get_goals_crates_player(map_array, &soko);
    a = map_error_handling(soko);
    if (a != 1) {
        return a;
    }
    game_loop(map_array, soko);
    a = soko->status;
    freeing(soko);
    free(map_array);
    return a;
}
