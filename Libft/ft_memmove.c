/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:57:37 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:58:13 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;
	char *lasts;
	char *lastd;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
		while (len--)
			*lastd-- = *lasts--;
	return (dst);
}
