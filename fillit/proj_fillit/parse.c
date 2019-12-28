/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:01:06 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:16:42 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	*parse_tet(char *tet_str)
{
	int				tets_len;
	char			*tmp;
	unsigned short	*tets;
	int				i;

	tmp = tet_str;
	tet_str = ft_strrmchr(tet_str, '\n');
	tets_len = ft_strlen(tet_str) / 4;
	tets = (unsigned short *)ft_memalloc(sizeof(short) * (tets_len) + 1);
	tets[tets_len] = 0;
	i = 0;
	while (tet_str[i])
	{
		if (tet_str[i] == '#')
			tets[i / 16] = tets[i / 16] | 1 << (15 - i % 16);
		i++;
	}
	return (tets);
}
