/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** Philosopher h
*/

#ifndef PHILOSOPHER_H_
	#define PHILOSOPHER_H_

	#include <pthread.h>

	#if defined UNIT_TEST
		#define STATIC
	#else
		#define STATIC static
	#endif /* UNIT_TEST */

	typedef struct	args_s {
		int philo;
		int rounds;
	}		args_t;

	typedef struct	philosopher_s {
		int eat;
		int state;
		size_t who;
		args_t *args;
		pthread_t philo_thread;
		pthread_mutex_t philo_mutex;
		pthread_mutex_t *philo_mutex_r;
	}		philosopher_t;

	void *job();
	int main_core(int argc, char **argv);
	int initialization(char **argv, args_t *args);
	int my_philosopher(philosopher_t *philo, args_t *args);

#endif /* !PHILOSOPHER_H_ */
