/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:04:56 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 19:27:27 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ns;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ns = (char *)malloc(len + 1);
	if (!ns)
		return (NULL);
	while (*s1)
		*ns++ = *s1++;
	while (*s2)
		*ns++ = *s2++;
	*ns = '\0';
	return (ns - len);
}
