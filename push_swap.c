/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/28 17:51:41 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dll	*stack1;
	int		i;

	stack1 = NULL;
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
	// free sto cazzo
	return (0);
}
