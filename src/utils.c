/*
** EPITECH PROJECT, 2017
** utils
** File description:
** 	Util fonctions
*/

#include "../include/navy.h"

void check_hit_missed_sig(void)
{
	int fd = open("hit_or_missed.txt", O_RDONLY);
	char *get_response = get_next_line(fd);

	if (my_strlen(get_response) == 3)
		my_putstr("hit\n");
	else
		my_putstr("miss\n");
	free(get_response);
	close(fd);
}

void game(int sign, siginfo_t *info, void *context)
{
	switch (sign) {
		case SIGUSR1:
			break;
		case SIGUSR2:
			check_hit_missed_sig();
			break;
		default:
			break;
	}
}

void sig(int sign)
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = game;
	sigaction(sign, &act, NULL);
	pause();
}

void init_pid(void)
{
	extern t_game pid;
	int fd = open("pid.txt", O_RDWR);
	char *get_pid_usr1 = get_next_line(fd);
	int get_pid_usr1_int = my_str_to_int(get_pid_usr1);

	pid.pid_usr1 = get_pid_usr1_int;
	close(fd);
	free(get_pid_usr1);
}
