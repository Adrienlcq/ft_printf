/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlecler <adlecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:05:04 by adlecler          #+#    #+#             */
/*   Updated: 2022/02/25 22:36:53 by adlecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

/* struct */
typedef struct s_data
{
	int		ret;
	//long	nb;
	//char	buff[5000];
	va_list	args;
}				t_data;

/* corps ft_printf */
int		ft_printf(const char *format, ...);
void	ft_type(t_data *data, char c);
int		is_ok(char c);

/* treat cspdiuxX% */
int		ft_treat_s(t_data *data);
int		ft_treat_x(t_data *data, char c);
int		ft_treat_percentage(char c);
int		ft_treat_ptr(unsigned long n, char *hex);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_uputnbr(unsigned int n);

/* utils */
int		ft_strlen(char *str);
int		ft_hex_putnbr(unsigned int n, char *hexa);
int		ft_point_print(unsigned long n, char *hex);

#endif
