/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:09:55 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:09:59 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	flen;
	int		res;

	if (!*find)
		return ((char *)s);
	flen = ft_strlen(find);
	res = 1;
	while (*s && flen <= slen && (res = ft_strncmp(s, find, flen)))
	{
		slen--;
		s++;
	}
	return (res ? NULL : (char *)s);
}
