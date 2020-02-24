#include "fdf.h"

int	get_heigth(int fd, t_map *map)
{
	char *line;
	int height;

	// fd = open(file_name, O_RDONLY, 0);
	// if (fd < 0)
	// {
	// 	close(fd);
	// 	kill(1);
	// }
	height = 0;
	while (get_next_line(fd, &line))
	{
	// (void)map;
	printf("line: %s\n", line);
	printf("err width: %d\n", map->width);
		if (count_words(line, ' ') != map->width)
		{

			// 
			
			kill(5);
		}
		height++;
		free(line);
	}
	close(fd);
	return (height + 1);
}

int		get_width(int fd)
{
	char *line;
	int width;
	
	get_next_line(fd, &line);
	width = count_words(line, ' ');
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
		// if (!ft_isdigit(*(nums[i])))
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
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		close(fd);
		kill(1);
	}
	map->width = get_width(fd);
	map->height = get_heigth(fd, map);
	close(fd);
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
