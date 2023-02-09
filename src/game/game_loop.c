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

int player_imput(char **map, struct sokoban *soko)
{
    int a = getch();
    if (a == 66 && (down_colision1(map, soko) ) < 3 ) {
        soko->p->y += 1;
        return a;
    }
    if (a == 65 && (up_colision1(map, soko) ) < 3 ) {
        soko->p->y -= 1;
        return a;
    }
    if (a == 68 && (left_colision1(map, soko) < 3) ) {
        soko->p->x -= 1;
        return a;
    }
    if (a == 67 && (right_colision1(map, soko) < 3) ) {
        soko->p->x += 1;
        return a;
    }
    if (a == 97) {
        arround_colision(map, soko);
    } return a;
}

void game_loop(char **map, struct sokoban *soko)
{
    WINDOW *w = initscr();
    cbreak();
    noecho();
    int a = 0;
    while (a == 0) {
        a = game(map, soko);
    }
    refresh();
    delwin(w);
    endwin();
}

int game(char **map, struct sokoban *soko)
{
    int a = 0;
    if (ordered_crates(soko) == 1) {
        a = 1;
        soko->status = 0;
    } else if (locked_crates(map, soko) == 1) {
        a = 1;
        soko->status = 1;
    }
    for (int i = 0; map[i][0] != '\0'; i++) {
        mvaddstr(1 * i, 0, map[i]);
    }
    print_goals(soko->g);
    print_crates(soko->c);
    print_player(soko->p);
    player_imput(map, soko);
    refresh();
    return a;
}

//inverser 27 et 32
//Game loop : While 32 && 27, restart 32 avec sauvegarde
//Game : change a to 27 after ordered / locked_crates
