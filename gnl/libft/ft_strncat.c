/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:08:00 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:22:33 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict str, const char *restrict append, size_t n)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(str);
	len2 = ft_strlen(append);
	if (len2 < n)
	{
		ft_strcpy(&str[len1], append);
	}
	else
	{
		ft_strncpy(&str[len1], append, n);
		str[len1 + n] = '\0';
	}
	return (str);
}
