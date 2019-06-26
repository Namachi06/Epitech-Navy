/*
** EPITECH PROJECT, 2017
** game.c
** File description:
** Game fonctions
*/

#include "../include/navy.h"

void set_coordinate(void)
{
	char *coordinate;
	int fd;

	my_putstr("\nattack: ");
	coordinate = get_next_line(0);
	fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	lseek(fd, 0, SEEK_END);
	write(fd, coordinate, 2);
	write(fd, "\n", 1);
	close(fd);
	my_putstr(coordinate);
	my_putstr(": ");
}

char *get_coordinate(void)
{
	int fd = open("temp.txt", O_RDONLY);
	char *get_coordinate = get_next_line(fd);

	my_putstr(get_coordinate);
	my_putstr(": ");
	close(fd);
	return (get_coordinate);
}

void game_usr1(char * file, char **map)
{
	extern t_game pid;

	set_coordinate();
	kill(pid.pid_usr2, SIGUSR1);
	sig(SIGUSR2);
	game_usr2(file, map);
}

void game_usr2(char *file, char **map)
{
	char *coordinate;
	extern t_game pid;
	char **new_map;

	my_putstr("\nwaiting for enemy's attack...\n");
	sig(SIGUSR1);
	coordinate = get_coordinate();
	hit_or_missed(map, coordinate);
	kill(pid.pid_usr2, SIGUSR2);
	new_map = update_map(map);
	display_updated_map(new_map);
	game_usr1(file, map);
}
