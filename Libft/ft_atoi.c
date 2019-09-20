/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:41:42 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 19:39:43 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MAX 9223372036854775807U
#define LONG_MIN -9223372036854775808U

static long		ft_atol(const char *str)
{
	int				i;
	int				sign;
	unsigned long	n;
	unsigned long	cutoff;
	int				cutlim;

	i = 0;
	n = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? 1 : 0;
	cutoff = sign ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % 10;
	cutoff /= 10;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		if (n > cutoff || (n == cutoff && (str[i] - '0') > cutlim))
			return (sign ? LONG_MIN : LONG_MAX);
		i++;
	}
	n = sign ? -n : n;
	return (n);
}

int				ft_atoi(const char *str)
{
	return (int)ft_atol(str);
}
