/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:11:06 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 19:27:57 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char delim)
{
	int			state;
	unsigned	wc;

	state = 0;
	wc = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == delim)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++wc;
		}
		++str;
	}
	return (wc);
}

char		**ft_strsplit(char const *str, char c)
{
	int		strlen;
	char	*temp_str;
	char	**s;
	char	**save_s;

	strlen = 0;
	s = (char **)malloc((count_words((char *)str, c) + 1) * sizeof(char *));
	if ((save_s = s) == NULL || str == NULL)
		return (NULL);
	while (1)
	{
		temp_str = (*str != c && strlen == 0) ? (char *)str : temp_str;
		if ((*str == c || *str == '\0') && strlen > 0)
		{
			*s++ = ft_strsub(temp_str, 0, strlen);
			if ((s - 1) == NULL)
				return (ft_clear_tab(save_s));
			strlen = 0;
		}
		strlen = *str == c ? strlen : strlen + 1;
		if (!*str++)
			break ;
	}
	*s = 0;
	return (save_s);
}
