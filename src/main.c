/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:47:47 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

int	main(int argc, char *argv[])
{
	t_fract	fract;

	check_inputs(argc, argv);
	fract = init_fract(argv);
	init_events(&fract);
	mlx_loop_hook(fract.mlx_ptr, &no_event, &fract);
	mlx_loop(fract.mlx_ptr);
}
