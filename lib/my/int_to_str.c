/*
** EPITECH PROJECT, 2018
** int_to_str
** File description:
** transform an int to a string
*/

#include <stdlib.h>

int nb_digits(int nb)
{
	int i = 0;

	while (nb != 0) {
		nb = nb / 10;
		i++;
	}
	return (i);
}

char *int_to_string(int nb)
{
	char *res = (char *)malloc(sizeof(nb_digits(nb) + 1));
	char digits;
	int i = nb_digits(nb);

	res[i] = '\0';
	i--;
	while (nb != 0) {
		digits = (char)(nb % 10) + 48;
		res[i] = digits;
		i--;
		nb = nb / 10;
	}
	return (res);
}
