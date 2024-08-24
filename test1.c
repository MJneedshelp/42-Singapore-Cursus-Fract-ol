/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:26:45 by mintan            #+#    #+#             */
/*   Updated: 2024/08/24 17:03:09 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minilibx-linux/mlx.h"
#include <mlx.h>


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





int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	*img;

	mlx_ptr = mlx_init();

	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Minjow");


	img->img = mlx_new_image(mlx_ptr, 1920, 1080);

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	mj_mlx_pixel_put(img, 810, 540, 0x11FFFFFF);

	mlx_put_image_to_window(mlx_ptr, mlx_win, img->img, 0, 0);

	mlx_loop(mlx_ptr);

}
