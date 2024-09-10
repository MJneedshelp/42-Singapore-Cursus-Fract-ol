/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:10:59 by mintan            #+#    #+#             */
/*   Updated: 2024/09/10 15:46:46 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: translates and scale pixel coordinates based on the defined
   XXXXXXX WRITE THIS LATER WHEN YOU GET ALL YOUR TERMS DOWN

*/

t_cmplx	tf_pixel_to_cmplx(int p_x, int p_y, t_fract *fract)
{
	t_cmplx	res;

	res.re = fract->mag * ((double)p_x / WIN_LEN * U_A - (U_A / 2)) + \
	fract->or_a;
	res.img = fract->mag * ((double)-p_y / WIN_HT * U_B + (U_B / 2)) + \
	fract->or_b;
	return (res);
}

/* Description: checks if a given complex number is part of the mandelbrot set
   given the number of iterations n.
   Actions:
	- Calculate the ith term of the mandelbrot equation for each iteration
	  until the nth term term
	  	- Mandelbrot equation: Z_n+1 = (Z_n)^2 + C
	- Check the magnitude of the ith term
		- If the magnitude |z_i| =< 2: part of the mandelbrot set
		- If the magnitude |z_i| > 2: not part of the mandelbrot set. Break and
		return the number of iterations when the it diverges
	- Return 0 if |z_n| =< 2
*/

int	check_mandelbrot(t_cmplx input, int no_iter)
{
	t_cmplx	term;
	int		i;

	term.re = 0.0;
	term.img = 0.0;
	i = 0;
	while (i < no_iter)
	{
		term = sum_cmplx(sqr_cmplx(term), input);
		i++;
		if (magnitude_cmplx(term) > 2)
			return (i);
	}
	return (0);
}


/* Description: checks if a given complex number is part of the julia set
   given the number of iterations n as well as the real and imaginary terms of
   the complex number in the julia set.
   Actions:
	- Calculate the ith term of the julia equation for each iteration
	  until the nth term term
	  	- Julia equation: Z_n+1 = (Z_n)^2 + C
		- Z_0: current position on the complex plan
		- C: given complex term
	- Check the magnitude of the ith term
		- If the magnitude |z_i| =< 2: part of the julia set
		- If the magnitude |z_i| > 2: not part of the julia set. Break and
		return the number of iterations when the it diverges
	- Return 0 if |z_n| =< 2
*/

int	check_julia(t_cmplx input, t_cmplx c_term, int no_iter)
{
	t_cmplx	term;
	int		i;

	term.re = input.re;
	term.img = input.img;
	i = 0;
	while (i < no_iter)
	{
		term = sum_cmplx(sqr_cmplx(term), c_term);
		i++;
		if (magnitude_cmplx(term) > 2)
			return (i);
	}
	return (0);
}




/* Description: Draw the mandelbrot fractal into an image.
   Actions:
	1. For each pixel in the window, convert the pixel coordinates into the
	   the complex coordinates
	2. Check if the the complex coordinates lies within the mandelbrot set
		- In set: colour black
		- Not in set: colour white
*/

int	draw_mandelbrot(t_img *img, t_fract *fract)
{
	int		x;
	int		y;
	t_cmplx	pix;

	t_cmplx	c_term;

	c_term.re = 0.285;
	c_term.img = 0.01;

	x = 0;
	while (x < WIN_LEN)
	{
		y = 0;
		while (y < WIN_HT)
		{
			// pix = tf_pixel_to_cmplx(x, y, fract);
			// if (check_mandelbrot(pix, fract->iter) == 0)
			// 	img_pixel_put(img, x, y, COLOR_BLACK);
			// else
			// 	img_pixel_put(img, x, y, COLOR_WHITE);
			// y++;

			// if (check_julia(pix, c_term, fract->iter) == 0)
			// 	img_pixel_put(img, x, y, COLOR_BLACK);
			// else
			// 	img_pixel_put(img, x, y, COLOR_WHITE);
			// y++;
			pix = tf_pixel_to_cmplx(x, y, fract);
			if (fract->set == 1)
			{
				if (check_mandelbrot(pix, fract->iter) == 0)
					img_pixel_put(img, x, y, COLOR_BLACK);
				else
					img_pixel_put(img, x, y, COLOR_WHITE);
			}
			else
			{
				if (check_julia(pix, c_term, fract->iter) == 0)
					img_pixel_put(img, x, y, COLOR_BLACK);
				else
					img_pixel_put(img, x, y, COLOR_WHITE);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.mlx_img, 0, 0);
	return (0);
}








// int	main(void)
// {
// 	t_cmplx	input1;
// 	t_cmplx	input2;
// 	int		no_iter;

// 	no_iter = 20;
// 	input1.re = 0.3;
// 	input1.img = 0.5;
// 	input2.re = -0.123;
// 	input2.img = 0.745;
// 	printf("Input 1: %f + (%f)i | Part of Mandelbrot set: %d\n", input1.re, input1.img, check_mandelbrot(input1, no_iter));
// 	printf("Input 2: %f + (%f)i | Part of Mandelbrot set: %d\n", input2.re, input2.img, check_mandelbrot(input2, no_iter));
// 	return (0);
// }
