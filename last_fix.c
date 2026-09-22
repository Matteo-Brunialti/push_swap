/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_fix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:36:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 02:31:41 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_1_2_3(t_dll **stack, t_options *options)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->rank;
	b = (*stack)->next->rank;
	c = (*stack)->prev->rank;
	if (a > b && a > c)
		rotate_ra(stack, options);
	else if (b > a && b > c)
		reverse_rotate_ra(stack, options);
	if ((*stack)->rank > (*stack)->next->rank)
		swap_sa(stack, options);
}

static int	minimum_position(t_dll **stack1, int len_stack1)
{
	t_dll	*curr;
	int		min;
	int		position;
	int		i;

	curr = (*stack1);
	min = curr->rank;
	position = 0;
	i = 0;
	while (i < len_stack1)
	{
		if (curr->rank < min)
		{
			min = curr->rank;
			position = i;
		}
		curr = curr->next;
		i++;
	}
	return (position);
}

static void	min_tob(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	int	i;

	i = minimum_position(stack1, len_stack1);
	if (i <= len_stack1 / 2)
	{
		while (i > 0)
		{
			rotate_ra(stack1, options);
			i--;
		}
	}
	else
	{
		while (i < len_stack1)
		{
			reverse_rotate_ra(stack1, options);
			i++;
		}
	}
	push_pb(stack1, stack2, options);
}

void	sort_small(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	if (len_stack1 <= 1)
		return ;
	if (len_stack1 == 2)
	{
		if ((*stack1)->rank > (*stack1)->next->rank)
			swap_sa(stack1, options);
		return ;
	}
	while (len_stack1 > 3)
	{
		min_tob(stack1, stack2, options, len_stack1);
		len_stack1--;
	}
	sort_1_2_3(stack1, options);
	while (*stack2)
		push_pa(stack1, stack2, options);
}
