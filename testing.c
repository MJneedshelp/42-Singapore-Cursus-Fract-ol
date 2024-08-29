#include <stdint.h>
#include <stdio.h>


int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    return (red << 16 | green << 8 | blue);
}

int	main(void)
{
	int	color_code;

	color_code = encode_rgb(245, 209, 66);

	printf("Colour code: %d\n", color_code);
}
