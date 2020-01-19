#include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(DEF_PROJ);
	*y = (*x + *y) * sin(DEF_PROJ) - z;
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

void	rot_x(int *x, int *z, t_data *data)
{
	double angle = data->rotate_x;
	*x = (*x - (data->map->width - 1) * data->zoom / 2) * cos(angle) + *z * sin(angle);
	*z = -(*x) * sin(angle) + *z * cos(angle);
}

void	rot_y(int *y, int *z, t_data *data)
{
	double angle = data->rotate_y;
	*y = (*y - (data->map->height - 1) * data->zoom / 2) * cos(angle) + *z * sin(angle);
	*z = -(*y) * sin(angle) + *z * cos(angle);
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
	MAX(z, z1);
	if (z1 - z)
}

void	draw_line(int x, int y, int x1, int y1, t_data *data)
{
	// float x_step;
	// float y_step;
	// int max;
	int z;
	int z1;
	int color;

	z = data->map->depth_arr[(int)y][(int)x];
	z1 = data->map->depth_arr[(int)y1][(int)x1];
	color =  get_color(z, z1, data); //(z || z1) ? : 0xffffff;
	
	zoom(&x, &x1, &y, &y1, data);

	// z *= data->zoom / 10;
	// z1 *= data->zoom / 2;
	
	rot_x(&x, &z, data);
	rot_x(&x1, &z1, data);
	rot_y(&y, &z, data);
	rot_y(&y1, &z1, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	shift(&x, &x1, &y, &y1, data);
	
	BresenhamLine(x, y, x1, y1, data, color);
// https://habr.com/ru/post/185086/


	// x_step = x1 - x;
	// y_step = y1 - y;
	// max = MAX(abs(x_step), abs(y_step));
	// x_step /= max;
	// y_step /= max;
	// while((int)(x - x1) || (int)(y - y1))
	// {
	// 	if (x > WIDTH || y > HEIGHT || y < 0 || x < 0)
	// 		break ;
	// 	plot(x, y, data, color, 0.5);
	// 	x += x_step;
	// 	y += y_step;
	// }
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
	int error = dx / 2; // Здесь используется оптимизация с умножением на dx, чтобы избавиться от лишних дробей
	int ystep = (y0 < y1) ? 1 : -1; // Выбираем направление роста координаты y
	int y = y0;
	int x = x0;
	while ((x - x1) || (y - y1))
	{
		plot(steep ? y : x, steep ? x : y, data, color);
		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
		x++;
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