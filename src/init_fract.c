/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:09:25 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:49:33 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Desciption: Sets the initial parameters for rendering. Different starting
   parameters for the different fractal sets:
	- or_a: origin of a - real on the complex plane
	- or_b: origin of b - imaginary on the complex plane
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

/* Description: Initialises the fractal set information
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

/* Description: Initialises the fract structure, which holds all the
   information required for the programme. Used to pass information across
   the different functions in the programme:
	- mlx_ptr: pointer to a big structure storing a lot of minilibx info
	- win_ptr: pointer to the created window
	- t_img: struct to hold all the information required for the image
	- init_set: takes in information for the julia set from the input arguments
	- init_parameters: sets up the origin of the complex plane based on the
	  fractal set
	- rng: a number that is fed into a formula to generate a random number
	- event: identifier to use to draw a new image when a mouse or key event
	  takes place
*/

t_fract	init_fract(char *argv[])
{
	t_fract	fract;

	fract.mlx_ptr = mlx_init();
	if (fract.mlx_ptr == NULL)
		exit (EXIT_FAILURE);
	fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
	if (fract.win_ptr == NULL)
	{
		free (fract.mlx_ptr);
		exit (EXIT_FAILURE);
	}
	fract.img.mlx_img = mlx_new_image(fract.mlx_ptr, WIN_LEN, WIN_HT);
	fract.img.addr = mlx_get_data_addr(fract.img.mlx_img, &(fract.img.bpp), \
	&(fract.img.line_len), &(fract.img.endian));
	fract.rng = DEF_ITER;
	init_set(&fract, argv);
	init_parameters(&fract);
	fract.event = 1;
	return (fract);
}

/* Description: function to put pixels on to an image. This is used instead of
	mlx_pixel_put. Maps the x and y coordinates of the pixel to a memory
	address of an image.
*/

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
