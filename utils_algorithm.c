/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 08:56:50 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 02:25:50 by mbrunial         ###   ########.fr       */
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
	t_dll	*not_curr;
	int		i;
	int		j;

	if (!stack || !*stack)
		return ;
	i = 0;
	curr = (*stack);
	while (i < len_stack)
	{
		curr->rank = 0;
		not_curr = (*stack);
		j = 0;
		while (j < len_stack)
		{
			if (curr->num > not_curr->num)
				(curr->rank)++;
			not_curr = not_curr->next;
			j++;
		}
		curr = curr->next;
		i++;
	}
}

static void	rotate_i_times(t_dll **stack1, t_dll **stack2, t_options *options,
		int i)
{
	while (i > 0)
	{
		rotate_rb(stack2, options);
		i--;
	}
	push_pa(stack1, stack2, options);
}

static void	reverse_rotate_i_times(t_dll **stack1, t_dll **stack2,
		t_options *options, int i)
{
	while (i > 0)
	{
		reverse_rotate_rb(stack2, options);
		i--;
	}
	push_pa(stack1, stack2, options);
}

void	range_sort_sorting(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack2)
{
	t_dll	*curr;
	int		i;

	while (*stack2)
	{
		curr = (*stack2);
		i = 0;
		while (curr->rank != (len_stack2 - 1))
		{
			curr = curr->next;
			i++;
		}
		if (i <= (len_stack2 / 2))
			rotate_i_times(stack1, stack2, options, i);
		else
			reverse_rotate_i_times(stack1, stack2, options, len_stack2 - i);
		len_stack2--;
	}
}
