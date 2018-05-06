/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** test_init_args.c
*/

#include <criterion/criterion.h>
#include "philosopher.h"

int init_args(int argc, char **argv, args_t *args);

Test(init_args, return_value_ac_bad)
{
	args_t args;
	int ac = 3;
	char *av[3] = {"./philo", "-p", "3"};

	cr_assert_eq(init_args(ac, av, &args), 84, "Expected return: 84.");
}

Test(init_args, return_value_ac_good)
{
	args_t args;
	int ac = 5;
	char *av[5] = {"./philo", "-p", "3", "-e", "3"};

	cr_assert_eq(init_args(ac, av, &args), 0, "Expected return: 0.");
}
