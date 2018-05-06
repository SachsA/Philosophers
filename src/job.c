/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** job c
*/

#include <stdio.h>
#include <unistd.h>
#include "extern.h"
#include "philosopher.h"

STATIC void rest(philosopher_t *philo)
{
	(void)philo;
	lphilo_sleep();
#ifdef __BONUS__
	printf("\x1b[31mPhilosopher[%lu] is sleeping!\x1b[0m\n", philo->who);
#endif
	usleep(5000);
}

STATIC void eat(philosopher_t *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	pthread_mutex_lock(philo->philo_mutex_r);
	lphilo_take_chopstick(&philo->philo_mutex);
	lphilo_take_chopstick(philo->philo_mutex_r);
	lphilo_eat();
#ifdef __BONUS__
	printf("\x1b[32mPhilosopher[%lu] is eating!\x1b[0m\n", philo->who);
#endif
	usleep(5000);
	lphilo_release_chopstick(&philo->philo_mutex);
	lphilo_release_chopstick(philo->philo_mutex_r);
	pthread_mutex_unlock(&philo->philo_mutex);
	pthread_mutex_unlock(philo->philo_mutex_r);
}

STATIC void think(philosopher_t *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	lphilo_take_chopstick(&philo->philo_mutex);
	lphilo_think();
#ifdef __BONUS__
	printf("\x1b[36mPhilosopher[%lu] is thinking!\x1b[0m\n", philo->who);
#endif
	usleep(5000);
	lphilo_release_chopstick(&philo->philo_mutex);
	pthread_mutex_unlock(&philo->philo_mutex);
}

STATIC void algo_philo(philosopher_t *philo)
{
	char str[3] = "ERT";
	int max = philo->args->rounds;

	while (philo->eat < max) {
		if (str[philo->state] == 'E') {
			eat(philo);
			philo->eat += 1;
		}
		else if (str[philo->state] == 'T')
			think(philo);
		else
			rest(philo);
		philo->state = (philo->state + 1) % 3 % philo->args->philo;
	}
}

void *job(void *ptr_philo)
{
	philosopher_t *philo = ptr_philo;

	algo_philo(philo);
	return (0);
}
