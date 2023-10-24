/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorido <jflorido@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:51 by jflorido          #+#    #+#             */
/*   Updated: 2023/10/24 16:45:29 by jflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Libraries
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

//list of functions
int	ft_what_id(va_list ap, char id);
int	ft_putchar(char c);
int	ft_putnb(int nb);
int	ft_putstr(char *str);
int ft_puthexa(int nb, char id);
int	ft_hexa_len (int nb);

#endif
