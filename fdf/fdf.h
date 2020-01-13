
#include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"
#define PointerMotionMask		(1L<<6)
#define MotionNotify		6
#define WIDTH		700
#define HEIGHT		700
typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_map
{
	int width;
	int height;
	int **depth_arr;
}	t_map;

void	read_file(char *file_name, t_map *map);
int	count_words(char *str, char delim);