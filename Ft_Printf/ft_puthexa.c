/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:23:40 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/24 16:45:02 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len (int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

int ft_puthexa(int nb, char id)
{
	char	*hexa_u;
	char	*hexa_l;
	int		count;
	int		res;

	count = ft_hexa_len(nb);
	hexa_l = "0123456789abcdef";
	hexa_u = "0123456789ABCDEF";
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb >= 16)
		ft_puthexa(nb / 16, id);
	res = nb % 16;
	if (id == 'x')
		write(1, &hexa_l[res], 1);
	else if (id == 'X')
		write(1, &hexa_u[res], 1);
	return (count);
}
