/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:16:23 by nventres          #+#    #+#             */
/*   Updated: 2020/01/21 19:47:13 by nventres         ###   ########.fr       */
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
		free(tmp); //??????????????????
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







// static t_arr	*newlist(const int fd)
// {
// 	t_arr	*new;

// 	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
// 		return (NULL);
// 	new->fd = fd;
// 	new->rest = ft_strnew(BUFF_SIZE);
// 	new->next = NULL;
// 	return (new);
// }

// static char		*checkrest(char **p_n, char *rest)
// {
// 	char *str;

// 	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
// 	{
// 		str = ft_strsub(rest, 0, *p_n - rest);
// 		ft_strcpy(rest, ++(*p_n));
// 	}
// 	else
// 	{
// 		str = ft_strnew(ft_strlen(rest) + 1);
// 		ft_strcat(str, rest);
// 		ft_strclr(rest);
// 	}
// 	return (str);
// }

// static int		get_line(const int fd, char **line, char *rest)
// {
// 	char			buf[BUFF_SIZE + 1];
// 	char			*p_n;
// 	char			*tmp;
// 	int				rd;

// 	p_n = NULL;
// 	rd = 1;
// 	*line = checkrest(&p_n, rest);
// 	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
// 	{
// 		buf[rd] = '\0';
// 		if ((p_n = ft_strchr(buf, '\n')) != NULL)
// 		{
// 			ft_strcpy(rest, ++p_n);
// 			ft_strclr(--p_n);
// 		}
// 		tmp = *line;
// 		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
// 			return (-1);
// 		ft_strdel(&tmp);
// 	}
// 	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static t_arr	*list;
// 	t_arr			*tmp;
// 	int				ret;

// 	if (fd < 0 || line == 0)
// 		return (-1);
// 	if (!list)
// 		list = newlist(fd);
// 	tmp = list;
// 	while (tmp->fd != fd)
// 	{
// 		if (tmp->next == NULL)
// 			tmp->next = newlist(fd);
// 		tmp = tmp->next;
// 	}
// 	ret = get_line(fd, line, tmp->rest);
// 	return (ret);
// }
