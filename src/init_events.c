/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:54 by mintan            #+#    #+#             */
/*   Updated: 2024/09/12 11:53:56 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: XXXXXXX
*/

static	int	mouse_event(int button, int x, int y, t_fract *fract)
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
	printf("or_a: %f | or_b: %f | mag: %f | iter: %d\n", fract->or_a, fract->or_b, fract->mag, fract->iter);
	// draw_fractal(&(fract->img), fract);
	return (0);
}

/* Description: XXXXXXX
*/

int	hook_keypress(int keysym, t_fract *fract)
{
	printf("Key: %d pressed\n", keysym);
	fract->event = 1;
	if (keysym == XK_Escape)
		close_window(fract);
	else if (keysym == XK_Up)
		fract->or_b = fract->or_b + (TRANS_STEP * fract->mag);
	else if (keysym == XK_Down)
		fract->or_b = fract->or_b - (TRANS_STEP * fract->mag);
	else if (keysym == XK_Right)
		fract->or_a = fract->or_a + (TRANS_STEP * fract->mag);
	else if (keysym == XK_Left)
		fract->or_a = fract->or_a - (TRANS_STEP * fract->mag);
	else if (keysym == XK_KP_Add || keysym == XK_bracketright)
		fract->iter += 10;
	else if (keysym == XK_KP_Subtract || keysym == XK_bracketleft)
		fract->iter -= 10;
	else if (keysym == XK_space)
		init_parameters(fract);
	printf("or_a: %f | or_b: %f | mag: %f | iter: %d\n", fract->or_a, fract->or_b, fract->mag, fract->iter);
	// draw_fractal(&(fract->img), fract);
	return (0);
}





/* Description: Closes the window, destroys the image and destroys the display.
   The function then exits the programme afterwards. This function is called
   when the window is closed either with the ESC key or the X button on the
   window is clicked.
*/
int	close_window(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fract->win_ptr = NULL;
	mlx_destroy_image(fract->mlx_ptr, fract->img.mlx_img);
	fract->img.mlx_img = NULL;
	mlx_destroy_display(fract->mlx_ptr);
	free (fract->mlx_ptr);
	fract->mlx_ptr = NULL;
	exit (EXIT_SUCCESS);
}



/* Description: initialises all the mouse and key events.
*/

void	init_events(t_fract *fract)
{
	mlx_mouse_hook(fract->win_ptr, mouse_event, fract);
	mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);
	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, hook_keypress, fract);
}
