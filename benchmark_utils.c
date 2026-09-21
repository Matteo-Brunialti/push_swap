/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunial <mbrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 09:11:53 by mbrunial          #+#    #+#             */
/*   Updated: 2026/09/21 09:34:02 by mbrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_digit(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	long_n;
	int			i;
	char		*str;

	i = count_digit(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		long_n = -((long long)n);
	}
	else
		long_n = n;
	while (long_n)
	{
		i--;
		str[i] = '0' + (long_n % 10);
		long_n /= 10;
	}
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*sjoined;

	if (s1 == NULL || s2 == NULL)
		return (free(s1), free(s2), NULL);
	sjoined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sjoined)
		return (free(s1), free(s2), NULL);
	i = 0;
	while (s1[i])
	{
		sjoined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sjoined[i + j] = s2[j];
		j++;
	}
	sjoined[i + j] = '\0';
	free(s1);
	free(s2);
	return (sjoined);
}

char	*sos(char *s1)
{
	char	*seallocata;
	size_t	i;

	if (!s1)
		return (NULL);
	seallocata = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!seallocata)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		seallocata[i] = s1[i];
		i++;
	}
	seallocata[i] = '\0';
	return (seallocata);
}
