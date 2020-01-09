/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:56:03 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:57:12 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst0, const void *restrict src0,
size_t length)
{
	char		*dst;
	const char	*src;

	dst = (char *)dst0;
	src = (char *)src0;
	if (length == 0 || dst == src)
		return (dst0);
	while (length--)
		*dst++ = *src++;
	return (dst0);
}
