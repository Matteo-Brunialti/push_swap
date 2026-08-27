/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:07:21 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/27 20:53:55 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// fukking base case 1 node 2 node 3 node n node
int create_dll_node_front(t_dll **head, int num)
{
	t_dll *new_node;
	t_dll *old_first;
	t_dll *tmp_last;

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
	old_first = (*head);	
	tmp_last = (*head)->prev;
	(*head) = new_node;
	new_node->next = tmp_last->next;
	new_node->prev = old_first->prev;
	new_node->num = num;
	old_first->prev = (*head);
	tmp_last->next = (*head);
	//tozzo chi legge
	return (0);
}

void print_dll(t_dll **stack)
{
	t_dll *head;
	t_dll *curr;

	head = (*stack);
	curr = head;
	while (curr->next != head)
	{
		printf("%d\n", curr->num);
		curr = curr->next;
	}
	printf("%d\n", curr->num);
}
