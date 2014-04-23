/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:54:45 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:13:26 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

int		printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		printf_putstr(char *str)
{
	int		len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			len++;
		write (1, str, len);
	}
	else
	{
		len = 6;
		write(1, "(null)", len);
	}
	return (len);
}

int		printf_two_pow(int nb)
{
	int		ret;

	ret = 1;
	while (nb > 0)
	{
		ret *= 2;
		nb--;
	}
	return (ret);
}

int		printf_strlen(char *str)
{
	int		i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (6);
}

int		printf_fill(int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}
