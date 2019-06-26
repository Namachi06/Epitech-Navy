/*
** EPITECH PROJECT, 2017
** display
** File description:
** 	Display curent map with boat positions and enemy map with update
*/

#include "../include/navy.h"

void display_created_map(char **map)
{
	my_putstr("\nenemy's positions:\n");
	for (int i = 0; map[i] != NULL; i++) {
		my_putstr(map[i]);
		my_putchar('\n');
	}
}

void display_my_map(char **map, char *file)
{
	map = add_ship_map(map, file);
	my_putstr("my positions:\n");
	for (int i = 0; map[i] != NULL; i++) {
		my_putstr(map[i]);
		my_putchar('\n');
	}
}

void display_updated_map(char **map)
{
	my_putchar('\n');
	for (int i = 0; map[i] != NULL; i++) {
		my_putstr(map[i]);
		my_putchar('\n');
	}
}
