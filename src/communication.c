/*
** EPITECH PROJECT, 2017
** communication
** File description:
** 	Handle communication between two process
*/

#include "../include/navy.h"

struct s_game pid;

void check_first_connection(int sig, siginfo_t *info, void *context)
{
	pid.pid_usr2 = info->si_pid;
	switch (sig) {
		case SIGUSR1:
			my_putstr("my_pid: ");
			my_put_nbr(getpid());
			my_putstr("\nsuccessfully connected\n\n");
			break;
		case SIGUSR2:
			my_putstr("enemy connected\n\n");
			break;
		default:
			break;
	}
}

void search_ennemy(void)
{
	struct sigaction act;
	int fd = open("pid.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	char *ppid = int_to_string(getpid());

	write(fd, ppid, my_strlen(ppid));
	write(fd, "\n", 1);
	close(fd);
	my_putstr("my_pid: ");
	my_putstr(ppid);
	my_putstr("\n");
	init_pid();
	my_putstr("waiting for enemy connection...\n\n");
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = check_first_connection;
	sigaction(SIGUSR2, &act, NULL);
	pause();
	kill(pid.pid_usr2, SIGUSR1);
}

void connect_to_ennemy(char *str)
{
	int ennemy;
	struct sigaction act;

	ennemy = my_str_to_int(str);
	kill(ennemy, SIGUSR2);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = check_first_connection;
	sigaction(SIGUSR1, &act, NULL);
	pause();
}

int connexion_argument(int argc, char **argv)
{
	if (argc == 2) {
		search_ennemy();
		my_navy_usr1(argv[1]);
	} else if (argc == 3) {
		connect_to_ennemy(argv[1]);
		my_navy_usr2(argv[2]);
	} else {
		return (-1);
	}
	return (0);
}
