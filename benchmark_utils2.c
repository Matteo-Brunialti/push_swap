/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 09:29:24 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/22 00:38:33 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*operations(t_options *options)
{
	char	*line;

	line = ft_strjoin(sos("[bench] sa: "), ft_itoa(options->sa));
	line = ft_strjoin(line, ft_strjoin(sos(" sb: "), ft_itoa(options->sb)));
	line = ft_strjoin(line, ft_strjoin(sos(" ss: "), ft_itoa(options->ss)));
	line = ft_strjoin(line, ft_strjoin(sos(" pa: "), ft_itoa(options->pa)));
	line = ft_strjoin(line, ft_strjoin(sos(" pb: "), ft_itoa(options->pb)));
	line = ft_strjoin(line, ft_strjoin(sos("\n[bench] ra: "),
				ft_itoa(options->ra)));
	line = ft_strjoin(line, ft_strjoin(sos(" rb: "), ft_itoa(options->rb)));
	line = ft_strjoin(line, ft_strjoin(sos(" rr: "), ft_itoa(options->rr)));
	line = ft_strjoin(line, ft_strjoin(sos(" rra: "), ft_itoa(options->rra)));
	line = ft_strjoin(line, ft_strjoin(sos(" rrb: "), ft_itoa(options->rrb)));
	line = ft_strjoin(line, ft_strjoin(sos(" rrr: "), ft_itoa(options->rrr)));
	line = ft_strjoin(line, sos("\n"));
	return (line);
}
