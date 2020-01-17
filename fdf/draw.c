#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(DEF_PROJ);
	*y = (*x + *y) * sin(DEF_PROJ) - z;
}

void plot(int x, int y, t_data *data, int color, float intense)
{
	int i;
	
	i = (x * 4) + (y * data->size_line);
	data->data_addr[i] = color * intense;
	data->data_addr[i + 1] = (color >> 8) * intense;
	data->data_addr[i + 2] = (color >> 16) * intense;
}

void	rot_x(float *x, float *y, int *z, t_data *data)
{
	(void)(x);
	
	
	double angle = data->rotate_x;
	*y = *y * cos(angle) + *z * sin(angle);
	*z = -(*y) * sin(angle) + *z * cos(angle);
}

void	rot_y(float *x, float *y, int *z, t_data *data)
{
	(void)(y);
	
	
	double angle = data->rotate_y;
	*x = *x * cos(angle) + *z * sin(angle);
	*z = -(*x) * sin(angle) + *z * cos(angle);
}

void	draw_line(float x, float y, float x1, float y1, t_data *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;
	int color;

	z = data->map->depth_arr[(int)y][(int)x];
	z1 = data->map->depth_arr[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	color = (z || z1) ? 0xff0000 : 0xffffff;

	// isometric(&x, &y, z);
	// isometric(&x1, &y1, z1);

	rot_x(&x, &y, &z, data);
	rot_x(&x1, &y1, &z1, data);

	rot_y(&x, &y, &z, data);
	rot_y(&x1, &y1, &z1, data);

	x += data->x_shift;
	y += data->y_shift;
	x1 += data->x_shift;
	y1 += data->y_shift;
// https://habr.com/ru/post/185086/
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(abs(x_step), abs(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		if (x > WIDTH || y > HEIGHT || y < 0 || x < 0)
			break ;
		plot(x, y, data, color, 0.1);
		x += x_step;
		y += y_step;
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