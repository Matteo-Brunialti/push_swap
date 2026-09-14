/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:08:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/14 12:13:30 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

// doubly linked list struct
typedef struct s_dll
{
	struct s_dll	*next;
	struct s_dll	*prev;
	int				num;
}					t_dll;

// argument struct
typedef struct s_options {
	bool simple;
	bool medium;
	bool complex;
	bool adaptive;
	bool bench;
}				t_options;

// aglorithm
void				bubble(t_dll **stack1, t_dll **stack2, int len);

// dubly linked list
void				free_dll(t_dll **head);
void				print_dll(t_dll **stack);
int					is_sorted(t_dll *stack);
int					circular_dll_create_front_node(t_dll **head, int num);
void				reverse_print_dll(t_dll **stack);

// operation.c
int					rotate(t_dll **head);
int					reverse_rotate(t_dll **head);
int					swap(t_dll **head);
int					push(t_dll **head1, t_dll **head2);

// validate_args.c
int					validate_args(int argc, char **argv);
long long			is_int(char *str);
#endif
