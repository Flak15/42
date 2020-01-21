
#include "fdf.h"

void	redraw_window(t_data *data)
{
	ft_bzero(data->data_addr, WIDTH * HEIGHT * data->bpp / 8);
	draw_map(data);
}

int key(int key, void *p)
{
	t_data *data;

	data = (t_data *)p;
	printf("%d\n", key);
	if (key == MINUS)
	{
		data->flattening = data->flattening == 1 ? 1 : data->flattening - 1;
		redraw_window(data);
	}
	if (key == PLUS)
	{
		data->flattening += 1;
		redraw_window(data);
	}
	if (key == ARROW_UP)
	{
		data->y_shift -= 30;
		redraw_window(data);
	}
	if (key == ARROW_DOWN)
	{
		data->y_shift += 30;
		redraw_window(data);
	}
	if (key == ARROW_LEFT)
	{
		data->x_shift -= 30;
		redraw_window(data);
	}
	if (key == ARROW_RIGHT)
	{
		data->x_shift += 30;
		redraw_window(data);
	}
	if (key == ESCAPE)
	{
		// free all
		exit(0);
	}
	return (0);
}

int mouse_move(int x,int y, void *p)
{
	t_data *data;
	data = (t_data *)p;
	if (data->mb1_pressed)
	{
		data->r_end->x = x;
		data->r_end->y = y;

		data->rotate_y -= (data->r_start->x - data->r_end->x) * 0.002;
		data->rotate_x -= (data->r_start->y - data->r_end->y) * 0.002;

		redraw_window(data);
		data->r_start->x = x;
		data->r_start->y = y;
	}
	if (data->mb2_pressed)
	{
		data->r_end->x = x;
		data->rotate_z += (data->r_start->x - data->r_end->x) * 0.002;
		redraw_window(data);
		data->r_start->x = x;
	}
	return (0);
}
int	mouse_press(int button, int x,int y, void *p)
{
	t_data *data;

	data = (t_data *)p;
	if (button == WHL_UP)
	{
		data->zoom +=1;
		redraw_window(data);
	}
	if (button == WHL_DN)
	{
		data->zoom -=1;
		redraw_window(data);
	}
	if (button == LMB)
	{
		data->mb1_pressed = 1;
		data->r_start->x = x;
		data->r_start->y = y;
	}
	if (button == RMB)
	{
		data->mb2_pressed = 1;
		data->r_start->x = x;
		data->r_start->y = y;
	}
	return (0);
}

int	mouse_release(int button, int x,int y, void *p)
{
	t_data *data;

	(void)x;
	(void)y;
	data = (t_data *)p;
	if (button == LMB)
	{
		data->mb1_pressed = 0;
	}
	if (button == RMB)
	{
		data->mb2_pressed = 0;
	}
	return (0);
}


t_data	*init(void)
{
	t_data	*data;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	data->img_ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img_ptr, &(data->bpp),
		&(data->size_line), &(data->endian));
	data->map = (t_map *)ft_memalloc(sizeof(t_map));
	data->r_start = (t_point *)ft_memalloc(sizeof(t_point));
	data->r_end = (t_point *)ft_memalloc(sizeof(t_point));
	data->zoom = DEF_ZOOM;
	data->flattening = 1;
	data->proj = DEF_PROJ;
	data->x_shift = 400;
	data->y_shift = 200;
	data->rotate_x = 0;
	data->rotate_y = 0;
	data->rotate_z = 0;
	data->map->max_depth = 0;
	data->map->min_depth = 0;
	data->mb1_pressed = 0;
	data->mb2_pressed = 0;
	data->r_start->x = 0;
	data->r_start->y = 0;
	data->r_end->x = 0;
	data->r_end->y = 0;
	return (data);
}

int main(int argc, char **argv)
{

	t_data *data;

	if (argc != 2)
		return (1);
	data = init();

	read_file(argv[1], data);


	draw_map(data);

	mlx_key_hook(data->win, key, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask, mouse_release, data);
	mlx_loop(data->mlx);
	return (0);
}
