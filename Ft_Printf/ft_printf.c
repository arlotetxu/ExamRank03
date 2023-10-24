/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:16:04 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/24 18:40:45 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Format Specifier	                    Type
%c	                                    Character
%d		                                Signed integer
%e or %E	                            Scientific notation of floats
%f	                                    Float values
%g or %G	                            Similar as %e or %E
%hi	                                    Signed integer (short)
%hu	                                    Unsigned Integer (short)
%i	                                    Unsigned integer
%l or %ld or %li	                    Long
%lf	                                    Double
%Lf	                                    Long double
%lu	                                    Unsigned int or unsigned long
%lli or %lld	                        Long long
%llu	                                Unsigned long long
%o	                                    Octal representation
%p	                                    Pointer
%s	                                    String
%u	                                    Unsigned int
%x or %X	                            Hexadecimal representation
%n	                                    Prints nothing
%%	                                    Prints % character
*/
/* Deberás implementar las siguientes conversiones: cspdiuxX % */

#include "ft_printf.h"

int	ft_what_id(va_list ap, char id)
{
	int	len;

	len = 0;
	if (id == 'c')
		len = ft_putchar(va_arg(ap, int));
	else if (id == 'd' || id == 'i')
		len = ft_putnb(va_arg(ap, int));
	else if (id == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (id == 'x' || id == 'X')
		len = ft_puthexa(va_arg(ap, int), id);
	else if (id == 'p')
		len = ft_putstr("0x") + ft_puthexa(va_arg(ap, int), 'x');

	return (len);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int	len;
	int	i;

	va_start(ap, str);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_what_id(ap, str[i]);
		}
		else
			len = len + ft_putchar(str[i]);
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	printf("\nCount nb: %d\n", ft_puthexa(-458, 'X'));
	return (0);
}
