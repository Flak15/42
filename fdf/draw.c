#include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;
	
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(DEF_PROJ);
	*y = (prev_x + prev_y) * sin(DEF_PROJ) - z;
}

void plot(int x, int y, t_data *data, int color)
{
	int i;

	if (x < WIDTH && y < HEIGHT && y > 0 && x > 0)
	{
		i = (x * 4) + (y * data->size_line);
		data->data_addr[i] = color;
		data->data_addr[i + 1] = color >> 8;
		data->data_addr[i + 2] = color >> 16;
	}
}

void	rot_x(int *y, int *z, t_data *data)
{
	double angle; 
	int prev_y;

	prev_y = *y;
	angle = data->rotate_x;
	// *y = (prev_y - (data->map->height - 1) * data->zoom / 2) * cos(angle) + *z * sin(angle);
	*y = (prev_y) * cos(angle) + *z * sin(angle);
	*z = -prev_y * sin(angle) + *z * cos(angle);
}

void	rot_y(int *x, int *z, t_data *data)
{
	double angle; 
	int prev_x;

	angle = data->rotate_y;
	prev_x = *x;
	*x = (prev_x) * cos(angle) + *z * sin(angle);
	// *x = (prev_x - (data->map->width - 1) * data->zoom / 2) * cos(angle) + *z * sin(angle);
	*z = -prev_x * sin(angle) + *z * cos(angle);
}

static void	rot_z(int *x, int *y, t_data *data)
{
	double angle; 
	int prev_x;
	int prev_y;

	angle = data->rotate_z;
	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_x * sin(angle) + prev_y * cos(angle);
}


void zoom(int *x, int *x1, int *y, int *y1, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

void shift(int *x, int *x1, int *y, int *y1, t_data *data)
{
	*x += data->x_shift;
	*y += data->y_shift;
	*x1 += data->x_shift;
	*y1 += data->y_shift;
}

int		get_color(int z, int z1, t_data *data)
{
	int red;
	int green;
	int blue;
	float percent;

	
	percent = (float)(MAX(z, z1) - data->map->min_depth) / 
		(float)abs(data->map->max_depth - data->map->min_depth);
	red = 101 * (1 - percent) + (0xff * percent);
	green = 67  * (1 - percent) + (0xff * percent);
	blue = 33  * (1 - percent) + (0xff * percent);
	return ((red << 16) | (green << 8) | blue);
	
}

void	draw_line(int x, int y, int x1, int y1, t_data *data)
{
	int z;
	int z1;
	int color;

	z = data->map->depth_arr[(int)y][(int)x];
	z1 = data->map->depth_arr[(int)y1][(int)x1];
	color =  get_color(z, z1, data);
	zoom(&x, &x1, &y, &y1, data);
	z *= data->flattening;
	z1 *= data->flattening;
	
	rot_x(&y, &z, data);
	rot_x(&y1, &z1, data);
	rot_y(&x, &z, data);
	rot_y(&x1, &z1, data);
	rot_z(&x, &y, data);
	rot_z(&x1, &y1, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	shift(&x, &x1, &y, &y1, data);
	
	BresenhamLine(x, y, x1, y1, data, color);
}


void swap(int *x, int *x1)
{
	int temp;

	temp = *x;
	*x = *x1;
	*x1 = temp;
}

void BresenhamLine(int x0, int y0, int x1, int y1, t_data *data, int color)
{
	int steep;

	steep = abs(y1 - y0) > abs(x1 - x0) ? 1 : 0; 
	if (steep)
	{
		swap(&x0, &y0); 
		swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	int dx = x1 - x0;
	int dy = abs(y1 - y0);
	int error = dx / 2;
	int ystep = (y0 < y1) ? 1 : -1;
	while ((x0 - x1) || (y0 - y1))
	{
		plot(steep ? y0 : x0, steep ? x0 : y0, data, color);
		error -= dy;
		if (error < 0)
		{
			y0 += ystep;
			error += dx;
		}
		x0++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			
			if (x < data->map->width - 1)
				draw_line(x, y, x + 1, y, data);
			if (y < data->map->height - 1)
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	
}