/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/29 10:45:30 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_dll *stack1 = NULL;
	t_dll *stack2 = NULL;
	int i;

	i = argc - 1;
	if (argc < 2)
		return (0);
	else
	{
		// if (validate_argv(argc, argv) == -1)
		// 	return (write(1, "Error\n", 6));
		while (i > 0)
		{
			circular_dll_create_front_node(&stack1, atoi(argv[i]));
			i--;
		}
	}
	printf("-------original stack-----------\n");
	print_dll(&stack1);
	printf("--------operation swap--------\n");
	swap(&stack1);
	print_dll(&stack1);
	printf("--------operation rotate--------\n");
	rotate(&stack1);
	print_dll(&stack1);
	printf("--------operation reverse rotate--------\n");
	reverse_rotate(&stack1);
	print_dll(&stack1);
	printf("--------operation push --------\n");
	push(&stack1, &stack2);
	printf("ocho stack 1\n");
	print_dll(&stack1); // free sto cazzo
	printf("ocho stack 2\n");
	print_dll(&stack2); // free sto cazzo
	
	return (0);
}
