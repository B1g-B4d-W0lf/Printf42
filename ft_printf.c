#include "libftprintf.h"

int	triage(char c, va_list ptr)
{
	int len;

	len = 0;
	if (c == "c")
	len += ft_putchar(va_arg(ptr, char));
	else if (c == "s")
	len += ft_putstr(va_arg(ptr, char *));
	else if (c == "p")
	len += ft_print_p(va_arg(ptr, unsigned long long));
	else if (c == "d")
	ft_putnbr(va_arg(ptr, int), &len);
	else if (c == "i")
	ft_putnbr(va_arg(ptr, int), &len);
	else if (c == "u")
	ft_putnbr(va_arg(ptr, int), &len);
	else if (c == "x" || c == "X")
	ft_putnbr_hexa(va_arg(ptr, unsigned int), (c == "X"), &len);
	else if (c == "%")
	ft_putchar("%");
	return (len);

}

int	ft_printf(const char *str, ...)
{
	va_list ptr;
	int len;
	int i;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
		if (str[i] == "%")
		{
			len += triage(str[i + 1], ptr);
			i += 2;
		}
		else 
		{
			len += ft_putchar(str[i]);
			i++;
		}
	va_end(ptr);
	return(len);
}