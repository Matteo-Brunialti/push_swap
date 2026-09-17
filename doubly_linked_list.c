/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:07:21 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/17 12:28:23 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The void	free_dll(t_dll **head) is a helper function that free a doubly linked
 * 	list
 *
 * head and it's value (*head) are checked for NULL
 */
void	free_dll(t_dll **head)
{
	t_dll	*next_node;
	t_dll	*current_node;

	if (head == NULL || (*head) == NULL)
		return ;
	current_node = (*head)->next;
	while (current_node != (*head))
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free((*head));
	(*head) = NULL;
}

/* The int	circular_dll_create_front_node(t_dll **head, int num) creates a
 * 	doubly linked list (dll) with the content as a integer.
 * It add new node to a dll and it assues that (*head) is NULL for empty dll.
 * It's a function used in the 42 push_swap project.
 *
 * Error:
 * 		If malloc fail a -1 erro is returned
 *
 * Note:
 * 		the validity of head is not checked.
 */
int	circular_dll_create_front_node(t_dll **head, int num)
{
	t_dll	*new_node;
	t_dll	*first_node;
	t_dll	*last_node;

	new_node = (t_dll *)malloc(sizeof(t_dll));
	if (!new_node)
		return (-1);
	new_node->rank = -1;
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
	t_dll	*curr;

	if ((*stack) == NULL)
		return ;
	curr = (*stack);
	while (curr->next != (*stack))
	{
		printf("%d ", curr->num);
		curr = curr->next;
	}
	printf("%d\n", curr->num);
}

void	reverse_print_dll(t_dll **stack)
{
	t_dll	*curr;

	if ((*stack) == NULL)
		return ;
	curr = (*stack);
	while (curr->prev != (*stack))
	{
		curr = curr->prev;
		printf("%d ", curr->num);
	}
	curr = curr->prev;
	printf("%d\n", curr->num);
}

void	print_dll_rank(t_dll **stack)
{
	t_dll	*curr;

	if ((*stack) == NULL)
		return ;
	curr = (*stack);
	while (curr->next != (*stack))
	{
		printf("%d ", curr->rank);
		curr = curr->next;
	}
	printf("%d\n", curr->rank);
}

int	is_sorted(t_dll *stack)
{
	t_dll *curr;

	if (stack == NULL)
		return (-1);
	curr = stack;
	while (curr->next != stack)
	{
		if (curr->num >= curr->next->num)
		{
			printf("[ERROR] Stack is not sorted\n");
			return (-1);
		}
		curr = curr->next;
	}
	printf("[OK] Stack is sorted!\n");

	return (0);
}