/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:07:21 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/28 16:58:57 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	circular_dll_create_front_node(t_dll **head, int num)
{
	t_dll	*new_node;
	t_dll	*first_node;
	t_dll	*last_node;

	new_node = (t_dll *)malloc(sizeof(t_dll));
	if (!new_node)
		return (-1);
	if ((*head) == NULL)
	{
		(*head) = new_node;
		new_node->next = (*head);
		new_node->prev = (*head);
		new_node->num = num;
		return (0);
	}
	first_node = (*head);
	last_node = (*head)->prev;
	(*head) = new_node;
	new_node->next = first_node;
	new_node->prev = last_node;
	new_node->num = num;
	first_node->prev = (*head);
	last_node->next = (*head);
	return (0);
}

void	print_dll(t_dll **stack)
{
	t_dll	*head;
	t_dll	*curr;

	head = (*stack);
	curr = head;
	while (curr->next != head)
	{
		printf("%d\n", curr->num);
		curr = curr->next;
	}
	printf("%d\n", curr->num);
}
