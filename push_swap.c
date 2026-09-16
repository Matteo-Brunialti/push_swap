/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/16 12:31:33 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_dll		*stack1;
	t_dll		*stack2;
	t_options	options;
	int			i;
	int 		shift;

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
	printf("disorder : %f\n", compute_disorder(&stack1));
	if (options.adaptive)
		printf("\n");
		// do something with adaptive
	else if (options.complex)
		printf("\n");
		// do complex algorithm
	else if (options.medium)
		printf("\n");
		// do medium algorithm
	else if (options.simple)
		bubble(&stack1, &stack2, argc - shift - 1, &options);
	if (options.bench)
		// so somthing with bench
	return (0);
}
