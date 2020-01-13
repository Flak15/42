#include "fdf.h"

int		get_heigth(char *file_name)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}


int		get_width(char *file_name)
{
	char *line;
	int fd;
	int width;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return
}

void fill_depth(t_map *map, char *line)
{
	char **nums;
	int i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		map->depth_arr[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
}

void	read_file(char *file_name, t_map *map)
{
	char *line;
	int fd;
	int i;

	map->height = get_heigth(file_name);
	map->width = get_width(file_name);

	map->depth_arr = (int **)malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i <= map-> height)
		map->depth_arr[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(map, line);
		free(line);
	}

}