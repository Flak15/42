/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:06:23 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:21:06 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*ns;
	char			*save_ns;
	unsigned int	cnt;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ns = (char *)malloc(len + 1);
	if (!ns)
		return (NULL);
	cnt = 0;
	save_ns = ns;
	while (*s)
	{
		*ns = f(cnt++, *s++);
		ns++;
	}
	*ns = '\0';
	return (save_ns);
}
