/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <adrien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:47:23 by adlecler          #+#    #+#             */
/*   Updated: 2022/03/01 20:10:29 by adrien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	char	*test = "coucou";
	(void)ac;
	(void)av;
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un char (c) : %c\n", 'C'));
	printf("Retour attendu: %d\n", printf("Ceci est un char (c) : %c\n", 'C'));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est une string (s) : %s\n", NULL));
	printf("Retour attendu: %d\n", printf("Ceci est une string (s) : %s\n", NULL));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est une string (s) : %s\n", "Hello World!"));
	printf("Retour attendu: %d\n", printf("Ceci est une string (s) : %s\n", "Hello World!"));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est une string (s) : %s\n", ""));
	printf("Retour attendu: %d\n", printf("Ceci est une string (s) : %s\n", ""));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un hexa (X) : %X\n", 42));
	printf("Retour attendu: %d\n", printf("Ceci est un hexa (X) : %X\n", 42));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un hexa (x) : %x\n", 160));
	printf("Retour attendu: %d\n", printf("Ceci est un hexa (x) : %x\n", 160));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un pourcentage : %%\n"));
	printf("Retour attendu: %d\n", printf("Ceci est un pourcentage : %%\n"));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un decimal (d) : %d\n", (2147483647)));
	printf("Retour attendu: %d\n", printf("Ceci est un decimal (d) : %d\n", (2147483647)));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un decimal (i) : %i\n", 666));
	printf("Retour attendu: %d\n", printf("Ceci est un decimal (i) : %i\n", 666));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est un unsigned int (u) : %u\n", 4294967295 + 2));
	printf("Retour attendu: %d\n", printf("Ceci est un unsigned int (u) : %u\n", 4294967295 + 2));
	ft_printf("Mon retour: %d\n", ft_printf("Ceci est une adresse (p) : %p\n", &test));
	printf("Retour attendu: %d\n", printf("Ceci est une adresse (p) : %p\n", &test));
	ft_printf("Mon retour: %d\n", ft_printf("C'est de la merde : %c%s%%%p\n", 'c', "coucou", "42"));
	printf("Retour attendu: %d\n", printf("C'est de la merde : %c%s%%%p\n", 'c', "coucou", "42"));
	ft_printf("ft_printf: %d\n", ft_printf("Test 2 : \" %%%% \" \nYour return :"));
	printf("printf: %d\n", printf("Test 2 : \" %%%% \" \nYour return :"));
	return (0);
}
