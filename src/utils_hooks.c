/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:36 by mintan            #+#    #+#             */
/*   Updated: 2024/08/29 09:38:03 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>


int	draw_rect(t_fract *fract, t_rect rect)
{
	int	i;
	int	j;

	i = rect.x;
	while (i < rect.x + rect.width)
	{
		j = rect.y;
		while (j < rect.y + rect.height)
		{
			mlx_pixel_put(fract->mlx_ptr, fract->win_ptr, i, j, rect.colour);
			j++;
		}
		i++;
	}
}

int	draw_bkground(t_fract *fract)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_LEN)
	{
		j = 0;
		while (j < WIN_HT)
		{
			mlx_pixel_put(fract->mlx_ptr, fract->win_ptr, i, j, COLOR_WHITE);
			j++;
		}
		i++;
	}
}






/* Description: function to be used in mlx_loop_hook when there are no events
*/
int	hook_no_event(t_fract *fract)
{
	if (fract->win_ptr != NULL)
	{
		draw_bkground(fract);
		draw_rect(fract, (t_rect){WIN_LEN - 100, WIN_HT - 100, 100, 100, COLOR_GREEN});
		draw_rect(fract, (t_rect){0, 0, 100, 100, COLOR_RED});

		// draw_rect(fract);
	}
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
		close_window(fract);
	return (0);
}

int	hook_keyrelease(int keysym, t_fract *fract)
{
	printf("Key released\n");
	return (0);
}
