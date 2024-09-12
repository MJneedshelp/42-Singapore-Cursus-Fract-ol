/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/09/12 09:44:48 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"


int	main(int argc, char *argv[])
{
	t_fract	fract;

	//logic:
	//1. Check argc argv
	//	- mandelbrot: 2 argc
	//	- julia: 4 argc
	check_inputs(argc, argv);
	fract = init_fract(argv);

	printf("Check set: %d | j_re: %f | j_img: %f\n", fract.set, fract.j_term.re, fract.j_term.img);



	printf("mlx_ptr: %p | win_ptr: %p | or_a: %f | or_b: %f | mag: %f | iter: %d\n", fract.mlx_ptr, fract.win_ptr, fract.or_a, fract.or_b, fract.mag, fract.iter);
	printf("mlx_img: %p | addr: %p | Bits per pixel: %d | line size: %d | endian: %d\n", fract.img.mlx_img, fract.img.addr, fract.img.bpp, fract.img.line_len, fract.img.endian);
	init_events(&fract);
	draw_fractal(&(fract.img), &fract);

	mlx_loop(fract.mlx_ptr);
	// printf("Magnification Factor: %f | Origin a: %f | Origin b: %f\n", fract->mag, fract->or_a, fract->or_b);





}



