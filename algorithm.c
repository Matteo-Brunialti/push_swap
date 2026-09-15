/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/15 22:40:32 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// simple algorithm
void bubble(t_dll **stack1, t_dll **stack2, int len_stack1, t_options *options)
{
	int i;
	int j;

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
