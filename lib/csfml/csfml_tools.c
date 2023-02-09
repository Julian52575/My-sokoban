/*
** EPITECH PROJECT, 2022
** csfml tools
** File description:
** some function that are useful for csfml projects (hi guillaume)
*/

#include <ncurses.h>
#include <curses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
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

void csfml_tools_create(struct csfml_tools *ct)
{
    sfRenderWindow *w =
    create_renderwindow(1980, 1080, 32, "c Rulian EPitech Nancy 2022");
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_restart(clock);
    ct->window = w;
    ct->clock = clock;
    ct->time = time;
    ct->time_buffer = 0;
}
