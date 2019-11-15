/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:09:25 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 19:29:38 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return ((char *)str);
}
