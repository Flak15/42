
#include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"
#include <math.h>
#include "libft.h"
#include "mlx.h"
#define MAX(a, b) (a > b ? a : b)
#define PointerMotionMask		(1L<<6)
#define MotionNotify		6
#define WIDTH		700
#define HEIGHT		700
#define DEF_ZOOM	30
#define DEF_PROJ	0.8
#define DEF_SHIFT	220

typedef struct s_map
{
	int width;
	int height;
	int **depth_arr;
}	t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		zoom;
	int		proj;
	t_map	*map;
}	t_data;

typedef struct s_point
{
	int x;
	int y;
}	t_point;



void	read_file(char *file_name, t_map *map);
int		count_words(char *str, char delim);
void	draw_line(float x, float y, float x1, float y1, t_data *data);
void	draw_map(t_data *data);