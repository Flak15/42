
#include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"
#include <math.h>
#include "libft.h"
#include "mlx.h"

#define MAX(a, b) (a > b ? a : b)
#define PointerMotionMask	(1L<<6)
#define MotionNotify		6
#define ButtonPressMask		(1L<<2)
#define ButtonReleaseMask	(1L<<3)
#define ButtonPress			4
#define ButtonRelease		5
#define WIDTH		1280
#define HEIGHT		720
#define DEF_ZOOM	30
#define DEF_PROJ	0.523599
#define DEF_SHIFT	220
#define LMB	1
#define RMB	2
#define WHL_UP	4
#define WHL_DN	5
#define PLUS 24
#define MINUS 27
#define ESCAPE 53
#define ARROW_UP 126
#define ARROW_RIGHT 124
#define ARROW_DOWN 125
#define ARROW_LEFT 123

typedef struct s_map
{
	int width;
	int height;
	int **depth_arr;
	int	min_depth;
	int	max_depth;
}	t_map;

typedef struct s_point
{
	int x;
	int y;
}	t_point;

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
	int		flattening;
	float	proj;
	int		x_shift;
	int		y_shift;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
	int		mb1_pressed;
	int		mb2_pressed;
	t_point	*r_start;
	t_point	*r_end;
	t_map	*map;
}	t_data;

int	read_file(char *file_name, t_data *data);
int		count_words(char *str, char delim);
void	draw_line(int x, int y, int x1, int y1, t_data *data);
void	draw_map(t_data *data);
void	plot(int x, int y, t_data *data, int color);
void	BresenhamLine(int x0, int y0, int x1, int y1, t_data *data, int color);
void	kill(int code);
