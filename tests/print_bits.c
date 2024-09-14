#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	c;

	for (int i = 7; i >= 0; i--)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	print_bits(240);
}
