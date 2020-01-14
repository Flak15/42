#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(DEF_PROJ);
	*y = (*x + *y) * sin(DEF_PROJ) - z;
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

    x += DEF_SHIFT;
    y += DEF_SHIFT;
    x1 += DEF_SHIFT;
    y1 += DEF_SHIFT;

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
	
}