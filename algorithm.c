/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/10 21:25:00 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void bubble(t_dll **stack1, t_dll **stack2, int len_stack1)
{
	int	i;
	int	j;
	
	i = 0;
	while (i++ < (len_stack1))
		push(stack1, stack2, "pb\n");
	i = 0;
	while (i < (len_stack1 - 1))
	{
		j = i;
		while (j < (len_stack1 - 1))
		{
			if (stack2[0]->num > stack2[0]->next->num)
				swap(stack2, "sb\n");
			rotate(stack2, "rb\n");
			j++;
		}
		push(stack2, stack1, "pa\n");
		i++;
	}
	push(stack2, stack1, "pa\n");
}

