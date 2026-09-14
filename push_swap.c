/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/14 12:13:48 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_dll *stack1 = NULL;
	t_dll *stack2 = NULL;
	t_options options;
	int i;

	if (argc < 2)
		return (0);
	i = argc - 1;
	if (validate_args(argc, argv) == -1)
		return (write(1, "Error\n", 6));
	while (i > 0)
	{
		if (circular_dll_create_front_node(&stack1, is_int(argv[i])) == -1)
			return (write(1, "Error\n", 6));
		i--;
	}
	// print_dll(&stack1);
	bubble(&stack1, &stack2, (argc - 1));
	// printf("---------------------------------------\n");
	// print_dll(&stack1);
	// printf("---------------------------------------\n");
	// reverse_print_dll(&stack1);
	// (void)is_sorted(stack1);
	return (0);
}
