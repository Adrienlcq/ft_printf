/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <adrien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:40:37 by adlecler          #+#    #+#             */
/*   Updated: 2022/03/01 20:06:24 by adrien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* init struct */
void	init(t_data *data)
{
	data->ret = 0;
}

void	ft_type(t_data *data, char c)
{
	if (c == 'p')
		data->ret += ft_treat_ptr(va_arg(data->args, unsigned long int),
				"0123456789abcdef");
	if (c == 'd' || c == 'i')
		data->ret += ft_putnbr(va_arg(data->args, int));
	if (c == 'c')
		data->ret += ft_putchar(va_arg(data->args, int));
	if (c == 'u')
		data->ret += ft_uputnbr(va_arg(data->args, int));
	if (c == 's')
		data->ret += ft_treat_s(va_arg(data->args, char*));
	if (c == 'x')
		data->ret += ft_hex_putnbr(va_arg(data->args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		data->ret += ft_hex_putnbr(va_arg(data->args, unsigned int),
				"0123456789ABCDEF");
	if (c == '%')
		data->ret += ft_treat_percentage('%');
}

int	is_ok(char c)
{
	return (c == 's' || c == 'x' || c == 'c' || c == 'X' || c == '%'
		|| c == 'd' || c == 'i' || c == 'u' || c == 'p');
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	int		i;

	i = 0;
	va_start(data.args, format);
	init(&data);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (!is_ok(format[i]))
				i++;
			ft_type(&data, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			data.ret++;
		}
		i++;
	}
	va_end(data.args);
	return (data.ret);
}
