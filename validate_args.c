/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:38:46 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 00:25:37 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_int_args(int argc, char **argv, int shift)
{
	long long	tmp_i;
	long long	tmp_j;
	ssize_t		i;
	ssize_t		j;

	i = shift + 1;
	if (i >= argc)
		return (-1);
	while (i < argc)
	{
		j = i + 1;
		tmp_i = is_int(argv[i]);
		if (tmp_i == LLONG_MIN)
			return (-1);
		while (j < argc)
		{
			tmp_j = is_int(argv[j]);
			if (tmp_j == LLONG_MIN || tmp_i == tmp_j)
				return (-1);
			j++;
		}
		i++;
	}
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
	options->disorder = 0.0;
}

static int	parse_option(t_options *options, char *arg)
{
	if (option_cmp(arg, "--bench"))
	{
		if (options->bench)
			return (-1);
		options->bench = true;
		return (0);
	}
	if (options->simple || options->medium || options->complex
		|| options->adaptive)
		return (-1);
	options->simple = option_cmp(arg, "--simple");
	options->medium = option_cmp(arg, "--medium");
	options->complex = option_cmp(arg, "--complex");
	options->adaptive = option_cmp(arg, "--adaptive");
	if (!options->simple && !options->medium && !options->complex
		&& !options->adaptive)
		return (-1);
	return (0);
}

int	validate_args(t_options *options, int argc, char **argv)
{
	int	i;

	set_options_to_false(options);
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (parse_option(options, argv[i]) == -1)
			return (-1);
		i++;
	}
	if (!options->simple && !options->medium && !options->complex
		&& !options->adaptive)
		options->adaptive = true;
	return (validate_int_args(argc, argv, i - 1));
}
