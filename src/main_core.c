/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** main c
*/

#include <stdio.h>
#include <stdlib.h>
#include "extern.h"
#include "philosopher.h"

STATIC int init_args(int argc, char **argv, args_t *args)
{
	int ret = 0;

	if (argc != 5)
		ret = 84;
	else {
		args->philo = 0;
		args->rounds = 0;
		RCFStartup(argc, argv);
		if (initialization(argv, args) == 84)
			ret = 84;
	}
	return (ret);
}

STATIC void quit_philo(philosopher_t *philo)
{
	if (philo != NULL)
		free(philo);
	RCFCleanup();
}

int main_core(int argc, char **argv)
{
	int ret = 0;
	args_t args;
	philosopher_t *philo = NULL;

	if (init_args(argc, argv, &args) == 84)
		ret = 84;
	else {
		philo = malloc(sizeof(philosopher_t) * args.philo);
		if (philo == NULL)
			ret = 84;
		if (my_philosopher(philo, &args) == 84)
			ret = 84;
	}
	quit_philo(philo);
	return (ret);
}
