/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:31:03 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/26 19:57:22 by mbrunial         ###   ########.fr       */
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
			if (!(argv[argc][i] > '0' && argv[argc][i] < '9'))
				return (-1);
		argc--;
	}
	return (0);	
}

int main(int argc, char *argv[])
{
	t_dll **stack1;

	int i = 1;
	if (argc < 2)
		return (0);
	else
	{
		validate_argv(argc, argv);
		while (i < argc)
		{
			// just go for ddl new fuker
		}
		
	}
	return (0);
	
}