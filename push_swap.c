/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/27 20:56:08 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int validate_argv(int argc, char *argv[])
{
	int i;
	while (argc > 1)
	{
		i = 0;
		while (argv[argc][i] != '\0')
		{
			if (!(argv[argc][i] > '0' && argv[argc][i] < '9'))
				return (-1);
			i++;
		}
		argc--;
	}
	return (0);	
}

int main(int argc, char *argv[])
{
	t_dll *stack1;

	stack1 = NULL;
	int i = argc -1 ;
	if (argc < 2)
		return (0);
	else
	{
		//validate_argv(argc, argv);
		while (i > 0)
		{

			create_dll_node_front(&stack1, atoi(argv[i]));
			i--;
		}
		print_dll(&stack1);
	}
	// free sto cazzo
	return (0);
	
}
