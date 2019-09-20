/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:12:21 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:12:50 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*ns;
	char	*start;
	char	*end;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (ft_isspace(*start))
		start++;
	while (ft_isspace(*end))
		end--;
	len = end - start > 0 ? end - start + 1 : 1;
	ns = (char *)malloc(len);
	if (!ns)
		return (NULL);
	ft_strncpy(ns, start, len);
	*(ns + len) = '\0';
	return (ns);
}
