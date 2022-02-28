/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:33:24 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/28 14:10:59 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* treat % */
int	ft_treat_percentage(char c)
{
	write(1, &c, 1);
	return (1);
}

/* treat s */
int	ft_treat_s(t_data *data)
{
	char	*str;

	str = va_arg(data->args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

/* treat x and X */
int	ft_hex_putnbr(unsigned int n, char *hexa)
{
	int		i;

	i = 0;
	if (n >= 16)
		i += ft_hex_putnbr((n / 16), hexa);
	i += ft_putchar(hexa[(n % 16)]);
	return (i);
}

/* treat p */
int	ft_treat_ptr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_point_print(n, hex);
	return (i);
}

int	ft_point_print(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_point_print((n / 16), hex);
	i += ft_putchar(hex[(n % 16)]);
	return (i);
}
