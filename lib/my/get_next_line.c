/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** 	Automaticly read one line of a text file;
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/get_next_line.h"

void init(t_get_next_line *gnl)
{
	gnl->b = 1;
	gnl->word = NULL;
	gnl->nb_char = 0;
}

char *my_realloc(char *string, int length)
{
	char *new_memory;

	if (string == NULL)
		return (NULL);
	new_memory = (char *)malloc(sizeof(char) * length + 1);
	for (int i = 0; string[i] != '\0'; i++) {
		new_memory[i] = string[i];
	}
	free(string);
	return (new_memory);
}

char read_next_char(int fd)
{
	int static r;
	int static buffer_index = 0;
	int static read_once = 0;
	char static buffer[READ_SIZE];

	if (READ_SIZE == buffer_index || read_once == 0) {
		r = read(fd, buffer, sizeof(buffer));
		read_once = 1;
		buffer_index = 0;
	}
	if (r == 0) {
		return (-1);
	}
	buffer_index++;
	return (buffer[buffer_index - 1]);
}

char *get_next_line(int fd)
{
	t_get_next_line *n = (t_get_next_line *)malloc(sizeof(t_get_next_line));

	if (fd < 0)
		return (NULL);
	init(n);
	n->word = (char *)malloc(sizeof(char) * READ_SIZE + 1);
	do {
		n->c = read_next_char(fd);
		if ((n->c != -1) && (n->c != '\n')) {
			if (n->nb_char >= (READ_SIZE * n->b)) {
				n->b++;
				n->word = my_realloc(n->word, n->b * READ_SIZE);
			}
			n->word[n->nb_char] = n->c;
			n->nb_char++;
		}
	} while ((n->c != -1) && (n->c != '\n'));
	if (n->c == -1)
		return (NULL);
	n->word[n->nb_char] = '\0';
	return (n->word);
}
