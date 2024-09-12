/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/09/12 08:07:49 by mintan           ###   ########.fr       */
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
	init_events(&fract);
	draw_mandelbrot(&(fract.img), &fract);

	mlx_loop(fract.mlx_ptr);
	// printf("Magnification Factor: %f | Origin a: %f | Origin b: %f\n", fract->mag, fract->or_a, fract->or_b);





}






int	check_numeric(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot++;
		else if (ft_isdigit(str[i]) == 0)
			return (0);

		i++;
	}
	return (1);
}
