/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:36:55 by mintan            #+#    #+#             */
/*   Updated: 2024/09/03 08:28:07 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: translates and scale pixel coordinates based on the defined
   XXXXXXX WRITE THIS LATER WHEN YOU GET ALL YOUR TERMS DOWN

*/

t_cmplx	tf_pixel_to_cmplx(int x, int y)
{
	t_cmplx	res;

	res.re = (double)x * ((2 * COMPLEX_MAX_A) / WIN_LEN) - COMPLEX_MAX_A;
	res.img = (double)y * ((-2 * COMPLEX_MAX_B) / WIN_HT) + COMPLEX_MAX_B;
	return (res);
}



// int	main(void)
// {
// 	t_cmplx	output1;
// 	t_cmplx	output2;
// 	t_cmplx	output3;
// 	t_cmplx	output4;
// 	t_cmplx	output5;
// 	t_cmplx output6;
// 	t_cmplx output7;
// 	t_cmplx	output8;

// 	output1= tf_pixel_to_cmplx(0, 0);
// 	printf("Pixel: (0, 0) | Complex: (Re: %f, Img: %f)\n", output1.re, output1.img);
// 	output2= tf_pixel_to_cmplx(500, 0);
// 	printf("Pixel: (500, 0) | Complex: (Re: %f, Img: %f)\n", output2.re, output2.img);
// 	output3= tf_pixel_to_cmplx(500, 400);
// 	printf("Pixel: (500, 400) | Complex: (Re: %f, Img: %f)\n", output3.re, output3.img);
// 	output4= tf_pixel_to_cmplx(0, 400);
// 	printf("Pixel: (0, 400) | Complex: (Re: %f, Img: %f)\n", output4.re, output4.img);
// 	output5= tf_pixel_to_cmplx(250, 200);
// 	printf("Pixel: (250, 200) | Complex: (Re: %f, Img: %f)\n", output5.re, output5.img);
// 	output6= tf_pixel_to_cmplx(375, 300);
// 	printf("Pixel: (375, 300) | Complex: (Re: %f, Img: %f)\n", output6.re, output6.img);
// 	output7= tf_pixel_to_cmplx(122, 400);
// 	printf("Pixel: (122, 400) | Complex: (Re: %f, Img: %f)\n", output7.re, output7.img);
// 	output8= tf_pixel_to_cmplx(425, 100);
// 	printf("Pixel: (425, 100) | Complex: (Re: %f, Img: %f)\n", output8.re, output8.img);
// }

