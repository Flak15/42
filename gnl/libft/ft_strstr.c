/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:11:39 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:11:53 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char *s;
	char *f;

	if (!*to_find)
		return ((char *)str);
	while (*str)
	{
		s = (char *)str;
		f = (char *)to_find;
		while (*s && *f && !(*f - *s))
		{
			s++;
			f++;
		}
		if (!*f)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
