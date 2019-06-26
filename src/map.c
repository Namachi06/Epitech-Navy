/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** Create the map and place ship
*/

#include "../include/navy.h"

char **update_map(char **map)
{
	int fd = open("hit_or_missed.txt", O_RDONLY);
	char *line;
	char sign;
	int coo[2];

	line = get_next_line(fd);
	if (my_strcmp("hit", line) == 0)
		sign = 'x';
	if (my_strcmp("miss", line) == 0)
		sign = 'o';
	close(fd);
	open("temp.txt", O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	coo[0] = (line[0] - 63) * 2 - 2;
	coo[1] = line[1] - 47;
	map[coo[1]][coo[0]] = sign;
	return (map);
}

char **place_ship(char **map, char *buffer)
{
	int front[2] = {buffer[2] - 63, buffer[3] - 47 };
	int back[2] = {buffer[5] - 63, buffer[6] - 47 };

	front[0] = front[0] * 2 - 2;
	back[0] = back[0] * 2 - 2;
	map[front[1]][front[0]] = buffer[0];
	map[back[1]][back[0]] = buffer[0];
	while (front[0] != back[0]) {
		back[0] = back[0] - 2;
		map[back[1]][back[0]] = buffer[0];
	}
	while (front[1] != back[1]) {
		back[1] = back[1] - 1;
		map[back[1]][back[0]] = buffer[0];
	}
	return (map);
}

char **add_ship_map(char **map, char *file)
{
	int fd = open(file, O_RDONLY);
	char *buffer;
	int z = 0;

	while (z < 4) {
		buffer = get_next_line(fd);
		map = place_ship(map, buffer);
		z++;
	}
	return (map);
}

char **create_map(void)
{
	char **map;

	map = (char **)malloc(sizeof(char *) * 10 + 1);
	map[0] = " |A B C D E F G H\0";
	map[1] = "-+---------------\0";
	for (int i = 2; i <= 10; i++) {
		map[i] = (char *)malloc(sizeof(char) * 17 + 1);
		map[i][0] = i + 47;
		map[i][1] = '|';
		for (int j = 2; j <= 16; j++) {
			map[i][j] = '.';
			j++;
			map[i][j] = ' ';
		}
		map[i][17] = '\0';
	}
	map[10] = NULL;
	return (map);
}

void hit_or_missed(char **map, char *coordinate)
{
	int fd = open("hit_or_missed.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	int coord[2] = {coordinate[0] - 64, coordinate[1] - '0'};

	lseek(fd, 0, SEEK_END);
	if (map[coord[1] + 1][coord[0] * 2] == '.') {
		my_putstr("miss");
		my_putchar('\n');
		write(fd, "miss\n", 5);
	} else {
		my_putstr("hit");
		my_putchar('\n');
		write(fd, "hit\n", 4);
	}
	close(fd);
}
