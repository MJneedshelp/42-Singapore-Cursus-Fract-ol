/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:05:49 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 17:13:16 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: prints out an error message. Function is used when the inputs
   into the programme are unexpected. Exits the programme afterwards.
*/
static void	print_error(void)
{
	ft_putendl_fd("Please run the programmme in the following ways ONLY:", 2);
	ft_putendl_fd("./fractol mandelbrot OR", 2);
	ft_putendl_fd("./fractol julia <value 1> <value 2>", 2);
	ft_putendl_fd("where <value 1> and <value 2> are both doubles. E.g.", 2);
	ft_putendl_fd("./fractol julia 0.285 0.01", 2);
	exit (EXIT_FAILURE);
}

/* Description: Takes in a string and checks if all characters are digits.
   - Allows for ' ', '\t', '\r', at the start of the string.
   - Allows for either 1 '+' or '-' after the spaces, before the digits
   - Allows for 1 '.' for decimals
   - return:
		- 1: the string is numeric
		- 0: the string is not numeric
   */

static int	check_numeric(char *str)
{
	int	ctr;
	int	dot;

	ctr = 0;
	dot = 0;
	while (((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str == '.')
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		else if (ft_isdigit(*str) == 0)
			return (0);
		else
			ctr++;
		str++;
	}
	if (ctr < 1)
		return (0);
	return (1);
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

void	check_inputs(int argc, char *argv[])
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
			if (check_numeric(argv[2]) == 0 || check_numeric(argv[2]) == 0)
				print_error();
			return ;
		}
		else
			print_error();
	}
}
