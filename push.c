/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:15:25 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/15 12:10:13 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_front_node(t_dll **head, t_dll *node)
{
	t_dll	*first_node;
	t_dll	*last_node;

	if ((*head) == NULL)
	{
		(*head) = node;
		node->next = (*head);
		node->prev = (*head);
		return (0);
	}
	first_node = (*head);
	last_node = (*head)->prev;
	node->next = first_node;
	node->prev = last_node;
	(*head) = node;
	first_node->prev = node;
	last_node->next = node;
	return (0);
}

/* Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
static int	push(t_dll **head1, t_dll **head2)
{
	t_dll	*first_node;
	t_dll	*last_node;

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
	return (0);
}

void push_pa(t_dll **head1, t_dll **head2, t_options *options)
{
	push(head1, head2);
	write(1, "pa\n", 3);
	if (options->bench)
		(options->pa)++;
}

void push_pb(t_dll **head1, t_dll **head2, t_options *options)
{
	push(head1, head2);
	write(1, "pb\n", 3);
	if (options->bench)
		(options->pb)++;
}