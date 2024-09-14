/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:45 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:20:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>
// #include </X11/keysymdef.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	mj_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int	deal_key(int keycode, void *param)
{
	ft_printf("Keycode: %d\n", keycode);
	// mlx_pixel_put();
	if (param == NULL)
		return (0);
	return (0);
}


int	draw_line(void *mlx_ptr, void *mlx_win, int xstart, int xend, int ystart, int yend, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixelx;
	double	pixely;

	delta_x = xend - xstart;
	delta_y = yend - ystart;
	pixels = sqrt(pow(delta_x, 2) + pow(delta_y, 2));

	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;

	pixelx = xstart;
	pixely = ystart;
	while (pixels)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, pixelx, pixely, color);
		pixelx = pixelx + delta_x;
		pixely = pixely + delta_y;
		pixels--;
	}
	return (0);

}


int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	// t_data	*img;

	mlx_ptr = mlx_init();

	mlx_win = mlx_new_window(mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);

	// mlx_pixel_put(mlx_ptr, mlx_win, 250, 250, 0xCB329F);

	draw_line(mlx_ptr, mlx_win, 0, WIN_LEN, 0, WIN_HT, 0xFFFFFF);

	mlx_key_hook(mlx_win, deal_key, (void *)0);




	// img->img = mlx_new_image(mlx_ptr, 1920, 1080);

	// img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	// mj_mlx_pixel_put(img, 810, 540, 0x11FFFFFF);

	// mlx_put_image_to_window(mlx_ptr, mlx_win, img->img, 0, 0);

	mlx_loop(mlx_ptr);

}
