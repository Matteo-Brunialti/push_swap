/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 19:08:01 by mbrunial          #+#    #+#             */
/*   Updated: 2026/08/26 19:30:21 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if !defined PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>

typedef struct s_dll
{
	int num;
	t_dll *next;
	t_dll *prev;
} t_dll;


# endif
