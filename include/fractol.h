/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:40:20 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>

# define WIN_HT 600.0
# define WIN_LEN 800.0
# define WIN_NAME "fract-ol"
# define DEF_ITER 42
# define U_A 4.0
# define U_B 3.0
# define MAG_STEP 1.1
# define TRANS_STEP 0.25
# define ITER_STEP 1.01
# define COLOR_BLACK 0x000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cmplx_number
{
	double	re;
	double	img;
}	t_cmplx;

typedef struct s_fract
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	or_a;
	double	or_b;
	double	mag;
	int		iter;
	int		event;
	int		rng;
	int		set;
	t_cmplx	j_term;
}	t_fract;

/* Initialisation functions */
void	check_inputs(int argc, char *argv[]);
t_fract	init_fract(char *argv[]);
void	init_parameters(t_fract *fract);
void	init_events(t_fract *fract);
void	img_pixel_put(t_img *img, int x, int y, int color);

/* Hook functions used in the mlx hook functions */
int		mouse_event(int button, int x, int y, t_fract *fract);
int		key_event(int keysym, t_fract *fract);
int		no_event(t_fract *fract);
int		close_window(t_fract *fract);

/* Complex number operations */
t_cmplx	sqr_cmplx(t_cmplx input);
t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2);
double	magnitude_cmplx(t_cmplx input);
t_cmplx	tf_pixel_to_cmplx(int p_x, int p_y, t_fract *fract);

/* Draw Fractal functions */
int		check_mandelbrot(t_cmplx input, int no_iter);
int		draw_fractal(t_img *img, t_fract *fract);
int		check_julia(t_cmplx input, t_cmplx c_term, int no_iter);

#endif
