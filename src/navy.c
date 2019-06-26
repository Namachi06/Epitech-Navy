/*
** EPITECH PROJECT, 2017
** navy
** File description:
** 	Game function
*/

#include "../include/navy.h"

int my_navy_usr1(char *file)
{
	char **map = create_map();
	char **enemy_map = create_map();

	display_my_map(map, file);
	display_created_map(enemy_map);
	game_usr1(file, enemy_map);
	return (0);
}

int my_navy_usr2(char *file)
{
	char **map = create_map();
	char **enemy_map = create_map();

	display_my_map(map, file);
	display_created_map(enemy_map);
	game_usr2(file, map);
	return (0);
}
