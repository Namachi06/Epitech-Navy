/*
** EPITECH PROJECT, 2017
** navy
** File description:
** 	Navy include
*/

#include "my.h"

typedef struct s_game
{
	int pid_usr1;
	int pid_usr2;
	char *hit;
	char *miss;
} t_game;

int my_navy_usr1(char *file);
int my_navy_usr2(char *file);
void game_usr1(char *file, char **map);
void game_usr2(char *file, char **map);
void hit_or_missed(char **map, char *coordinate);
char **create_map(void);
void display_created_map(char **map);
void display_my_map(char **map, char *file);
char **add_ship_map(char **map, char *file);
char **place_ship(char **map, char *buffer);
int connexion_argument(int argc, char **argv);
void check_first_connection(int sig, siginfo_t *info, void *context);
void sig(int sign);
void init_pid(void);
char **update_map(char **map);
void display_updated_map(char **map);
