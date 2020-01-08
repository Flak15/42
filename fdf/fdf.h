#include "minilibx/mlx.h"
#include <stdio.h>
#include "libft.h"

#define PointerMotionMask		(1L<<6)
#define MotionNotify		6
#define WIDTH		700
#define HEIGHT		700
typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;