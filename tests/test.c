#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putlongnbr_fd(long l, int fd, int base)
{
	char	ascii_c;

	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putlongnbr_fd(-l, fd, base);
	}
	else if (l > base -1)
	{
		ft_putlongnbr_fd(l / base, fd, base);
		ft_putlongnbr_fd(l % base, fd, base);
	}
	else
	{
		ascii_c = l + 48;
		ft_putchar_fd(ascii_c, fd);
	}
}

int main(){
	ft_putlongnbr_fd(2, 1, 2);
}
