/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:01:06 by nventres          #+#    #+#             */
/*   Updated: 2019/12/25 14:30:46 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

char		*read_tet(int fd)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tet;
	char	*ftet;
	int		res;

	tet = ft_strnew(1);
	while ((res = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[res] = '\0';
		ftet = tet;
		tet = ft_strjoin(tet, tmp);
		free(ftet);
	}
	return (tet);
}

int			check_input(char *str)
{
	int	ch;
	int	rows;

	ch = 0;
	rows = 0;
	while (*str)
	{
		if (*str == '\n')
			if (ch == 4)
			{
				ch = 0;
				rows++;
			}
			else if (ch == 0 && rows == 4)
				rows = 0;
			else
				return (1);
		else if (*str == '#' || *str == '.')
			ch++;
		else
			return (1);
		str++;
	}
	return (0);
}

unsigned short		*parse_tet(char *tet_str)
{
	int				tets_len;
	char			*tmp;
	unsigned short	*tets;
	int				i;

	tmp = tet_str;
	tet_str = ft_strrmchr(tet_str, '\n');
	free(tmp);
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

int			check_right(unsigned short tet, int i)
{
	if (i < 0)
		return (0);
	if (tet & 1 << i)
		return (1 + check_bottom(tet, i - 4)
			+ (i % 4 == 0 ? 0 : check_right(tet, i - 1)));
	else
		return (0);
}

int			check_left(unsigned short tet, int i)
{
	if (i > 15)
		return (0);
	if (tet & 1 << i)
		return (1 + ((i + 1) % 4 == 0 ? 0 : check_left(tet, i + 1))
			+ check_bottom(tet, i - 4));
	else
		return (0);
}

int			check_bottom(unsigned short tet, int i)
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

int			check_tet(unsigned short *tets, char *tet_str)
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
		{
			if (tets[j] != 51 && tets[j] != 51 << 1 && tets[j] != 51 << 2 &&
				tets[j] != 51 << 4 && tets[j] != 51 << 5 &&
				tets[j] != 51 << 6 && tets[j] != 51 << 8 &&
				tets[j] != 51 << 9 && tets[j] != 51 << 10)
				return (1);
		}
		else if (res != 4)
			return (1);
		j++;
		i = 15;
	}
	if (j < (int)(ft_strlen(tet_str) / 4))
		return (1);
	return (0);
}

void		shift_top_tet(unsigned short *tets)
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

void		shift_left_tet(unsigned short *tets)
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

int				get_lfig_length(unsigned long tet)
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

int				get_lfig_height(unsigned long tet)
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

unsigned long	proccess(unsigned long *field, unsigned long *tets,
	int index, int f_size)
{
	unsigned long	l_tet;
	unsigned long	res;
	int				h_shift;
	int				v_shift;
	int				cnt;

	cnt = 0;
	h_shift = 1;
	v_shift = 1;
	l_tet = (tets[index]);
	if (l_tet == 0)
		return (*field);
	while (1)
	{
		while ((*field | l_tet) != (*field + l_tet) || (cnt != 0))
		{
			l_tet = l_tet >> 1;
			if (h_shift + get_lfig_length(tets[index]) > f_size)
			{
				l_tet = l_tet >> (8 - h_shift);
				h_shift = 1;
				v_shift++;
			}
			else
				h_shift++;
			if (get_lfig_height(tets[index]) + (v_shift) > f_size + 1)
				return (1);
			cnt = cnt == 0 ? 0 : cnt - 1;
		}
		*field = *field | l_tet;
		if ((res = proccess(field, tets, index + 1, f_size)) == 1)
		{
			*field = *field ^ l_tet;
			cnt++;
		}
		else
		{
			tets[index] = l_tet;
			break ;
		}
	}
	return (res);
}

void		render_f(unsigned long *tets, int f_size)
{
	int	i;
	int	tet;
	int	printed;

	i = 63;
	while (i >= 0)
	{
		tet = 0;
		printed = 0;
		if ((i + 1) % 8 == 0 && (i / 8 >= 8 - f_size) && i != 63)
			ft_putchar('\n');
		while (tets[tet])
		{
			if (tets[tet++] & ((unsigned long)1 << (i)))
			{
				ft_putchar('A' + tet - 1);
				printed = 1;
				break ;
			}
		}
		if (!printed && (i % 8 >= 8 - f_size) && (i / 8 >= 8 - f_size))
			ft_putchar('.');
		i--;
	}
	ft_putchar('\n');
}

void		get_solution(unsigned long *tets)
{
	unsigned long	f;
	int				i;

	f = 0;
	i = get_lfig_length(tets[0]) > get_lfig_height(tets[0]) ?
		get_lfig_length(tets[0]) : get_lfig_height(tets[0]);
	while (i <= 8)
	{
		f = proccess(&f, tets, 0, i);
		if (f != 1)
			break ;
		i++;
	}
	if (i > 8)
		ft_putstr("error\n");
	else
		render_f(tets, i);
}

int			main(int argc, char **argv)
{
	int				fd;
	char			*tet;
	unsigned short	*tets_arr;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <file>\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	tet = read_tet(fd);
	if (check_input(tet))
	{
		ft_putstr("error\n");
		return (1);
	}
	tets_arr = parse_tet(tet);
	if (check_tet(tets_arr, tet))
	{
		ft_putstr("error\n");
		return (1);
	}
	shift_tets(tets_arr);
	get_solution(convert_all(tets_arr));
	return (0);
}
