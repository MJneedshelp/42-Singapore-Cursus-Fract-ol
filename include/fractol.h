/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2024/09/02 13:26:33 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_HT 400.0
# define WIN_LEN 500.0
# define WIN_NAME "fract-ol"
# define DEF_ITER 20
# define COMPLEX_MAX_A 2.0
# define COMPLEX_MAX_B 2.0
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

typedef struct s_cmplx_number
{
	double	re;
	double	img;
}	t_cmplx;



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





/* Complex number operations */
t_cmplx	sqr_cmplx(t_cmplx input);
t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2);
double	magnitude_cmplx(t_cmplx input);



/* Mandelbrot set functions */






#endif
