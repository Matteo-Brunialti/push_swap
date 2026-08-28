/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:17:52 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/28 17:48:33 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dll **head)
{
	t_dll	*first_node;
	t_dll	*last_node;
	t_dll	*tmp;

	if ((*head) == NULL || (((*head)->next == (*head)->prev)
			&& (*head)->next == (*head)))
		return (0);
	if ((*head)->next == (*head)->prev)
	{
		(*head) = (*head)->next;
		return (0);
	}
	first_node = (*head);      //		A
	last_node = (*head)->prev; //	C
	(*head) = (*head)->next;   //		B
	tmp = first_node->next;
	first_node->next = (*head)->next;
	(*head)->next = last_node->next;
	last_node->next = tmp;
	tmp = first_node->prev;
	first_node->prev = last_node->prev;
	last_node->prev = (*head)->prev;
	(*head)->prev = tmp;
	return (0);
}

int	rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->next;
	return (0);
}
int	reverse_rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->prev;
	return (0);
}
