/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:59:05 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/24 21:32:26 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int	ft_u_nb_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 16;	
	}
	return (len);
}

int	ft_puthexa(unsigned int nb)
{
	char	*hex;
	int		res;
	int		len;

	len = ft_u_nb_len(nb);
	res = 0;
	hex = "0123456789abcdef";
	if (nb > 16)
		ft_puthexa(nb / 16);
	res = nb % 16;
	write(1, &hex[res], 1);
	return (len);
}

int	ft_nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_putnb(int nb)
{
	char	res;
	int		len;

	res = 0;
	len = ft_nb_len(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnb(nb / 10);
	res = (nb % 10) + '0';
	write(1, &res, 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len++;
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (len);
}

int ft_check_id(va_list ap, char id)
{
	int	len;

	len = 0;
	if (id == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (id == 'd')
		len = ft_putnb(va_arg(ap, int));
	else if (id == 'x')
		len = ft_puthexa(va_arg(ap, unsigned int));
	return (len);
}

int ft_printf(const char *str, ... )
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_check_id(ap, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			len = len + 1;	
		}
		i++;
	}
	va_end(ap);
	return (len);		
}
int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}