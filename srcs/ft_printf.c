/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:02:06 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:13:39 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

static int	find_next_percent(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			return (i);
		i++;
	}
	return (-1);
}

int			ft_printf(char *str, ...)
{
	int		i;
	int		ret;
	int		nb_char;
	t_param	data;
	va_list	ap;

	nb_char = 0;
	i = 0;
	va_start(ap, str);
	while ((ret = find_next_percent((str + i))) != -1)
	{
		data.param = 0;
		data.nb = 0;
		write(1, (str + i), ret);
		nb_char += ret;
		nb_char += which_param(str + ret + i, &data, &i, &ap);
		i += ret;
	}
	va_end(ap);
	nb_char += printf_putstr(str + i);
	return (nb_char);
}
