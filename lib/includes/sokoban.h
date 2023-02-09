/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** structs and prototyping for soko
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdio.h>
#include "my_csfml.h"
#include "hunter.h"
#include "my.h"
#include "julian.h"


struct crates {
    int x;
    int y;
    struct crates *next;
};

struct goals {
    int x;
    int y;
    struct goals *next;
};

struct player {
    int x;
    int y;
    struct player *next;
};

struct borders {
    int x;
    int y;
    struct borders *next;
};

struct sokoban {
    struct crates *c;
    struct goals *g;
    struct player *p;
    struct borders *b;
    int status;
    sfSprite *space;
    sfSprite *borders;
    sfSprite *crate;
    sfSprite *goal;
    sfSprite *player;
    sfSprite *background;
    int x_screen;
    int y_screen;
};

void get_goals_crates_player(char **map, struct sokoban **soko);
void get_goals_crates_player2(char **map, int y, int x);
void get_map(char *file, char *map, int size);
void get_borders(char map, int y, int x, struct borders **b);
void get_goals(char map, int y, int x, struct goals **g);
void get_player(char map, int y, int x, struct player **p);
void get_crates(char map, int y, int x, struct crates **c);

int player_imput(char **map, struct sokoban *soko);
void game_loop(char **map, struct sokoban *soko);
int game(char **map, struct sokoban *soko);

int check_crates(struct sokoban *s, int y, int x);
void move_crates(struct sokoban *s, int y, int x, int movement);

int is_crate(struct crates *c, int y, int x);
int is_goal(struct goals *g, int y, int x);

int up_colision1(char **map, struct sokoban *s);
int down_colision1(char **map, struct sokoban *s);
int right_colision1(char **map, struct sokoban *s);
int left_colision1(char **map, struct sokoban *s);
void arround_colision(char **map, struct sokoban *soko);

void print_borders(struct borders *b);
void print_player(struct player *p);
void print_goals(struct goals *g);
void print_crates(struct crates *c);
int colision(struct sokoban *soko, int entitY, int entitX);
int locked_crates(char **map, struct sokoban *soko);
int ordered_crates(struct sokoban *s);

void game_end(struct sokoban *s);
void victory(void);
void game_over(int why);

int goals_len(struct sokoban *soko);
int crates_len(struct sokoban *soko);
int player_len(struct sokoban *soko);

int map_error_handling(struct sokoban *soko);
int ac_error_handling(int ac, char **av);

void free_goals(struct goals *g);
void free_crates(struct crates *c);

void blank(struct csfml_tools *ct,
char **map, struct sokoban *soko);
void create_sprites(struct sokoban *element);
void graphic_loop(struct csfml_tools *ct,
char **map, struct sokoban *soko);

int g_game(struct csfml_tools *ct,
char **map, struct sokoban *soko);

void move_player(struct csfml_tools *ct,
char **map, struct sokoban *soko, sfKeyCode button);
void display_all(struct csfml_tools *ct,
char **map, struct sokoban *soko);

void display_player(struct csfml_tools *ct,
struct sokoban *s);
void display_map(sfRenderWindow *w, char **map, struct sokoban *s);
void display_goal(sfRenderWindow *w, struct sokoban *s);
void display_crate(sfRenderWindow *w, struct sokoban *s);
void g_game_end(struct csfml_tools *ct, struct sokoban *s);
void quit_window(sfRenderWindow *w, struct sokoban *s);
