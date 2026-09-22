/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 09:05:26 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 01:37:43 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * The optional benchmark mode (--bench) must display, after sorting:
 * The computed disorder (% with two decimals).
 * The name of the strategy used and its theoretical complexity class.
 * The total number of operations.
 * The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
 * rrr).
 * The benchmark output must be sent to stderr and only appear when the flag is
 * present.
 */

static void	fill_percent(char *p, int value)
{
	int	i;

	i = 0;
	if (value >= 10000)
	{
		p[i] = '1';
		i++;
	}
	if (value >= 1000)
	{
		p[i] = value / 1000 % 10 + '0';
		i++;
	}
	p[i] = value / 100 % 10 + '0';
	i++;
	p[i] = '.';
	i++;
	p[i] = value / 10 % 10 + '0';
	i++;
	p[i] = value % 10 + '0';
	i++;
	p[i] = '%';
	i++;
	p[i] = '\0';
}

static char	*disorder(float disorder_val)
{
	char	*percent;
	char	*result;
	int		disorder_value_int;

	percent = malloc(8);
	if (!percent)
		return (NULL);
	disorder_value_int = (int)(disorder_val * 10000 + 0.5);
	fill_percent(percent, disorder_value_int);
	result = ft_strjoin(sos("[bench] disorder: "), percent);
	return (result);
}

static char	*strategy(t_options *options, float disorder)
{
	if (options->adaptive)
	{
		if (disorder < 0.2)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive / O(n2)\n"),
					sos("")));
		if (0.2 <= disorder && disorder < 0.5)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive / O(n√n)\n"),
					sos("")));
		if (disorder >= 0.5)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive "
						"/ O(n log n)\n"), sos("")));
	}
	else if (options->complex)
		return (ft_strjoin(sos("\n[bench] strategy: Complex / O(n log n)\n"),
				sos("")));
	else if (options->medium)
		return (ft_strjoin(sos("\n[bench] strategy: Medium / O(n√n)\n"),
				sos("")));
	else if (options->simple)
		return (ft_strjoin(sos("\n[bench] strategy: Simple /  O(n2)\n"),
				sos("")));
	return (NULL);
}

static char	*operations_total_ops(t_options *options)
{
	int		tot;
	char	*total_ops;

	tot = 0;
	tot += options->sa;
	tot += options->sb;
	tot += options->ss;
	tot += options->pa;
	tot += options->pb;
	tot += options->ra;
	tot += options->rb;
	tot += options->rr;
	tot += options->rra;
	tot += options->rrb;
	tot += options->rrr;
	total_ops = ft_strjoin(sos("[bench] total_ops: "), ft_itoa(tot));
	total_ops = ft_strjoin(total_ops, sos("\n"));
	return (total_ops);
}

int	benchmark(t_options *options, float disorder_val)
{
	char	*final;
	ssize_t	len;

	final = disorder(disorder_val);
	final = ft_strjoin(final, strategy(options, disorder_val));
	final = ft_strjoin(final, operations_total_ops(options));
	final = ft_strjoin(final, operations(options));
	if (!final)
		return (-1);
	len = ft_strlen(final);
	write(2, final, len);
	free(final);
	return (0);
}
