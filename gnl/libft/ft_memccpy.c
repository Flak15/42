/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:41 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:21:54 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	unsigned char *dp;
	unsigned char *sp;
	unsigned char uc;

	uc = (unsigned char)c;
	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	if (n)
		while (1)
		{
			if ((*dp++ = *sp++) == uc)
				return ((void *)dp);
			if (--n == 0)
				break ;
		}
	return (0);
}
