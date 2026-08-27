/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:08:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/27 20:16:16 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if !defined PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <stdlib.h>

typedef struct s_dll
{
	int num;
	struct s_dll *next;
	struct s_dll *prev;
} t_dll;



void print_dll(t_dll **stack);
int create_dll_node_front(t_dll **head, int num);
# endif
