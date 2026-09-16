/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:46:13 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/16 17:12:48 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of stack by one.
 * The first element becomes the last one.
 */
static int	rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->next;
	return (0);
}

void	rotate_ra(t_dll **head, t_options *options)
{
	rotate(head);
	write(1, "ra\n", 3);
	if (options->bench)
		(options->ra)++;
}

void	rotate_rb(t_dll **head, t_options *options)
{
	rotate(head);
	write(1, "rb\n", 3);
	if (options->bench)
		(options->rb)++;
}

void	rotate_rr(t_dll **head1, t_dll **head2, t_options *options)
{
	rotate(head1);
	rotate(head2);
	write(1, "rr\n", 3);
	if (options->bench)
		(options->rr)++;
}