#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	dx = (x - y) * cos(angle);
	dy = (x + y) * sin(angle) - z;
}

void	draw_line(float x, float y, float x1, float y1, t_data *data, int color)
{
	float x_step;
	float y_step;
	int max;

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;


	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX(abs(x_step), abs(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
		
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;
	int color;

	y = 0;
	
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			color =  data->map->depth_arr[y][x] ? 
				0xff0000 : 0xffffff;
			if (x < data->map->width - 1)
				draw_line(x, y, x + 1, y, data, color);
			if (y < data->map->height - 1)
				draw_line(x, y, x, y + 1, data, color);
			x++;
		}
		y++;
	}
	
}