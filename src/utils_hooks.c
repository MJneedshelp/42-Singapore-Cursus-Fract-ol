/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:13:36 by mintan            #+#    #+#             */
/*   Updated: 2024/08/28 10:13:36 by mintan           ###   ########.fr       */
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

int	hook_key_event(int keysym, t_fract *fract)
{
	if (keysym == XK_Esca)
}
