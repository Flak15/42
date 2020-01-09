/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:54:46 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:55:12 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;

	ptr = (const unsigned char *)s;
	if (n)
	{
		while (1)
		{
			if (*ptr++ == (unsigned char)c)
				return ((void *)(ptr - 1));
			if (--n == 0)
				break ;
		}
	}
	return (NULL);
}
