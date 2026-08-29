/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:17:52 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/29 10:45:55 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_dll **head)
{
	t_dll *first_node;
	t_dll *last_node;
	t_dll *tmp;

	if ((*head) == NULL || (((*head)->next == (*head)->prev) && (*head)->next == (*head)))
		return (0);
	if ((*head)->next == (*head)->prev)
	{
		(*head) = (*head)->next;
		return (0);
	}
	first_node = (*head);	   //		A
	last_node = (*head)->prev; //		C
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

int push_front_node(t_dll **head, t_dll *node)
{
	t_dll *first_node;
	t_dll *last_node;

	if ((*head) == NULL)
	{
		(*head) = node;
		node->next = (*head);
		node->prev = (*head);
	}
	first_node = (*head);
	last_node = (*head)->prev;
	(*head) = node;
	first_node->prev = node;
	last_node->next = node;
	return (0);
}

int push(t_dll **head1, t_dll **head2)
{
	t_dll *first_node;
	t_dll *last_node;

	if ((*head1) == NULL)
		return (0);
	if ((*head1) == (*head1)->next)
	{
		first_node = (*head1);
		(*head1) = NULL;
		push_front_node(head2, first_node);
	}
	last_node = (*head1)->prev;
	first_node = (*head1);
	(*head1) = (*head1)->next;
	(*head1)->prev = last_node;
	last_node->next = (*head1);
	push_front_node(head2, first_node);
	return (1);
}

int rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->next;
	return (0);
}
int reverse_rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->prev;
	return (0);
}
