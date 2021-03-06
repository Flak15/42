/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:02:22 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:02:33 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *p, int ch)
{
	while (1)
	{
		if (*p == (char)ch)
			return ((char *)p);
		if (!*p)
			return (0);
		p++;
	}
}
