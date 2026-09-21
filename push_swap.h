/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:08:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 09:34:50 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// doubly linked list struct
typedef struct s_dll
{
	struct s_dll	*next;
	struct s_dll	*prev;
	int				num;
	int				rank;
}					t_dll;

// argument struct
typedef struct s_options
{
	bool			simple;
	bool			medium;
	bool			complex;
	bool			adaptive;
	bool			bench;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_options;

// aglorithm
void				simple_bubble(t_dll **stack1, t_dll **stack2,
						t_options *options, int len_stack1);
void				adaptive(t_dll **stack1, t_dll **stack2, t_options *options,
						int len_stack1);
void				medium_range_sort(t_dll **stack1, t_dll **stack2,
						t_options *options, int len_stack1);
void				complex_radix(t_dll **stack1, t_dll **stack2,
						t_options *options, int len_stack1);
// utils_algorithm
int					my_sqrt(int num);
float				compute_disorder(t_dll **stack);
void				set_rank(t_dll **stack, int len_stack);
void				range_sort_sorting(t_dll **stack1, t_dll **stack2,
						t_options *options, int len_stack2);

// dubly linked list
void				free_dll(t_dll **head);
void				print_dll(t_dll **stack);
int					is_sorted(t_dll *stack);
int					circular_dll_create_front_node(t_dll **head, int num);
void				reverse_print_dll(t_dll **stack);
void				print_dll_rank(t_dll **stack);

// swap
void				swap_sa(t_dll **head, t_options *options);
void				swap_sb(t_dll **head, t_options *options);
void				swap_ss(t_dll **head1, t_dll **head2, t_options *options);

// push
void				push_pa(t_dll **head1, t_dll **head2, t_options *options);
void				push_pb(t_dll **stack_a, t_dll **stack_b,
						t_options *options);

// rotate
void				rotate_ra(t_dll **head, t_options *options);
void				rotate_rb(t_dll **head, t_options *options);
void				rotate_rr(t_dll **head1, t_dll **head2, t_options *options);

// reverse rotate
void				reverse_rotate_ra(t_dll **head, t_options *options);
void				reverse_rotate_rb(t_dll **head, t_options *options);
void				reverse_rotate_rrr(t_dll **head1, t_dll **head2,
						t_options *options);

// validate_args.c
int					validate_args(t_options *options, int argc, char **argv);
long long			is_int(char *str);

// benchmark
int					benchmark(t_options *options, float disorder_val);

// benchmark_utils.c

int					count_digit(int n);
char				*ft_itoa(int n);
size_t				ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*sos(char *s1);

// benchmark_utils2.c
char				*operations(t_options *options);

#endif
