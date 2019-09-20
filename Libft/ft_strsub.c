/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:11:58 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:12:10 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (!s)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, (char *)s + start, len);
	*(res + len) = '\0';
	return (res);
}
