/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:16:23 by nventres          #+#    #+#             */
/*   Updated: 2019/09/22 15:24:49 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	get_line(void **content, char **line)
{
	char	*curr;
	char	*tmp;

	curr = *content;
	while (*curr && *curr != '\n')
		curr++;
	*line = ft_strsub(*content, 0, curr - (char*)*content + 1);
	(*line)[curr - (char*)*content] = '\0';
	tmp = *content;
	if (*curr == '\0')
		ft_strclr(*content);
	else
		*content = ft_strdup(curr + 1);
	free(tmp);
}

t_list	*get_curr(int fd, t_list **files)
{
	t_list	*tmp;

	tmp = *files;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(files, tmp);
	return (tmp);
}

static int		read_file(const int fd, char **content)
{
	int		res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char			*tmp;
	size_t			res;
	static t_list	*files;
	t_list			*curr;
	char			str[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, str, 0)) < 0)
		return (-1);
	curr = get_curr(fd, &files);
	if (!curr)
		return (-1);
	tmp = curr->content;
	if ((int)(res = read_file(fd, &tmp)) == -1)
		return (-1);
	if (res < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	curr->content = tmp;
	get_line(&(curr->content), line);
	return (1);
}
