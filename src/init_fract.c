/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:09:25 by mintan            #+#    #+#             */
/*   Updated: 2024/09/12 09:48:53 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Desciption: Sets the initial parameters for rendering:
	- or_a: origin of a - real on the complex plane
	- or_b: origina of b - imaginary on the complex plane
	- mag: magnification. A lower number corresponds to higher zoom
	- iter: number of iterations
*/
void	init_parameters(t_fract *fract)
{
	if (fract->set == 1)
	{
		fract->or_a = -0.5;
		fract->or_b = 0.0;
	}
	else
	{
		fract->or_a = 0.0;
		fract->or_b = 0.0;
	}

	fract->mag = 1.0;
	fract->iter = DEF_ITER;
}


/* Description: Initialises the fractal set information"
	- set: 1 for mandelbrot, 0 for julia
	- j_term: complex term for julia set. Use ft_atod to convert
		- re: argv[2] corresponds to the real term for the julia set
		- img: argv[3] corresponds to the imaginary term for the julia set
*/
void	init_set(t_fract *fract, char *argv[])
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fract->set = 1;
	else
	{
		fract->set = 0;
		fract->j_term.re = ft_atod(argv[2]);
		fract->j_term.img = ft_atod(argv[3]);
	}
}




/* Description: Initialises the fract structure.
   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/

t_fract	init_fract(char *argv[])
{
	t_fract	fract;

	fract.mlx_ptr = mlx_init();
	if (fract.mlx_ptr == NULL)
		exit (EXIT_FAILURE);//Probably write a clean up function here
	fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
	if (fract.win_ptr == NULL)
	{
		free (fract.mlx_ptr);//Probably write a clean up function here
		exit (EXIT_FAILURE);
	}
	fract.img.mlx_img = mlx_new_image(fract.mlx_ptr, WIN_LEN, WIN_HT);
	fract.img.addr = mlx_get_data_addr(fract.img.mlx_img, &(fract.img.bpp),\
	&(fract.img.line_len), &(fract.img.endian));

	init_set(&fract, argv);


	init_parameters(&fract);
	fract.event = 1;
	return (fract);
}


void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}























// /* Description: Initialises the fract structure.
//    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// */

// t_fract	*init_fract(void)
// {
// 	t_fract	*fract;

// 	fract = (t_fract *)malloc(sizeof(t_fract));
// 	if (fract == NULL)
// 		exit (EXIT_FAILURE);
// 	fract->mlx_ptr = mlx_init();
// 	if (fract->mlx_ptr == NULL)
// 	{
// 		free (fract);					//Probably write a clean up function here
// 		exit (EXIT_FAILURE);
// 	}
// 	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
// 	if (fract->win_ptr == NULL)
// 	{
// 		free (fract->mlx_ptr);
// 		free (fract);					//Probably write a clean up function here
// 		exit (EXIT_FAILURE);
// 	}
// 	fract->img.mlx_img = mlx_new_image(fract->mlx_ptr, WIN_LEN, WIN_HT);
// 	fract->img.addr = mlx_get_data_addr(fract->img.mlx_img, &(fract->img.bpp), &(fract->img.line_len), &(fract->img.endian));
// 	fract->or_a = -0.5;
// 	fract->or_b = 0.0;
// 	fract->mag = 1.0;
// 	fract->iter = DEF_ITER;
// 	fract->event = 1;
// 	printf("Bits per pixel: %d | line size: %d | endian: %d\n", fract->img.bpp, fract->img.line_len, fract->img.endian);


// 	// mlx_get_data_addr(fract->img->mlx_img, fract->img->bpp, fract->img->line_len, fract->img->endian);
// 	// printf("img bpp value: %d\n", fract->img->bpp);
// 	return (fract);
// }
