/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:11:06 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 17:41:00 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char *str, char delim)
{
	int			state;
	unsigned	wc;

	state = 0;
	wc = 0;
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

static char	**ft_clear_all(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *str, char c)
{
	int		strlen;
	char	*temp_str;
	char	**s;
	char	**save_s;

	if (!(temp_str = (char *)str))
		return (NULL);
	strlen = 0;
	s = (char **)malloc((count_words(temp_str, c) + 1) * sizeof(char *));
	if ((save_s = s) == NULL)
		return (NULL);
	while (1)
	{
		temp_str = (*str != c && strlen == 0) ? (char *)str : temp_str;
		if ((*str == c || *str == '\0') && strlen > 0)
		{
			*s++ = ft_strsub(temp_str, 0, strlen);
			if ((s - 1) == NULL)
				return (ft_clear_all(save_s));
			strlen = 0;
		}
		strlen = *str == c ? strlen : strlen + 1;
		if (!*str++)
			break ;
	}
	*s = 0;
	return (save_s);
}
