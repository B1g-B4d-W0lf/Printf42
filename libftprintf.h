#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <io.h>
# include <stdarg.h>

# define HEXA "0123456789abcdef0123456789ABCDEF"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_hexa(unsigned int n, int c, int *len);
int	ft_putnbr(int n, int *len);
int	ft_putnbr_p(unsigned long long n, int *len);
int	ft_print_p(unsigned long long ptr);
int	triage(char c, va_list ptr);
int	ft_printf(const char *str, ...);
int	ft_putnbr_u(unsigned int n, int *len);

#endif