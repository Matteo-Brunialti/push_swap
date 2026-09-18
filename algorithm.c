/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/18 09:38:05 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// simple algorithm
void	simple_bubble(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
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

void	adaptive(t_dll **stack1, t_dll **stack2, t_options *options, int len_stack1)
{
	float disorder;

	disorder = compute_disorder(stack1);
	if (disorder < 0.2)
		simple_bubble(stack1, stack2, options, len_stack1);
	if (0.2 <= disorder && disorder < 0.5)
		printf("in contrsuction");
		//do something
	if (disorder >= 0.5)
		printf("in construction");
		// put complex here
}

void medium_range_sort(t_dll **stack1, t_dll **stack2, t_options *options, int len_stack1)
{
	t_dll	*curr;
	int		range;
	int		i;

	set_rank(stack1, len_stack1);
	range = my_sqrt(len_stack1);
	i = 1;
	curr = (*stack1);
	while (stack1)
	{
		if (0 < curr->rank && curr->rank < (range * ((i / range) + 1)))	
		{
			push_pa(stack1, stack2, options);
			i++;
		}
		else
			rotate_ra(stack1, options);
	}
	// insert sort for range number until stack b is finished
}
