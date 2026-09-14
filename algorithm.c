/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:55:58 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/14 11:54:56 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble(t_dll **stack1, t_dll **stack2, int len_stack1)
{
	int i;
	int j;

	i = 0;
	while (i++ < (len_stack1))
	{
		push(stack1, stack2);
		write(1, "pb\n", 3);
	}
	i = 0;
	while (i++ < (len_stack1))
	{
		j = i;
		while (j++ < len_stack1)
		{
			if (stack2[0]->num > stack2[0]->next->num)
			{
				swap(stack2);
				write(1, "sb\n", 3);
			}
			rotate(stack2);
			write(1, "rb\n", 3);
		}
		push(stack2, stack1);
		write(1, "pa\n", 3);
	}
}
