/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:03:25 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/23 19:09:08 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	while (str[count])
		count++;
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (count);
}
