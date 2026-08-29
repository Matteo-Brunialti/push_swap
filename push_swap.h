/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:08:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/29 10:43:16 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_dll
{
	int num;
	struct s_dll *next;
	struct s_dll *prev;
} t_dll;

void print_dll(t_dll **stack);
int circular_dll_create_front_node(t_dll **head, int num);
int rotate(t_dll **head);
int reverse_rotate(t_dll **head);
int swap(t_dll **head);
int push(t_dll **head1, t_dll **head2);
int push_front_node(t_dll **head, t_dll *node);
#endif
