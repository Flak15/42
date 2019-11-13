/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:01:51 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:02:18 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *restrict str, const char *restrict append)
{
	char *save;

	save = str;
	while (*str)
		str++;
	while (1)
	{
		if (!(*str = *append))
			return (save);
		++str;
		++append;
	}
}
