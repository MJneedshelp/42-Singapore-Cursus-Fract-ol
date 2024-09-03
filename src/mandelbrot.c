/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:10:59 by mintan            #+#    #+#             */
/*   Updated: 2024/09/03 09:00:13 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

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

	term.re = 0;
	term.img = 0;
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


/* Description: Draw the mandelbrot fractal into an image.
   Actions:
	1. For each pixel in the window, convert the pixel coordinates into the
	   the complex coordinates
	2. Check if the the complex coordinates lies within the mandelbrot set
		- In set: colour black
		- Not in set: colour white
*/

int	draw_mandelbrot(t_img *img)
{
	int		x;
	int		y;
	t_cmplx	pix;

	x = 0;
	while (x < WIN_LEN)
	{
		y = 0;
		while (y < WIN_HT)
		{
			pix = tf_pixel_to_cmplx(x, y);
			if (check_mandelbrot(pix, DEF_ITER) == 0)
				img_pixel_put(img, x, y, COLOR_BLACK);
			else
				img_pixel_put(img, x, y, COLOR_WHITE);
			y++;
		}
		x++;
	}
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
