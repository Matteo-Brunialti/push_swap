/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:17:52 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/09 20:03:06 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements at the top of stack.
 * Do nothing if there is only one or no elements.
 */
int swap(t_dll **head)
{
	t_dll *first_node;
	t_dll *last_node;
	t_dll *third_node;

	if ((*head) == NULL || (((*head)->next == (*head)->prev) && (*head)->next == (*head)))
		return (0);
	if ((*head)->next == (*head)->prev)
	{
		(*head) = (*head)->next;
		return (0);
	}
	first_node = (*head);	   
	last_node = (*head)->prev; 
	(*head) = (*head)->next;   
	third_node = (*head)->next;
	first_node->next = third_node;
	(*head)->next =  first_node; 
	last_node->next = (*head);
	third_node->prev = first_node;
	first_node->prev = (*head);
	(*head)->prev = last_node;

	
	return (0);
}

static int push_front_node(t_dll **head, t_dll *node)
{
	t_dll *first_node;
	t_dll *last_node;

	if ((*head) == NULL)
	{
		(*head) = node;
		node->next = (*head);
		node->prev = (*head);
		return (0);
	}
	first_node = (*head);
	last_node = (*head)->prev;
	(*head) = node;
	first_node->prev = node;
	last_node->next = node;
	return (0);
}

/* Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
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
		return (0);
	}
	last_node = (*head1)->prev;
	first_node = (*head1);
	(*head1) = (*head1)->next;
	(*head1)->prev = last_node;
	last_node->next = (*head1);
	push_front_node(head2, first_node);
	return (1);
}

/* Shift up all elements of stack by one.
 * The first element becomes the last one.
 */
int rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->next;
	return (0);
}

/* Shift down all elements of stack by one.
 * The last element becomes the first one.
 */
int reverse_rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->prev;
	return (0);
}
