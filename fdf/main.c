
#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <math.h>

void plot(int x, int y, t_data *data)
{
	int i;
	
	i = (x * 4) + (y * data->size_line);
	data->data_addr[i] = (char)255;
	data->data_addr[i + 1] = (char)255;
	data->data_addr[i + 2] = (char)255;
}

void print_line(t_point st, t_point end, t_data *data)
{
	int deltax = abs(end.x - st.x);
	int deltay = abs(end.y - st.y);
	int error = 0;
	int deltaerr = (deltay + 1);
	int y = st.y;
	int x = st.x;
	//int diry = end.y - st.y > 0 ? 1 : -1;
	if (deltax > deltay)
		while (x <= end.x)
		{
			plot(x, y, data);
			error = error + deltaerr;
			if (error >= (deltax + 1))
			{
				y = y + (end.y - st.y > 0 ? 1 : -1);
				error = error - (deltax + 1);
			}
			x++;
		}
	else
	{
		deltaerr = deltax + 1;
		while (y <= end.y)
		{
			plot(x, y, data);
			error = error + deltaerr;
			if (error >= (deltay + 1))
			{
				x = x + (end.x - st.x > 0 ? 1 : -1);
				error = error - (deltay + 1);
			}
			y++;
		}
	}
}



void draw_image(t_data *data)
{


	t_point one;
	t_point two;

	one.x = 10;
	one.y = 100;

	two.x = 100;
	two.y = 100;

	print_line(one, two, data);
}

int	mouse_win1(int button,int x,int y, void *p)
{
	t_data *data;
	

	data = (t_data *)p;
	
	draw_image(data);
	if (button == 1)
	{
		
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


	printf("bpp: %d, size_line: %d, endian: %d\n", data->bpp, data->size_line, data->endian);
	mlx_pixel_put(data->mlx, data->win, 100, i, 0xFFFFFF);
	mlx_mouse_hook(data->win, mouse_win1, data);
	//mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_win3, data);
	mlx_loop(data->mlx);
	return (0);
}
