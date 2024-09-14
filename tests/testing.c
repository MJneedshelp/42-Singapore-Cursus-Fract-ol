#include <stdint.h>
#include <stdio.h>
#include "include/libft.h"



// int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
//     return (red << 16 | green << 8 | blue);
// }

// int	main(void)
// {
// 	int	color_code;

// 	color_code = encode_rgb(245, 209, 66);

// 	printf("Colour code: %d\n", color_code);
// 	perror("test");
// }


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
