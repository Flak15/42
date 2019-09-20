/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:06:00 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:20:33 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*ns;
	char	*save_ns;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ns = (char *)malloc(len + 1);
	if (!ns)
		return (NULL);
	save_ns = ns;
	while (*s)
	{
		*ns = f(*s++);
		ns++;
	}
	*ns = '\0';
	return (save_ns);
}
