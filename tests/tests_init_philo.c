/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** tests_init_philo.c
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "philosopher.h"

int init_philo(philosopher_t *philo, args_t *args);

Test(init_philo, return_value_0)
{
	philosopher_t *philo = NULL;
	args_t args;
	int ret = 0;
	char *av[5] = {"./philo", "-p", "3", "-e", "3"};

	initialization(av, &args);
	philo = malloc(sizeof(philosopher_t) * args.philo);
	cr_assert_neq(philo, NULL, "Malloc has failed.");
	ret = init_philo(philo, &args);
	cr_assert_eq(ret, 0, "Expected return: 0.");
}

Test(init_philo, init_well)
{
	philosopher_t *philo = NULL;
	args_t args;
	char *av[5] = {"./philo", "-p", "3", "-e", "3"};

	initialization(av, &args);
	philo = malloc(sizeof(philosopher_t) * args.philo);
	cr_assert_neq(philo, NULL, "Malloc has failed.");
	init_philo(philo, &args);
	cr_assert_eq(philo[0].who, 0, "Expected : 0.");
	cr_assert_eq(philo[1].who, 1, "Expected : 1.");
	cr_assert_eq(philo[2].who, 2, "Expected : 2.");
	cr_assert_eq(philo[0].eat, 0, "Expected : 0.");
	cr_assert_eq(philo[1].eat, 0, "Expected : 0.");
	cr_assert_eq(philo[2].eat, 0, "Expected : 0.");
}
