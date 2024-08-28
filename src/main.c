/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/08/28 13:30:34 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>






int	deal_key(int keycode, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	ft_printf("Keycode: %d\n", keycode);
	mlx_pixel_put(fract->mlx_ptr, fract->win_ptr, keycode/10, keycode/10, 0xFFFFFF);
	if (keycode == 65307)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
		printf("Window destroyed\n");
	}
	return (0);
}




int	main(void)
{
	t_fract	*fract;

	fract = init_fract();

	mlx_loop_hook(fract->mlx_ptr, &hook_no_event, NULL);

	// mlx_key_hook(fract->win_ptr, &hook_key_event, fract);

	mlx_mouse_hook(fract->win_ptr, hook_mouse_event, fract);

	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &hook_keypress, fract);
	mlx_hook(fract->win_ptr, KeyRelease, KeyReleaseMask, &hook_keyrelease, fract);
	mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);


	mlx_loop(fract->mlx_ptr);


	end_prog(fract);
}
