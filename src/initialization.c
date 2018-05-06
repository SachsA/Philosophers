/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** initialization.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "philosopher.h"

STATIC int deal_opt(char **argv, size_t i, args_t *args)
{
	int ret = 0;

	if (strcmp(argv[i], "-p") == 0) {
		args->philo = atoi(argv[i + 1]);
		if (args->philo <= 1) {
			dprintf(2, "You must have at least two philosophers\n");
			ret = 84;
		}
	}
	else if (strcmp(argv[i], "-e") == 0) {
		args->rounds = atoi(argv[i + 1]);
		if (args->rounds <= 0) {
			dprintf(2, "You must have at least one eat cycle\n");
			ret = 84;
		}
	}
	return (ret);
}

int initialization(char **argv, args_t *args)
{
	int ret = 0;
	size_t i = 0;

	while (++i < 5) {
		if (deal_opt(argv, i, args) == 84) {
			ret = 84;
			break;
		}
	}
	return (ret);
}
