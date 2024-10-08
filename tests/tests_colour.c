# include <stdio.h>
# include <stdint.h>

int	gen_colour(int iter)
{
	uint8_t	red;
	uint8_t green;
	uint8_t	blue;

	red = 255;
	blue = 255;
	green = 255;

	if (iter <= 242)
	{
		red = (uint8_t)((iter - 42) / 200 * 255);
	}
	else if (iter >= 243 && iter <= 442)
	{
		blue = (uint8_t)((iter - 42) / 400 * 255);
	}
	else if (iter >= 443 && iter <= 642)
	{
		green = (uint8_t)((iter - 42) / 600 * 255);
	}
	printf("Red: %d | Green: %d | Blue: %d\n", red, green, blue);
	return (red << 16 | green << 8 | blue);
}


int	rngsus(int iter, int comparison)
{
	int	roll;

	roll = ((iter ^ comparison) + 42) % 255;
	return (roll);
}



int	main(void)
{
	double	result;
	int		iter;

	result = (65.0 / 200.0) * 255.0;
	iter = 42;
	iter = 42 * 1.01 * 1.01 * 1.01 * 1.01 * 1.01;
	printf("Print test int multiplication: %d\n", iter);
	iter = iter / 1.01 / 1.01 / 1.01 / 1.01 / 1.01;
	printf("Print test int division: %d\n", iter);
	printf("Dice roll: %d\n", rngsus(42, 42));


	// gen_colour(0);
	// printf("Result: %d\n", (uint8_t)result);

}


