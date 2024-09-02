/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:10:59 by mintan            #+#    #+#             */
/*   Updated: 2024/09/01 18:38:18 by mintan           ###   ########.fr       */
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
		printf("magnitude: %f\n", magnitude_cmplx(term));
		i++;
		if (magnitude_cmplx(term) > 2)
			return (i);
	}
	return (0);
}

int	main(void)
{
	t_cmplx	input1;
	t_cmplx	input2;
	int		no_iter;

	no_iter = 20;
	input1.re = 0.3;
	input1.img = 0.5;
	input2.re = -0.123;
	input2.img = 0.745;
	printf("Input 1: %f + (%f)i | Part of Mandelbrot set: %d\n", input1.re, input1.img, check_mandelbrot(input1, no_iter));
	printf("Input 2: %f + (%f)i | Part of Mandelbrot set: %d\n", input2.re, input2.img, check_mandelbrot(input2, no_iter));
	return (0);
}
