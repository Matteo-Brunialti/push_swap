/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 03:53:49 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	get_int(char *str, int i, int sign)
{
	long long	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 12)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (sign)
		res = -res;
	if (res > INT_MAX || res < INT_MIN || ((str[i] < '0' || str[i] > '9')
			&& str[i] != '\0'))
		return (LLONG_MIN);
	return (res);
}

long long	is_int(char *str)
{
	int	sign;
	int	i;

	if (!str || !(*str))
		return (LLONG_MIN);
	sign = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-';
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (LLONG_MIN);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (LLONG_MIN);
	return (get_int(str, i, sign));
}

float	compute_disorder(t_dll **stack)
{
	t_dll				*curr_i;
	t_dll				*curr_j;
	unsigned long long	mistakes;
	unsigned long long	total_pairs;

	if (!stack || !(*stack) || (*stack)->next == (*stack))
		return (0.0);
	curr_i = (*stack);
	mistakes = 0;
	total_pairs = 0;
	while (curr_i->next != (*stack))
	{
		curr_j = curr_i->next;
		while (curr_j != (*stack))
		{
			total_pairs++;
			if (curr_i->num > curr_j->num)
				mistakes++;
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
	return ((float)mistakes / total_pairs);
}

static void	select_algorithm(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	set_rank(stack1, len_stack1);
	options->disorder = compute_disorder(stack1);
	if (options->disorder != 0.0 && len_stack1 > 5)
	{
		if (options->adaptive)
			adaptive(stack1, stack2, options, len_stack1);
		else if (options->complex)
			complex_radix(stack1, stack2, options, len_stack1);
		else if (options->medium)
			medium_range_sort(stack1, stack2, options, len_stack1);
		else if (options->simple)
			simple_bubble(stack1, stack2, options, len_stack1);
	}
	else if (options->disorder != 0.0 && len_stack1 <= 5)
		sort_small(stack1, stack2, options, len_stack1);
	if (options->bench)
		benchmark(options, options->disorder);
}

int	main(int argc, char *argv[])
{
	t_dll		*stack1;
	t_dll		*stack2;
	t_options	options;
	int			i;
	int			shift;

	stack1 = NULL;
	stack2 = NULL;
	if (argc < 2)
		return (0);
	shift = validate_args(&options, argc, argv);
	if (shift == -1)
		return (write(2, "Error\n", 6), 1);
	i = argc;
	while (--i > shift)
	{
		if (circular_dll_create_front_node(&stack1, (int)is_int(argv[i])) == -1)
		{
			free_dll(&stack1);
			return (write(2, "Error\n", 6), 1);
		}
	}
	select_algorithm(&stack1, &stack2, &options, argc - shift - 1);
	free_dll(&stack1);
	return (0);
}
