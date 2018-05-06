/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** Philosopher c
*/

#include <stdlib.h>
#include "philosopher.h"

STATIC void init_thread(philosopher_t *philo, args_t *args)
{
	size_t i = -1;
	size_t max_p = (size_t)args->philo;

	while (++i < max_p) {
		pthread_create(&philo[i].philo_thread,
		NULL, job, &philo[i]);
		pthread_mutex_init(&philo->philo_mutex, NULL);
	}
	i = -1;
	while (++i < max_p) {
		pthread_join(philo[i].philo_thread, NULL);
		pthread_mutex_destroy(&philo->philo_mutex);
	}
}

STATIC int init_philo(philosopher_t *philo, args_t *args)
{
	size_t i = -1;
	size_t max = (size_t)args->philo;

	while (++i < max) {
		philo[i].who = i;
		philo[i].args = args;
		philo[i].state = i % 3;
		pthread_mutex_init(&philo[i].philo_mutex, NULL);
		philo[i].philo_mutex_r =
			&philo[(i + 1) % max].philo_mutex;
		philo[i].eat = 0;
	}
#ifdef UNIT_TEST
	return (0);
#endif
	init_thread(philo, args);
	return (0);
}

int my_philosopher(philosopher_t *philo, args_t *args)
{
	int ret = 0;

	if (init_philo(philo, args) == 84)
		ret = 84;
	return (ret);
}
