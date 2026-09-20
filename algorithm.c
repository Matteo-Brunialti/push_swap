/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/20 12:39:05 by mbrunial         ###   ########.fr       */
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
		push_pa(stack1, stack2, options);
	}
}

void	adaptive(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	float	disorder;

	disorder = compute_disorder(stack1);
	if (disorder < 0.2)
		simple_bubble(stack1, stack2, options, len_stack1);
	if (0.2 <= disorder && disorder < 0.5)
		printf("in contrsuction");
	// do something
	if (disorder >= 0.5)
		complex_radix(stack1, stack2, options, len_stack1);
}

static int	get_max_bits(int max_val)
{
	int	max_bits;

	max_bits = 0;
	while ((max_val >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_radix(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	int	max_bits;
	int	bit;
	int	i;

	if (len_stack1 <= 1)
		return ;
	max_bits = get_max_bits(len_stack1 - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < len_stack1)
		{
			if (((*stack1)->rank >> bit) & 1)
				rotate_ra(stack1, options);
			else
				push_pb(stack1, stack2, options);
			i++;
		}
		while (*stack2)
			push_pa(stack1, stack2, options);
		bit++;
	}
}

static	rotate_j_times(t_dll **stack, int j)
{

} 

static	reverse_rotate_j_times(t_dll **stack, int j)
{

}

static void	range_sort_sorting(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack2)
{
	t_dll	*curr;
	int		i;
	int		j;
	int		range;
	int		max_rank;

	range = my_sqrt(len_stack2);
	max_rank = len_stack2 - 1;
	while (stack2)
	{
		curr = (*stack2);
		j = 0;
		while (j < len_stack2)
		{
			if (curr->rank == max_rank)	
			{
				if (j <= (len_stack2 / 2))
					rotate_j_times(stack2, j);
				else
					reverse_rotate_j_times(stack2, len_stack2 - j);
				max_rank--;
				j = len_stack2;
			}
			curr = curr->next;
			j++;
		}
		i++;
	}
}

void	medium_range_sort(t_dll **stack1, t_dll **stack2, t_options *options,
		int len_stack1)
{
	t_dll	*curr;
	int		range;
	int		i;

	range = my_sqrt(len_stack1);
	i = 0;
	while (*stack1)
	{
		curr = (*stack1);
		if (curr->rank < (range * ((i / range) + 1)))
		{
			push_pb(stack1, stack2, options);
			i++;
		}
		else
			rotate_ra(stack1, options);
	}
	print_dll(stack2);
}
