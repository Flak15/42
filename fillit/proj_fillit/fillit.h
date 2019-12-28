/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:18:27 by nventres          #+#    #+#             */
/*   Updated: 2019/12/28 14:29:05 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 8
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

char			*read_tet(int fd);
unsigned short	*parse_tet(char *tet_str);
int				check_bottom(unsigned short tet, int i);
int				check_left(unsigned short tet, int i);
int				check_right(unsigned short tet, int i);
int				check_tet(unsigned short *tets, char *tet_str);
void			render_f(unsigned long *tets, int i);
unsigned long	proccess(unsigned long *field, unsigned long *tets,
	int index, int f_size);
int				get_lfig_length(unsigned long tet);
int				get_lfig_height(unsigned long tet);
unsigned long	*convert_all(unsigned short *tets);
unsigned long	convert(unsigned short tet);
void			shift_tets(unsigned short *tets);
char			*parse(char *argv);
#endif
