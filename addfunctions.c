#include "libftprintf.h"

int ft_putchar(char c)
{
	write(1, c, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while (str)
	{
		write(1, str[i], 1);
		i++;
	}
	return(i);
}

int ft_putnbr_hexa(unsigned int n, int c, int *len)
{
	if (n >= 16)
		ft_putnbr_hexa(n/16, c, len);
	ft_putchar(HEXA[n%16 + c*16]);
	return(*len += 1);
}

int	ft_putnbr(int n, int *len)
{
	if (n >= 10)
		ft_putnbr(n/10, len);
	ft_putchar(48 + n%10);
	return(*len += 1);
}

int	ft_putnbr_p(unsigned long long n, int *len)
{
		if (n >= 16)
		ft_putnbr_p(n/16, len);
	ft_putchar(HEXA[n%16]);
	return(*len += 1);
}

int	ft_print_p(unsigned long long ptr)
{
	int	len;
	
	len = ft_putstr("0x");
	if (ptr == 0)
		len += ft_putchar("0");
	else
		ft_putnbr_p(ptr, &len);
	return (len);
}