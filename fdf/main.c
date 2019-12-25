#include <mlx.h>

int main(void)
{
  void *mlx;
  void *window;
  int i = 100;
  

  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 1000, "Title");
  while (i++ < 200)
    mlx_pixel_put ( mlx, window, 100, i, 0xFFFFFF);
  mlx_loop(mlx);
  return (0);
}