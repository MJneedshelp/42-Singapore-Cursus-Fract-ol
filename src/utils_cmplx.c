/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmplx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:30:00 by mintan            #+#    #+#             */
/*   Updated: 2024/08/31 20:19:04 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include <math.h>
// #include "../include/fractol.h"

typedef struct s_cmplx_number
{
	double	re;
	double	img;
}	t_cmplx;


/* Description: calculates the square of a complex number. Returns a complex
   number in the form of a structure that contains the real and imaginary
   parts of the complex number.
*/

t_cmplx	sqr_cmplx(t_cmplx input)
{
	t_cmplx	res;

	printf("Input - re: %f | img: %f\n", input.re, input.img);
	res.re = (input.re * input.re) - (input.img * input.img);
	res.img = 2 * input.re * input.img;
	return (res);
}

/* Description: calculates the sum of 2 complex numbers. Sums the real and
   imaginary parts of the number individually. Returns a complex number in
   the form of a structure that contains the real and imaginary parts of
   the complex number.
*/

t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2)
{
	t_cmplx	res;

	res.re = input1.re + input2.re;
	res.img = input1.img + input2.img;
	return (res);
}


/* Description: calculates the magnitude of a complex number.
   - Complex number input: a + bi
   - Magnitude = sqrt(a^2 + b^2)
   Return: magnitude of the complex number as a double
*/

double	magnitude_cmplx(t_cmplx input)
{
	double	ret;

	ret = sqrt((input.re * input.re) + (input.img * input.img));
	return (ret);
}




/* Description: calculates the results of the mandelbrot equation given the
   the complex number and the number of iterations.
   - Mandelbrot equation: Z_n+1 = (Z_n)^2 + C
   Returns a complex number in the form of a structure that contains the
   real and imaginary parts of the complex number.
*/

t_cmplx	calc_mandelbrot(t_cmplx input, int no_iter)
{
	t_cmplx res;
	int		i;

	res.re = 0;
	res.img = 0;
	i = 0;
	while (i < no_iter)
	{
		res = sum_cmplx(sqr_cmplx(res), input);
		i++;
	}
	return (res);
}




int	main(void)
{
	t_cmplx	input1;
	t_cmplx	input2;
	t_cmplx	output1;
	t_cmplx output2;
	t_cmplx output3;
	int		no_iter;

	no_iter = 3;
	input1.re = 0.5;
	input1.img = 0.5;
	input2.re = 15;
	input2.img = -1.7;
	output1 = sqr_cmplx(input1);
	output2 = sum_cmplx(input1, input2);
	output3 = calc_mandelbrot(input1, no_iter);
	printf("Square of %f + (%f)i. Output - re: %f | img: %f\n", input1.re, input1.img, output1.re, output1.img);
	printf("Sum of %f + (%f)i. Output - re: %f | img: %f\n", input1.re, input1.img, output2.re, output2.img);
	printf("Mandelbrot. C = %f + (%f)i | Iterations: %d | Output - re: %f | img: %f\n", input1.re, input1.img, no_iter, output3.re, output3.img);
	printf("Mangnitude of madelbrot: %f\n", magnitude_cmplx(output3));


	return (0);
}









// /* Description: calculates the results of the mandelbrot equation given the
//    the complex number and the no. of iterations.
// */

// t_cmplx	mandelbrot(t_cmplx cmplx, int no_iter)
// {
// 	double	z_0;

// 	z_0 = 0;


// }



// /* Description: checks if a complex number is bounded XXXX
// 	- x: real
// 	- y: imaginary


// */

// int	calc_zn(double x, double y, int no_iter)
// {
// 	double	z_0;
// 	double	z_n,
// 	double
// 	z_0 = 0;

// 	//for no_iter = 1
// 	z_1 = (z_0 * z_0) +


// }
