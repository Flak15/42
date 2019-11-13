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
#include <stdio.h>//
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
	// if (*curr == '\0')
	// 	*content = 0;
	// else
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

int		read_file(const int fd, char **content)
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

void	clear_fd(void *content, size_t fd)
{
	(void)fd;
	free(content);
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
	res = read_file(fd, &tmp);
	if (res < BUFF_SIZE && !ft_strlen(tmp))
	{
		// printf("rrr: %ld, tmp: %s\n", res, tmp);
		//ft_lstdelone(&curr, &clear_fd);
		//free(*line);	
		return (0);
	}
	curr->content = tmp;
	get_line(&(curr->content), line);
	return (1);
}


// int main(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;
// 	int		ret;

// 	out = dup(1);
// 	pipe(p);

// 	fd = 1;
// 	dup2(p[1], fd);
// 	write(fd, "abc\n\n", 5);
// 	close(p[1]);
// 	dup2(out, fd);

// 	ret = get_next_line(p[0], &line);
// 	printf("line: %s, res: %d\n", line, ret);
// 	ret = get_next_line(p[0], &line);
// 	printf("line: %s, res: %d\n", line, ret);
// 	ret = get_next_line(p[0], &line);
// 	printf("line: %s, res: %d\n", line, ret);
// 	ret = get_next_line(p[0], &line);
// 	printf("line: %s, res: %d\n", line, ret);
// 	return (0);
// }

// #include <fcntl.h>

// int			main(int argc, char **argv)
// {
	
// 	int		fd;
// 	char		*line;

// 	if (argc == 2)
// 	{
		
// 		fd = open(argv[1], O_RDONLY);
// 		while ((get_next_line(fd, &line)) == 1)
// 		{
// 			ft_putstr(line);
// 			ft_putchar('\n');
// 		}
// 		close(fd);
// 	}
// 	return (0);
// }