/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:38:46 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/15 12:43:03 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The function is_int(char *str) check if a string is a valid int and return
 *	long long min on error
 *
 * Only string to int format accepted is:
 * 	|---------------|--------------|
 * 	|1 optional sign|valid int char|
 * 	|---------------|--------------|
 *
 * Return values:
 * 		Return a long long in the int range (from INT_MIN to INT_MAX)
 *
 * Error
 * 		LLONG_MIN is returned on error;
 */
long long is_int(char *str)
{
	long long res;
	int sign;
	int i;

	if (!(*str))
		return (LLONG_MIN);
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 11)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN || ((str[i] < '0' || str[i] > '9') && str[i] != '\0'))
		return (LLONG_MIN);
	return (res);
}

/* The function validate_int_args(int argc, char **argv) takes the argument passed
 * 	to the program and check if they are valid for the 42 push_swap project.
 * It is assumes that at least 1 parameter was passed, no argument are checked
 * 	at the main level.
 *
 * Every arguemnt is first check if valid integer then if it is duplicate
 *
 *
 * Error:
 * 		A -1 is returned if an invalid argument is provided.
 * 		List of invalid argument:
 * 			- arguments that are not integers
 * 			- integer outside the valid range
 * 			- duplicate values
 */
static int validate_int_args(int argc, char **argv)
{
	long long tmp_i;
	long long tmp_j;
	ssize_t i;
	ssize_t j;

	i = 1;
	while (i < (argc - 1))
	{
		j = i + 1;
		tmp_i = is_int(argv[i]);
		if (tmp_i == LLONG_MIN)
			return (-1);
		while (j < (argc - 1))
		{
			tmp_j = is_int(argv[j]);
			if (tmp_j == LLONG_MIN || tmp_i == tmp_j)
				return (-1);
			j++;
		}
		i++;
	}
	tmp_i = is_int(argv[i]);
	if (tmp_i == LLONG_MIN)
		return (-1);
	return (0);
}

static bool option_cmp(char *str, char *option)
{
	ssize_t i;

	i = 0;
	while (str[i] && option[i])
		i++;
	if (str[i] == option[i])
		return (true);
	return (false);
}

static void set_options_to_false(t_options *options)
{
	options->simple = false;
	options->medium = false;
	options->complex = false;
	options->adaptive = false;
	options->bench = false;
	options->sa = 0;
	options->sb = 0;
	options->ss = 0;
	options->pa = 0;
	options->pb = 0;
	options->ra = 0;
	options->rb = 0;
	options->rr = 0;
	options->rra = 0;
	options->rrb = 0;
	options->rrr = 0;
}
/*
 * AO: this function assume argc and atgv has 3 argument in it
 * the program name and at least 2 argument let them be number  or option
 *
 * true only if only 1 argument is given
 *
 */
int validate_args(t_options *options, int argc, char **argv)
{
	int shift;

	shift = 0;
	set_options_to_false(options);
	if (option_cmp(argv[1], "--simple") != option_cmp(argv[2], "--simple"))
		options->simple = true;
	if (option_cmp(argv[1], "--medium") != option_cmp(argv[2], "--medium"))
		options->medium = true;
	if (option_cmp(argv[1], "--complex") != option_cmp(argv[2], "--complex"))
		options->complex = true;
	if (option_cmp(argv[1], "--adaptive") != option_cmp(argv[2], "--adaptive"))
		options->adaptive = true;
	if (option_cmp(argv[1], "--bench") != option_cmp(argv[2], "--bench"))
		options->bench = true;
	if (options->simple)
		shift++;
	if (options->medium)
		shift++;
	if (options->complex)
		shift++;
	if (options->adaptive)
		shift++;
	if (options->bench)
		shift++;
	return (validate_int_args(argc + shift, argv + shift));
}
