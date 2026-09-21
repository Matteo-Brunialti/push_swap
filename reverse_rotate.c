/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:05:38 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 08:44:11 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift down all elements of stack by one.
 * The last element becomes the first one.
 */
static int	reverse_rotate(t_dll **head)
{
	if ((*head) == NULL)
		return (0);
	(*head) = (*head)->prev;
	return (0);
}

void	reverse_rotate_ra(t_dll **head, t_options *options)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
	if (options->bench)
		(options->rra)++;
}

void	reverse_rotate_rb(t_dll **head, t_options *options)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
	if (options->bench)
		(options->rrb)++;
}

void	reverse_rotate_rrr(t_dll **head1, t_dll **head2, t_options *options)
{
	reverse_rotate(head1);
	reverse_rotate(head2);
	write(1, "rrr\n", 3);
	if (options->bench)
		(options->rrr)++;
}
