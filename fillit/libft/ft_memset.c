/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:58:17 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:58:39 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char *d;

	if (n)
	{
		d = (unsigned char *)dst;
		while (1)
		{
			*d = (unsigned char)c;
			d++;
			if (--n == 0)
				break ;
		}
	}
	return (dst);
}
