/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:36 by mintan            #+#    #+#             */
/*   Updated: 2024/08/28 13:29:29 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>

/* Description: function to be used in mlx_loop_hook when there are no events
*/
int	hook_no_event(void)
{
	return (0);
}


/* Description: function to be used in mlx_key_hook
*/
int	hook_key_event(int keysym, t_fract *fract)
{
	if (keysym == XK_Escape)
		close_window(fract);
	if (keysym == XK_0)
		printf("Key sym: %d\n", keysym);
	return (0);
}


int	hook_mouse_event(int button, int x, int y, t_fract *fract)
{
	printf("Button: %d | position x: %d y: %d\n", button, x, y);
	return (0);
}


int	hook_keypress(int keysym, t_fract *fract)
{
	printf("Key pressed\n");
	if (keysym == XK_Escape)
		mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	return (0);
}

int	hook_keyrelease(int keysym, t_fract *fract)
{
	printf("Key released\n");
	return (0);
}
