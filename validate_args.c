/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:38:46 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 09:42:45 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_int_args(int argc, char **argv, int shift)
{
	long long	tmp_i;
	long long	tmp_j;
	ssize_t		i;
	ssize_t		j;

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
	return (shift);
}

static bool	option_cmp(char *str, char *option)
{
	ssize_t	i;

	i = 0;
	while (str[i] && option[i] && str[i] == option[i])
		i++;
	if (str[i] == option[i])
		return (true);
	return (false);
}

static void	set_options_to_false(t_options *options)
{
	options->simple = false;
	options->medium = false;
	options->complex = false;
	options->adaptive = true;
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

static	void	set_shift(t_options *options, int *shift)
{
	if (options->simple)
		(*shift)++;
	if (options->medium)
		(*shift)++;
	if (options->complex)
		(*shift)++;
	if (options->adaptive)
		(*shift)++;
	if (options->bench)
		(*shift)++;
}

/*
 * AO: this function assume argc and atgv has 3 argument in it
 * the program name and at least 2 argument let them be number  or option
 *
 * true only if only 1 argument is given
 *
 */
int	validate_args(t_options *options, int argc, char **argv)
{
	int	shift;

	shift = 0;
	if (argc == 2)
		return (validate_int_args(argc, argv, shift));
	set_options_to_false(options);
	if (option_cmp(argv[1], "--simple") != option_cmp(argv[2], "--simple"))
		options->simple = true;
	if (option_cmp(argv[1], "--medium") != option_cmp(argv[2], "--medium"))
		options->medium = true;
	if (option_cmp(argv[1], "--complex") != option_cmp(argv[2], "--complex"))
		options->complex = true;
	if (options->simple || options->medium || options->complex)
		options->adaptive = false;
	if (option_cmp(argv[1], "--bench") != option_cmp(argv[2], "--bench"))
		options->bench = true;
	set_shift(options, &shift);
	return (validate_int_args(argc - shift, argv + shift, shift));
}
