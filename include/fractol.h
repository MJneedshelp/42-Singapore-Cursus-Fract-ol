/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2024/08/27 19:31:34 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>

# define WIN_HT 720
# define WIN_LEN 1280
# define WIN_NAME "fract-ol"

typedef struct s_fract
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fract;


/* Utility functions */
t_fract	*init_fract(void);
void	end_prog(t_fract *fract);


/* Hook functions */
int		hook_no_event(void);

#endif
