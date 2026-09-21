/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 10:05:55 by mbrunial         ###   ########.fr       */
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
long long	is_int(char *str)
{
	long long	res;
	int			sign;
	int			i;

	if (!str || !(*str))
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
	if (res > INT_MAX || res < INT_MIN || ((str[i] < '0' || str[i] > '9')
			&& str[i] != '\0'))
		return (LLONG_MIN);
	return (res * sign);
}

float	compute_disorder(t_dll **stack)
{
	t_dll	*curr_i;
	t_dll	*curr_j;
	int		mistakes;
	int		total_pairs;

	if (!(*stack) || !stack || (*stack)->next == (*stack))
		return (0.0f);
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
	if (options->adaptive)
		adaptive(stack1, stack2, options, len_stack1);
	else if (options->complex)
		complex_radix(stack1, stack2, options, len_stack1);
	else if (options->medium)
		medium_range_sort(stack1, stack2, options, len_stack1);
	else if (options->simple)
		simple_bubble(stack1, stack2, options, len_stack1);
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
		return (write(1, "Error\n", 6));
	i = argc;
	while (--i > shift)
		if (circular_dll_create_front_node(&stack1, is_int(argv[i])) == -1)
			return (write(1, "Error\n", 6));
	set_rank(&stack1, argc - shift - 1);
	options.disorder = compute_disorder(&stack1);
	select_algorithm(&stack1, &stack2, &options, argc - shift - 1);
	return (0);
}
