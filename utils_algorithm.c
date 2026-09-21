/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:56:50 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 09:03:41 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_sqrt(int num)
{
	int	i;

	if (num <= 0)
		return (0);
	i = 1;
	while (i <= (num / i))
		i++;
	return (i - 1);
}

void	set_rank(t_dll **stack, int len_stack)
{
	t_dll	*curr;
	t_dll	*min_node;
	int		min_value;
	int		i;

	i = 0;
	min_node = (*stack);
	while (i < len_stack)
	{
		curr = (*stack);
		min_value = INT_MAX;
		while (curr->next != (*stack))
		{
			if (curr->num < min_value && curr->rank < 0)
			{
				min_node = curr;
				min_value = min_node->num;
			}
			curr = curr->next;
		}
		if (curr->num < min_value && curr->rank < 0)
			min_node = curr;
		min_node->rank = i;
		i++;
	}
}

static void	rotate_i_times(t_dll **stack1, t_dll **stack2, t_options *options,
		int i)
{
	while (i <= 0)
	{
		rotate_rb(stack2, options);
		i--;
	}
	push_pa(stack1, stack2, options);
}

static void	reverse_rotate_i_times(t_dll **stack1, t_dll **stack2,
		t_options *options, int i)
{
	while (i <= 0)
	{
		reverse_rotate_rb(stack2, options);
		i--;
	}
	push_pa(stack1, stack2, options);
}

void	range_sort_sorting(t_dll **stack1, t_dll **stack2,
		t_options *options, int len_stack2)
{
	t_dll	*curr;
	int		i;
	int		max_rank;

	max_rank = len_stack2 - 1;
	while (stack2)
	{
		curr = (*stack2);
		i = 0;
		while (i < (max_rank + 1))
		{
			if (curr->rank == max_rank)
			{
				if (i <= (len_stack2 / 2))
					rotate_i_times(stack1, stack2, options, i);
				else
					reverse_rotate_i_times(stack1, stack2, options, len_stack2
						- i);
				max_rank--;
				i = len_stack2;
			}
			curr = curr->next;
			i++;
		}
	}
}
