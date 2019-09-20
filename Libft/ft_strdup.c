/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:03:38 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:03:58 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(str) + 1;
	copy = (char *)malloc(size);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, size);
	return (copy);
}
