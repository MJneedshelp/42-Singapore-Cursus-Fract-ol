/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:09:25 by mintan            #+#    #+#             */
/*   Updated: 2024/09/07 19:26:21 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: prints out an error message. Function is used when the inputs
   into the programme are unexpected. Exits the programme afterwards.
*/
void	print_error(void)
{
	ft_putendl_fd("Please run the programmme in the following ways:", 2);
	ft_putendl_fd("./fractol mandelbrot OR", 2);
	ft_putendl_fd("./fractol julia <value 1> <value 2>", 2);
	ft_putendl_fd("where <value 1> and <value 2> are both doubles. E.g.",2);
	ft_putendl_fd("./fractol julia 0.285 0.01", 2);
	exit (EXIT_FAILURE);
}





/* Description: checks if the binary is run with the correct input arguments.
   Actions:
	1. Check if there are any input arguments: exit if there are no arguments
	2. Check argc 1 is either "mandelbrot or julia"
	3. If mandelbrot:
	   - there should not be any other arguments
	   - exit if there are extra arguments
	4. If Julia
	   - there should be 2 other arguments
	   - check if the 2 other arguments are doubles
	   - exit if any of the above conditons fail
*/

void	check_inputs(int argc, char* argv[])
{
	if (argc == 1)
		print_error();
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && \
		ft_strlen(argv[1]) == 10)
		{
			if (argc > 2)
				print_error();
			return ;
		}
		else if (ft_strncmp(argv[1], "julia", 5) == 0 && \
		ft_strlen(argv[1]) == 5)
		{
			if (argc != 4)
				print_error();

			//check for double
			return ;
		}
		else
			print_error();
	}
}

/* Desciption: Sets the initial parameters for rendering:
	- or_a: origin of a - real on the complex plane
	- or_b: origina of b - imaginary on the complex plane
	- mag: magnification. A lower number corresponds to higher zoom
	- iter: number of iterations
*/
void	init_parameters(t_fract *fract)
{	fract->or_a = -0.5;
	fract->or_b = 0.0;
	fract->mag = 1.0;
	fract->iter = DEF_ITER;
}


/* Description: Initialises the fract structure.
   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/

t_fract	init_fract(void)
{
	t_fract	fract;

	fract.mlx_ptr = mlx_init();
	if (fract.mlx_ptr == NULL)
		exit (EXIT_FAILURE);//Probably write a clean up function here
	fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
	if (fract.win_ptr == NULL)
	{
		free (fract.mlx_ptr);//Probably write a clean up function here
		exit (EXIT_FAILURE);
	}
	fract.img.mlx_img = mlx_new_image(fract.mlx_ptr, WIN_LEN, WIN_HT);
	fract.img.addr = mlx_get_data_addr(fract.img.mlx_img, &(fract.img.bpp),\
	&(fract.img.line_len), &(fract.img.endian));
	init_parameters(&fract);
	fract.event = 1;
	return (fract);
}






















// /* Description: Initialises the fract structure.
//    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// */

// t_fract	*init_fract(void)
// {
// 	t_fract	*fract;

// 	fract = (t_fract *)malloc(sizeof(t_fract));
// 	if (fract == NULL)
// 		exit (EXIT_FAILURE);
// 	fract->mlx_ptr = mlx_init();
// 	if (fract->mlx_ptr == NULL)
// 	{
// 		free (fract);					//Probably write a clean up function here
// 		exit (EXIT_FAILURE);
// 	}
// 	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
// 	if (fract->win_ptr == NULL)
// 	{
// 		free (fract->mlx_ptr);
// 		free (fract);					//Probably write a clean up function here
// 		exit (EXIT_FAILURE);
// 	}
// 	fract->img.mlx_img = mlx_new_image(fract->mlx_ptr, WIN_LEN, WIN_HT);
// 	fract->img.addr = mlx_get_data_addr(fract->img.mlx_img, &(fract->img.bpp), &(fract->img.line_len), &(fract->img.endian));
// 	fract->or_a = -0.5;
// 	fract->or_b = 0.0;
// 	fract->mag = 1.0;
// 	fract->iter = DEF_ITER;
// 	fract->event = 1;
// 	printf("Bits per pixel: %d | line size: %d | endian: %d\n", fract->img.bpp, fract->img.line_len, fract->img.endian);


// 	// mlx_get_data_addr(fract->img->mlx_img, fract->img->bpp, fract->img->line_len, fract->img->endian);
// 	// printf("img bpp value: %d\n", fract->img->bpp);
// 	return (fract);
// }


void	end_prog(t_fract fract)
{
	mlx_destroy_window(fract.mlx_ptr, fract.win_ptr);
	fract.win_ptr = NULL;

	mlx_destroy_display(fract.mlx_ptr);
	mlx_destroy_image(fract.mlx_ptr, &fract.img);
	free (fract.mlx_ptr);
	free (fract.img.addr);
	free (fract.img.mlx_img);
	//Probably need to clear up the img pointer as well


	exit (EXIT_SUCCESS);

}





// int	main(int argc, char *argv[])
// {
// 	printf("Argc: %d | argv[1]: %s \n", argc, argv[1]);
// 	check_inputs(argc, argv);
// 	printf("Input validated\n");
// }
