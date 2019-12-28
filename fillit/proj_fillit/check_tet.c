/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:00:18 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:16:25 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_right(unsigned short tet, int i)
{
	if (i < 0)
		return (0);
	if (tet & 1 << i)
		return (1 + check_bottom(tet, i - 4)
			+ (i % 4 == 0 ? 0 : check_right(tet, i - 1)));
	else
		return (0);
}

int	check_left(unsigned short tet, int i)
{
	if (i > 15)
		return (0);
	if (tet & 1 << i)
		return (1 + ((i + 1) % 4 == 0 ? 0 : check_left(tet, i + 1))
			+ check_bottom(tet, i - 4));
	else
		return (0);
}

int	check_bottom(unsigned short tet, int i)
{
	if (i < 0)
		return (0);
	if (tet & 1 << i)
		return (1 + ((i + 1) % 4 == 0 ? 0 : check_left(tet, i + 1))
			+ check_bottom(tet, i - 4)
			+ (i % 4 == 0 ? 0 : check_right(tet, i - 1)));
	else
		return (0);
}

int	check_tet(unsigned short *tets, char *tet_str)
{
	int i;
	int j;
	int res;

	i = 15;
	j = 0;
	while (tets[j])
	{
		while (!(tets[j] & 1 << i))
			i--;
		res = 1 + check_right(tets[j], i - 1) + check_bottom(tets[j], i - 4);
		if (res == 6)
			if (tets[j] != 51 && tets[j] != 51 << 1 && tets[j] != 51 << 2 &&
			tets[j] != 51 << 4 && tets[j] != 51 << 5 && tets[j] != 51 << 6 &&
			tets[j] != 51 << 8 && tets[j] != 51 << 9 && tets[j] != 51 << 10)
				return (1);
		if (res != 4 && res != 6)
			return (1);
		j++;
		i = 15;
	}
	if (j < (int)(ft_strlen(ft_strrmchr(tet_str, '\n')) / 16))
		return (1);
	free(tet_str);
	return (0);
}
