/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:54 by mintan            #+#    #+#             */
/*   Updated: 2024/09/07 19:47:50 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"



int	hook_mouse_event(int button, int x, int y, t_fract *fract)
{
	printf("Button: %d | position x: %d y: %d\n", button, x, y);
	if (button == 5)
	{
		fract->mag = (fract->mag) / MAG_STEP;
		// fract->iter = (fract->iter) / ITER_STEP;
		fract->event = 1;
	}
	else if (button == 4)
	{
		fract->mag = (fract->mag) * MAG_STEP;
		// fract->iter = (fract->iter) * ITER_STEP;
		fract->event = 1;
	}
	return (0);
}



/* Description: initialises all the mouse and key events

*/

void	init_events(t_fract fract)
{
	mlx_mouse_hook(fract.win_ptr, hook_mouse_event, &fract);

}

	// mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, &hook_keypress, fract);
	// mlx_hook(fract->win_ptr, KeyRelease, KeyReleaseMask, &hook_keyrelease, fract);
	// mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);
