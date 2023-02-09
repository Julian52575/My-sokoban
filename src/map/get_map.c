/*
** EPITECH PROJECT, 2022
** sokoban get map.c
** File description:
** analyze the map passed as a parameter
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
void get_goals_crates_player2(char **map, int y, int x);

void get_goals_crates_player2(char **map, int y, int x)
{
    if (map[y][x] != '#' && map[y][x] != ' ') {
        if (map[y][x] != 'O' && map[y][x] != 'X' && map[y][x] != 'P'
        && map[y][x] != '\n' && map[y][x] != '\0') {
            exit(84);
        }
        map[y][x] = ' ';
    }
}

void get_goals_crates_player(char **map, struct sokoban **soko)
{
    struct crates *c = NULL;
    struct goals *g = NULL;
    struct player *p = NULL;
    struct borders *b = NULL;
    for (int y = my_array_len(map); y >= 0; y--) {
        for (int x = 0; map[y][x]; x++) {
            get_goals(map[y][x], y, x, &g);
            get_crates(map[y][x], y, x, &c);
            get_player(map[y][x], y, x, &p);
            get_goals_crates_player2(map, y, x);
        }
    }
    struct sokoban *element;
    element = malloc(sizeof(*element));
    element->c = c;
    element->g = g;
    element->p = p;
    element->b = b;
    element->status = 0;
    *soko = element;
}

void get_map(char *file, char *map, int size)
{
    int fd = open(file, O_RDONLY);
    read(fd, map, size);
    map[size] = '\0';
}
