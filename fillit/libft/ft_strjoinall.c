/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:04:56 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 19:27:27 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinall(char const **s)
{
	char	*tmp;

	tmp = 0;
	if (!s)
		return (NULL);
	if (!*(s + 1))
		return ((char*)*s);
	while (*(s + 1))
	{
		if (!*s)
			return (NULL);
		if (tmp == 0)
			tmp = (char*)*s;
		if (!(tmp = ft_strjoin(tmp, *(s + 1))))//freeeee
			return (NULL);
		s++;
	}
	return (tmp);
}
