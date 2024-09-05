/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/09/05 19:46:31 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>






int	main(void)
{
	t_fract	*fract;

	fract = init_fract();



	mlx_mouse_hook(fract->win_ptr, hook_mouse_event, fract);

	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &hook_keypress, fract);
	mlx_hook(fract->win_ptr, KeyRelease, KeyReleaseMask, &hook_keyrelease, fract);
	mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);

	mlx_loop_hook(fract->mlx_ptr, &hook_no_event, fract);
	mlx_loop(fract->mlx_ptr);
	printf("Magnification Factor: %f | Origin a: %f | Origin b: %f\n", fract->mag, fract->or_a, fract->or_b);

	end_prog(fract);
}
