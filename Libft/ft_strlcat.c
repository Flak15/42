/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:05:28 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:05:33 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	const char	*savedest;
	size_t		n;
	size_t		handled_len;

	savedest = dest;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	handled_len = dest - savedest;
	n = size - handled_len;
	if (n == 0)
		return (ft_strlen(src) + handled_len);
	n--;
	while (*src && n)
	{
		*dest = *src;
		n--;
		dest++;
		src++;
	}
	handled_len = dest - savedest;
	*dest = '\0';
	return (ft_strlen(src) + handled_len);
}
