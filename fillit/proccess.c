/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:05:50 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:18:16 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned long	make_shift(unsigned long l_tet, int *h_shift,
	int *v_shift)
{
	l_tet = l_tet >> (8 - *h_shift);
	*h_shift = 1;
	(*v_shift)++;
	return (l_tet);
}

static void				rm_tet(unsigned long *field, int *cnt,
	unsigned long l_tet)
{
	*field = *field ^ l_tet;
	(*cnt)++;
}

static int				get_tet_pos(unsigned long *field, unsigned long *l_tet,
	int *sizes, unsigned long tet)
{
	while ((*field | *l_tet) != (*field + *l_tet) || (sizes[3] != 0))
	{
		*l_tet = *l_tet >> 1;
		if (sizes[0] + get_lfig_length(tet) > sizes[2])
			*l_tet = make_shift(*l_tet, &sizes[0], &sizes[1]);
		else
			(sizes[0])++;
		if (get_lfig_height(tet) + (sizes[1]) > sizes[2] + 1)
			return (1);
		sizes[3] = sizes[3] == 0 ? 0 : sizes[3] - 1;
	}
	return (0);
}

unsigned long			proccess(unsigned long *field, unsigned long *tets,
	int index, int f_size)
{
	unsigned long	l_tet;
	int				sizes[4];

	sizes[0] = 1;
	sizes[1] = 1;
	sizes[2] = f_size;
	sizes[3] = 0;
	if ((l_tet = tets[index]) == 0)
		return (0);
	while (1)
	{
		if (get_tet_pos(field, &l_tet, sizes, tets[index]) == 1)
			return (1);
		*field = *field | l_tet;
		if (proccess(field, tets, index + 1, f_size) == 1)
			rm_tet(field, &sizes[3], l_tet);
		else
		{
			tets[index] = l_tet;
			return (0);
		}
	}
}
