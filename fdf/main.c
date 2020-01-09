
#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int	mouse_win1(int button,int x,int y, void *p)
{
	t_data *data;
	int i;
	
	data = (t_data *)p;
	i = (x * 4) + (y * data->size_line * 4);
	
	if (button == 1)
	{
		data->data_addr[i] = 'f';
		data->data_addr[i + 1] = 'f';
		data->data_addr[i + 2] = 'f';
		// mlx_destroy_image(data->mlx, data->img_ptr);
		mlx_put_image_to_window(data->mlx, data->win, data->img_ptr, 0, 0);
	}
	

	printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
	return (0);
}

int	mouse_win3(int x,int y, void *p)
{
	t_data *data;

	data = (t_data *)p;
	mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
	// printf("Mouse moving in Win3, at %dx%d.\n",x,y);
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
	return (data);
}

int main(void)
{

	int i = 100;

	t_data *data;

	data = init();	


	while (i++ < 200)
	mlx_pixel_put(data->mlx, data->win, 100, i, 0xFFFFFF);
	mlx_mouse_hook(data->win, mouse_win1, data);
	//mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_win3, data);
	mlx_loop(data->mlx);
	return (0);
}