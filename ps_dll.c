/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:07:21 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/26 19:56:46 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// fukking base case 1 node 2 node 3 node n node
t_dll *dllnew(int num, t_dll *next, t_dll *prev)
{
	t_dll	*node;
	
	node = (t_dll *)malloc(sizeof(t_dll));
	if (!node)
		return (NULL);

	node->num = num;
	node->next = next;
	node->prev = prev;

	return (node);
}

void print_dll(t_dll **stack)
{
	t_dll *head;
	t_dll *curr;

	head = (*stack);
	curr = head;
	while (curr->next != head->next)
	{
		printf("%d\n", curr->num);
		curr = curr->next;
	}
}
