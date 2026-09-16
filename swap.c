/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:42:50 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/16 17:12:46 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements at the top of stack.
 * Do nothing if there is only one or no elements.
 */
int	swap(t_dll **head)
{
	t_dll	*first_node;
	t_dll	*last_node;
	t_dll	*third_node;

	if ((*head) == NULL || (((*head)->next == (*head)->prev)
			&& (*head)->next == (*head)))
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
	(*head)->next = first_node;
	last_node->next = (*head);
	third_node->prev = first_node;
	first_node->prev = (*head);
	(*head)->prev = last_node;
	return (0);
}

void	swap_sa(t_dll **head, t_options *options)
{
	swap(head);
	write(1, "sa\n", 3);
	if (options->bench)
		(options->sa)++;
}

void	swap_sb(t_dll **head, t_options *options)
{
	swap(head);
	write(1, "sb\n", 3);
	if (options->bench)
		(options->sb)++;
}

void	swap_ss(t_dll **head1, t_dll **head2, t_options *options)
{
	swap(head1);
	swap(head2);
	write(1, "ss\n", 3);
	if (options->bench)
		(options->ss)++;
}
