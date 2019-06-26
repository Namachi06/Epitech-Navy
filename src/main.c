/*
** EPITECH PROJECT, 2017
** main
** File description:
** 	Compute program
*/

#include "../include/navy.h"

int main(int argc, char *argv[])
{
	int res;
	res = connexion_argument(argc, argv);
	if (res != 0)
		return (84);
	return (0);
}
