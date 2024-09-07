/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/09/07 19:45:45 by mintan           ###   ########.fr       */
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

	fract = init_fract();
	printf("mlx_ptr: %p | win_ptr: %p | or_a: %f | or_b: %f | mag: %f | iter: %d\n", fract.mlx_ptr, fract.win_ptr, fract.or_a, fract.or_b, fract.mag, fract.iter);
	printf("mlx_img: %p | addr: %p | Bits per pixel: %d | line size: %d | endian: %d\n", fract.img.mlx_img, fract.img.addr, fract.img.bpp, fract.img.line_len, fract.img.endian);

	draw_mandelbrot(&(fract.img), fract);


	// mlx_mouse_hook(fract->win_ptr, hook_mouse_event, fract);

	// mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &hook_keypress, fract);
	// mlx_hook(fract->win_ptr, KeyRelease, KeyReleaseMask, &hook_keyrelease, fract);
	// mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);

	// // mlx_loop_hook(fract->mlx_ptr, &hook_no_event, fract);
	// draw_mandelbrot(&(fract->img), fract);
	// mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.mlx_img, 0, 0);

	mlx_loop(fract.mlx_ptr);
	// printf("Magnification Factor: %f | Origin a: %f | Origin b: %f\n", fract->mag, fract->or_a, fract->or_b);





	//logic to add for loop_hook
	//Add some sort of boolean variable into fract struct
	//events should set this var to 1
	//loop hook function checks if event is 1 to execute the draw fractal
	//this var should start at 1 to draw at the start

	end_prog(fract);

}
