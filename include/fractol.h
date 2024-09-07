/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2024/09/07 09:09:01 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_HT 600.0
# define WIN_LEN 800.0
# define WIN_NAME "fract-ol"
# define DEF_ITER 750
# define U_A 4.0
# define U_B 3.0
# define MAG_STEP 1.1
# define TRANS_STEP 0.01
# define ITER_STEP 1.01
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLACK 0x000000

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
	double	or_a;
	double	or_b;
	double	mag;
	double	iter;
	int		event;
}	t_fract;

typedef struct s_cmplx_number
{
	double	re;
	double	img;
}	t_cmplx;

typedef struct s_transformation_factors
{
	double	or_a;
	double	or_b;
	double	mag;
}	t_tf_fact;



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

void	img_pixel_put(t_img *img, int x, int y, int color);


// int		draw_rect(t_fract *fract, t_rect rect);

/* Window management functions */
int		close_window(t_fract *fract);





/* Complex number operations */
t_cmplx	sqr_cmplx(t_cmplx input);
t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2);
double	magnitude_cmplx(t_cmplx input);
t_cmplx	tf_pixel_to_cmplx(int p_x, int p_y, t_fract *fract);




/* Mandelbrot set functions */
int	check_mandelbrot(t_cmplx input, int no_iter);
int	draw_mandelbrot(t_img *img, t_fract *fract);







#endif
