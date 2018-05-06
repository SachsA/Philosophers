/*
** EPITECH PROJECT, 2018
** PSU_philosopher_2017
** File description:
** test_main_core.c
*/

#include <criterion/criterion.h>
#include "philosopher.h"

Test(main_core, return_value_ac_bad)
{
	int ac = 3;
	char *av[3] = {"./philo", "-p", "3"};

	cr_assert_eq(main_core(ac, av), 84, "Expected return: 84.");
}

Test(main_core, return_value_ac_good)
{
	int ac = 5;
	char *av[5] = {"./philo", "-p", "3", "-e", "3"};

	cr_assert_eq(main_core(ac, av), 0, "Expected return: 0.");
}
