/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:03:23 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:11:07 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	convert(unsigned short tet)
{
	unsigned long res;

	res = 0;
	res = res | ((unsigned long)(tet & 0xF000) << 48);
	res = res | ((unsigned long)(tet & 0x0F00) << 44);
	res = res | ((unsigned long)(tet & 0x00F0) << 40);
	res = res | ((unsigned long)(tet & 0x000F) << 36);
	return (res);
}

unsigned long	*convert_all(unsigned short *tets)
{
	int				cnt;
	unsigned long	*res;

	cnt = 0;
	while (tets[cnt])
		cnt++;
	res = (unsigned long *)malloc(sizeof(unsigned long) * (cnt + 1));
	res[cnt] = 0;
	while (*tets)
	{
		*res = convert(*tets);
		res++;
		tets++;
	}
	free(tets - cnt);
	return (res - cnt);
}
