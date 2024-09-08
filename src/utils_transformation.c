/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:36:55 by mintan            #+#    #+#             */
/*   Updated: 2024/09/08 14:47:44 by mintan           ###   ########.fr       */
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



// int	main(void)
// {
// 	t_cmplx		output1;
// 	t_cmplx		output2;
// 	t_cmplx		output3;
// 	t_cmplx		output4;
// 	t_cmplx		output5;
// 	t_cmplx 	output6;
// 	t_cmplx 	output7;
// 	t_cmplx		output8;
// 	t_tf_fact	fact;

// 	fact.mag = 0.5;
// 	fact.or_a = 0.0;
// 	fact.or_b = 0.0;

// 	output1= tf_pixel_to_cmplx(0, 0, fact);
// 	printf("Pixel: (0, 0) | Complex: (Re: %f, Img: %f)\n", output1.re, output1.img);
// 	output2= tf_pixel_to_cmplx(400, 400, fact);
// 	printf("Pixel: (400, 400) | Complex: (Re: %f, Img: %f)\n", output2.re, output2.img);
// 	output3= tf_pixel_to_cmplx(800, 0, fact);
// 	printf("Pixel: (800, 0) | Complex: (Re: %f, Img: %f)\n", output3.re, output3.img);
// 	output4= tf_pixel_to_cmplx(800, 800, fact);
// 	printf("Pixel: (800, 800) | Complex: (Re: %f, Img: %f)\n", output4.re, output4.img);
// 	output5= tf_pixel_to_cmplx(0, 800, fact);
// 	printf("Pixel: (0, 800) | Complex: (Re: %f, Img: %f)\n", output5.re, output5.img);
// 	output6= tf_pixel_to_cmplx(600, 200, fact);
// 	printf("Pixel: (600, 200) | Complex: (Re: %f, Img: %f)\n", output6.re, output6.img);
// 	output7= tf_pixel_to_cmplx(100, 700, fact);
// 	printf("Pixel: (100, 700) | Complex: (Re: %f, Img: %f)\n", output7.re, output7.img);
// 	output8= tf_pixel_to_cmplx(456, 133, fact);
// 	printf("Pixel: (456, 133) | Complex: (Re: %f, Img: %f)\n", output8.re, output8.img);
// }

