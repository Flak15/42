/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lfig_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:04:17 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:16:36 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_lfig_length(unsigned long tet)
{
	if (tet & 0x1000000000000000)
		return (4);
	else if ((tet & 0x2000000000000000)
		|| (tet & 0x20000000000000))
		return (3);
	else if (tet & 0x8000000000)
		return (1);
	else
		return (2);
}

int	get_lfig_height(unsigned long tet)
{
	if (tet & 0x8000000000)
		return (4);
	else if ((tet & 0x800000000000)
		|| (tet & 0x400000000000))
		return (3);
	else if (tet & 0x1000000000000000)
		return (1);
	else
		return (2);
}
