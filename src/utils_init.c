/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:09:25 by mintan            #+#    #+#             */
/*   Updated: 2024/08/29 16:48:41 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>

/* Description: Initialises the fract structure.
   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/

t_fract	*init_fract(void)
{
	t_fract	*fract;

	fract = (t_fract *)malloc(sizeof(t_fract));
	if (fract == NULL)
		exit (EXIT_FAILURE);
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
	{
		free (fract);					//Probably write a clean up function here
		exit (EXIT_FAILURE);
	}
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
	if (fract->win_ptr == NULL)
	{
		free (fract->mlx_ptr);
		free (fract);					//Probably write a clean up function here
		exit (EXIT_FAILURE);
	}
	fract->img.mlx_img = mlx_new_image(fract->mlx_ptr, WIN_LEN, WIN_HT);
	fract->img.addr = mlx_get_data_addr(fract->img.mlx_img, &(fract->img.bpp), &(fract->img.line_len), &(fract->img.endian));
	printf("Bits per pixel: %d | line size: %d | endian: %d\n", fract->img.bpp, fract->img.line_len, fract->img.endian);


	// mlx_get_data_addr(fract->img->mlx_img, fract->img->bpp, fract->img->line_len, fract->img->endian);
	// printf("img bpp value: %d\n", fract->img->bpp);
	return (fract);
}


void	end_prog(t_fract *fract)
{
	mlx_destroy_display(fract->mlx_ptr);
	mlx_destroy_image(fract->mlx_ptr, &fract->img);
	free (fract->mlx_ptr);
	free (fract->img.addr);
	free (&fract->img);
	free (fract);
	//Probably need to clear up the img pointer as well
	exit (EXIT_SUCCESS);
}
