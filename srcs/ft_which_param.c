/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:50:08 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:15:53 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

const char	g_tab[22] =
{
	'd', 'i', 'f', 'e', 'g', 'c', 'u', 'o', 'x', 'p', 'X', 's', '%', 'h',
	'l', '-', '+', '0', ' ', '.', '#', '*'
};

static void	which_param_sub_2(int *cont, t_param *data, int *j)
{
	data->param = data->param | printf_two_pow(*j);
	if (*j < 13)
		*cont = 0;
	else if (*j >= 13 && *j < 15 && *cont < 4)
		*cont = 4;
	else if (*j == 19 && *cont < 2)
	{
		data->nb2 = data->nb;
		*cont = 2;
		data->nb = 0;
	}
	else if (*j == 19 && *cont >= 2 && *cont <= 3)
		*cont = 3;
	else if (*cont > 1)
		*cont = -1;
}

static int	which_param_sub(char c, int *cont, t_param *d, const char tab[20])
{
	int		j;

	j = 0;
	while (c != tab[j] && j < 22)
		j++;
	if (c >= '0' && c <= '9')
	{
		if (*cont < 3)
			d->nb = d->nb * 10 + c - '0';
	}
	else if (j < 22)
	{
		which_param_sub_2(cont, d, &j);
	}
	else
		*cont = -1;
	return (j);
}

int			which_param(char *str, t_param *data, int *shift, va_list *ap)
{
	int			i;
	int			size;
	int			cont;

	i = 1;
	cont = 1;
	if (str[i - 1] == '%')
	{
		while (cont > 0 && str[i] != '\0')
		{
			size = which_param_sub(str[i], &cont, data, g_tab);
			i++;
		}
		size = printf_func(size, data, ap);
	}
	if (cont == -1)
	{
		*shift += 2;
		return (ft_put_char(data, str + i - 1));
	}
	*shift += i;
	return (size);
}
