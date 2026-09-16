/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/16 17:22:01 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// simple algorithm
void	simple_bubble(t_dll **stack1, t_dll **stack2, int len_stack1,
		t_options *options)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < (len_stack1))
		push_pb(stack1, stack2, options);
	i = 0;
	while (i++ < (len_stack1))
	{
		j = i;
		while (j++ < len_stack1)
		{
			if (stack2[0]->num > stack2[0]->next->num)
				swap_sb(stack2, options);
			rotate_rb(stack2, options);
		}
		push_pa(stack2, stack1, options);
	}
}

float	compute_disorder(t_dll **stack)
{
	t_dll	*curr_i;
	t_dll	*curr_j;
	int		mistakes;
	int		total_pairs;

	if (!(*stack))
		return (-1);
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

void	adaptive(t_dll **stack1, t_dll **stack2, int len_stack1, t_options *options)
{
	float disorder;

	disorder = compute_disorder(stack1);
	if (disorder < 0.2)
		simple_bubble(stack1, stack2, len_stack1, options);
	if (0.2 <= disorder < 0.5)
		printf("in contrsuction");
		//do something
	if (disorder >= 0.5)
		printf("in construction");
		// put complex here
}
