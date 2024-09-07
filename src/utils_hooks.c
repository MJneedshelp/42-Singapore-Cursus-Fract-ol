/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:36 by mintan            #+#    #+#             */
/*   Updated: 2024/09/07 15:24:28 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"
#include <mlx.h>
#include <math.h>


void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}


/* Description: function to be used in mlx_loop_hook when there are no events
   XXXXXXX
*/
int	hook_no_event(t_fract *fract)
{
	if (fract->win_ptr != NULL && fract->event == 1)
	{
		draw_mandelbrot(&(fract->img), fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img.mlx_img, 0, 0);
		fract->event = 0;
	}
	return (0);
}





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

/* Description: function to be used in mlx_key_hook
*/

int	hook_keypress(int keysym, t_fract *fract)
{
	printf("Key: %d pressed\n", keysym);
	fract->event = 1;
	if (keysym == XK_Escape)
		close_window(fract);
	else if (keysym == XK_Up)
		fract->or_b = fract->or_b - (TRANS_STEP * fract->mag);
	else if (keysym == XK_Down)
		fract->or_b = fract->or_b + (TRANS_STEP * fract->mag);
	else if (keysym == XK_Right)
		fract->or_a = fract->or_a - (TRANS_STEP * fract->mag);
	else if (keysym == XK_Left)
		fract->or_a = fract->or_a + (TRANS_STEP * fract->mag);
	else if (keysym == XK_KP_Add)
		fract->iter += 10;
	else if (keysym == XK_KP_Subtract)
		fract->iter -= 10;
	else if (keysym == XK_space)
	{
		//probably can put this in a function
		fract->or_a = 0.0;
		fract->or_b = 0.0;
		fract->mag = 1.0;
		fract->iter = DEF_ITER;
	}
	printf("or_a: %f | or_b: %f | mag: %f | iter: %d\n", fract->or_a, fract->or_b, fract->mag, fract->iter);
	return (0);
}

int	hook_keyrelease(int keysym, t_fract *fract)
{
	printf("Key released\n");
	return (0);
}
