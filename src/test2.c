#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"


/* Description: Takes in a string and checks if all characters are digits.
   - Allows for ' ', '\t', '\r', at the start of the string.
   - Allows for either 1 '+' or '-' after the spaces, before the digits
   - return:
		- 1: the string is numeric
		- 0: the string is not numeric
   */

// int	check_numeric(char *str)
// {
// 	int	i;
// 	int	dot;

// 	i = 0;
// 	dot = 0;
// 	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 		i++;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '.')
// 		{
// 			dot++;
// 			if (dot > 1)
// 				return (0);
// 		}
// 		else if (ft_isdigit(str[i]) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }


int	check_numeric(char *str)
{
	int	ctr;
	int	dot;

	ctr = 0;
	dot = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
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


int	main(void)
{
	printf("Check wrong: check_numeric: %d\n", check_numeric("wrong"));
	printf("Check 12345: check_numeric: %d\n", check_numeric("12345"));
	printf("Check +12345: check_numeric: %d\n", check_numeric("+12345"));
	printf("Check -12345: check_numeric: %d\n", check_numeric("-12345"));
	printf("Check ++12345: check_numeric: %d\n", check_numeric("++12345"));
	printf("Check --12345: check_numeric: %d\n", check_numeric("--12345"));
	printf("Check 12345.04: check_numeric: %d\n", check_numeric("12345.04"));
	printf("Check 12345.0.4: check_numeric: %d\n", check_numeric("12345.0.4"));
	printf("Check +12345.04: check_numeric: %d\n", check_numeric("+12345.04"));
	printf("Check -12345.04: check_numeric: %d\n", check_numeric("-12345.04"));
	printf("Check ++12345.04: check_numeric: %d\n", check_numeric("++12345.04"));
	printf("Check --12345.04: check_numeric: %d\n", check_numeric("--12345.04"));
	printf("Check 0.04: check_numeric: %d\n", check_numeric("0.04"));
	printf("Check +0.04: check_numeric: %d\n", check_numeric("+0.04"));
	printf("Check -0.04: check_numeric: %d\n", check_numeric("-0.04"));
	printf("Check .04: check_numeric: %d\n", check_numeric(".04"));
	printf("Check +: check_numeric: %d\n", check_numeric("+"));
	printf("Check -: check_numeric: %d\n", check_numeric("-"));


}
