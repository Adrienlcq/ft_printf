/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:22:54 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/28 14:14:03 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* treat c */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* treat i and d */
int	ft_putnbr(int n)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
		i += ft_putchar(nbr + '0');
	return (i);
}

/* treat u */
int	ft_uputnbr(unsigned int n)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	if (nbr >= 10)
	{
		i += ft_uputnbr(n / 10);
		i += ft_uputnbr(n % 10);
	}
	else
	{
		i += ft_putchar(nbr + '0');
	}
	return (i);
}

/* utils */
int	hexa_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
