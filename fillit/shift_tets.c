/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:01:21 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:17:16 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	shift_top_tet(unsigned short *tets)
{
	int i;

	i = 15;
	while (!(*tets & 1 << i))
		i--;
	while (i < 12)
	{
		*tets = *tets << 4;
		i += 4;
	}
}

static void	shift_left_tet(unsigned short *tets)
{
	int i;
	int j;

	j = 15;
	while (j >= 12)
	{
		i = j;
		while (i > 0)
		{
			if (*tets & (1 << i))
			{
				while ((i + 1) % 4 != 0)
				{
					*tets = *tets << 1;
					i++;
				}
				return ;
			}
			i -= 4;
		}
		j--;
	}
}

void		shift_tets(unsigned short *tets)
{
	while (*tets)
	{
		shift_top_tet(tets);
		shift_left_tet(tets);
		tets++;
	}
}
