/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:50:38 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/23 19:22:02 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_len(int nb)
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
		nb /= 10;
	}
	return (count);
}

int	ft_putnb(int nb)
{
	int	res;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	res = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnb(nb / 10);
	res = (nb % 10) + '0';
	write(1, &res, 1);
	return (ft_nb_len(nb));
}
