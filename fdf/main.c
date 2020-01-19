
#include "fdf.h"

void	redraw_window(t_data *data)
{
	ft_bzero(data->data_addr, WIDTH * HEIGHT * data->bpp / 8);
	draw_map(data);
}

int	mouse_win1(int button, int x,int y, void *p)
{
	t_data *data;
	

	data = (t_data *)p;
	
	if (button == 1)
	{
		data->rotate_x += 0.1;
		redraw_window(data);
	}
	if (button == 3)
	{
		data->rotate_y += 0.1;
		redraw_window(data);
	}

	printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
	return (0);
}

int key(int key, void *p)
{
	t_data *data;
	
	data = (t_data *)p;
	//printf("%d\n", key);
	if (key == 65362)
	{
		data->y_shift -= 30;
		redraw_window(data);
	}
	if (key == 65364)
	{
		data->y_shift += 30;
		redraw_window(data);
	}
	if (key == 65361)
	{
		data->x_shift -= 30;
		redraw_window(data);
	}
	if (key == 65363)
	{
		data->x_shift += 30;
		redraw_window(data);
	}
	if (key == 65307)
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
	if (data->mouse_pressed)
	{
		data->r_end->x = x;
		data->r_end->y = y;
		
		data->rotate_x -= (data->r_start->x - data->r_end->x) * 0.002;
		data->rotate_y -= (data->r_start->y - data->r_end->y) * 0.002;
		
		redraw_window(data);
		data->r_start->x = x;
		data->r_start->y = y;
	}
	return (0);
}
int	mouse_press(int button, int x,int y, void *p)
{
	t_data *data;
	// (void)p;

	data = (t_data *)p;
	if (button == 4)
	{
		data->zoom +=2;
		redraw_window(data);
	}
	if (button == 5)
	{
		data->zoom -=2;
		redraw_window(data);
	}
	if (button == 1)
	{
		data->mouse_pressed = 1;
		data->r_start->x = x;
		data->r_start->y = y;
	}
	return (0);
}

int	mouse_release(int button, int x,int y, void *p)
{
	t_data *data;
	// (void)p;

	data = (t_data *)p;
	if (button == 1 )
	{
		
		// mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
		printf("Release, at %dx%d.\n",x,y);
		data->mouse_pressed = 0;
		// data->r_end->x = x;
		// data->r_end->y = y;
		printf("Rotate from %dx%d to %dx%d.\n", data->r_start->x ,data->r_start->y, data->r_end->x, data->r_end->y);
		
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
	data->proj = DEF_PROJ;
	data->x_shift = 400;
	data->y_shift = 200;
	data->rotate_x = 0;
	data->rotate_y = 0;

	data->mouse_pressed = 0;
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

	read_file(argv[1], data->map);
	

	draw_map(data);
	
	// mlx_mouse_hook(data->win, mouse_win1, data);
    
	mlx_key_hook(data->win, key, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
    mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
    mlx_hook(data->win, ButtonRelease, ButtonReleaseMask, mouse_release, data);
	mlx_loop(data->mlx);
	return (0);
}
