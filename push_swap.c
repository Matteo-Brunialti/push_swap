/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/20 11:36:46 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dll		*stack1;
	t_dll		*stack2;
	t_options	options;
	int			i;
	int			shift;
	float		disorder;

	stack1 = NULL;
	stack2 = NULL;
	if (argc < 2)
		return (0);
	shift = validate_args(&options, argc, argv);
	if (shift == -1)
		return (write(1, "Error\n", 6));
	i = argc;
	while (--i > (0 + shift))
		if (circular_dll_create_front_node(&stack1, is_int(argv[i])) == -1)
			return (write(1, "Error\n", 6));
	set_rank(&stack1, argc - shift - 1);
	disorder = compute_disorder(&stack1);
	print_dll(&stack1);
	printf("below are the rank :\n");
	print_dll_rank(&stack1);
	if (options.adaptive)
		adaptive(&stack1, &stack2, &options, argc - shift - 1);
	else if (options.complex)
		complex_radix(&stack1, &stack2, &options, argc - shift - 1);
	else if (options.medium)
		medium_range_sort(&stack1, &stack2, &options, argc - shift -1);
	else if (options.simple)
		simple_bubble(&stack1, &stack2, &options, argc - shift - 1);
	if (options.bench)
		benchmark(&options, disorder);
	print_dll(&stack1);
	return (0);
}
