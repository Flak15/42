#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(DEF_PROJ);
	*y = (*x + *y) * sin(DEF_PROJ) - z;
}

void plot(int x, int y, t_data *data, int color)
{
	int i;
	
	i = (x * 4) + (y * data->size_line);
	data->data_addr[i] = color;
	data->data_addr[i + 1] = color >> 8;
	data->data_addr[i + 2] = color >> 16;
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

	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	x += data->x_shift;
	y += data->y_shift;
	x1 += data->x_shift;
	y1 += data->y_shift;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(abs(x_step), abs(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		plot(x, y, data, color);
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