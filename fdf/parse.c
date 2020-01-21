#include "fdf.h"

int	get_heigth(char *file_name, t_map *map)
{
	char *line;
	int fd;
	int height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		close(fd);
		kill(1);
	}
	height = 0;
	while (get_next_line(fd, &line))
	{

		// printf("w: %d\n", count_words(line, ' '));
		printf("2 %s\n", line);
		if (count_words(line, ' ') != map->width)
		{
			printf("hh%d\n", height);
			kill(5);
		}

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
	if (fd < 0)
	{
		close(fd);
		kill(1);
	}
	get_next_line(fd, &line);
	printf("1 %s\n", line);
	width = count_words(line, ' ');
	printf("w1: %d\n", width);
	free(line);
	close(fd);
	return (width);
}

void fill_depth(int *depth_line, char *line, t_map *map)
{
	char **nums;
	int i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		// if (!ft_isdigit(nums[i])) // check string for nums
		// 	kill(4);
		depth_line[i] = ft_atoi(nums[i]);
		map->max_depth = map->max_depth > depth_line[i] ? map->max_depth : depth_line[i];
		map->min_depth = map->min_depth < depth_line[i] ? map->min_depth : depth_line[i];
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	read_file(char *file_name, t_data *data)
{
	char *line;
	int fd;
	int i;
	t_map *map;

	map = data->map;
	map->width = get_width(file_name);
	map->height = get_heigth(file_name, map);

	if (!(map->depth_arr = (int **)malloc(sizeof(int *) * (map->height + 1))))
		kill(2);
	i = 0;
	while (i <= map->height)
		if (!(map->depth_arr[i++] = (int *)malloc(sizeof(int) * (map->width + 1))))
			kill(2);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		kill(1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_depth(map->depth_arr[i], line, map);
		free(line);
		i++;
	}
	map->depth_arr[i] = 0;
	close(fd);
	return (0);
}
