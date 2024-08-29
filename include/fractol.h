/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2024/08/29 16:41:52 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_HT 720
# define WIN_LEN 1280
# define WIN_NAME "fract-ol"
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_WHITE 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fract
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_fract;





typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	colour;
}	t_rect;





/* Utility functions */
t_fract	*init_fract(void);
void	end_prog(t_fract *fract);


/* Hook functions */
int		hook_no_event(t_fract *fract);
int		hook_key_event(int keysym, t_fract *fract);
int		hook_mouse_event(int button, int x, int y, t_fract *fract);

int		hook_keypress(int keysym, t_fract *fract);
int		hook_keyrelease(int keysym, t_fract *fract);

// int		draw_rect(t_fract *fract, t_rect rect);

/* Window management functions */
int		close_window(t_fract *fract);

#endif
