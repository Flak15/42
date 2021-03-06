/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:08:17 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:29:06 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (*s1 != *s2++)
			return ((*(unsigned char *)s1 - *(unsigned char *)--s2));
		if (!*s1)
			return (0);
		s1++;
		n--;
	}
	return (0);
}
