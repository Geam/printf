/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:24:36 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:14:10 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

int		ft_putlong(long n, int size)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		size += 1;
	}
	if (n >= 10)
		size = ft_putlong(n / 10, size);
	size += printf_putchar(n % 10 + '0');
	return (size);
}

int		ft_put_long(t_param *data, void *nbr)
{
	int		size;
	int		min;

	size = 0;
	min = printf_fill_nbrlen(data, nbr);
	if (!(data->param & PARAM_MI))
		size += printf_fill(min);
	if (!(data->param & PARAM_L))
		size += ft_put_long_sub(data, nbr);
	else if (data->param & PARAM_L)
	{
		if (data->param & PARAM_PL)
			size += printf_putchar('+');
		else if (data->param & PARAM_WH && *(long *)nbr >= 0)
			size += printf_putchar(' ');
		if (data->param & PARAM_D || data->param & PARAM_I)
			size += ft_putlong(*(long *)nbr, 0);
		else if (data->param & PARAM_U)
			size += ft_putlong(*(unsigned long *)nbr, 0);
	}
	if (data->param & PARAM_MI)
		size += printf_fill(min);
	return (size);
}

int		ft_put_long_sub(t_param *data, void *nbr)
{
	int		size;

	size = 0;
	if (data->param & PARAM_PL)
		size += printf_putchar('+');
	else if (data->param & PARAM_WH && *(int *)nbr >= 0)
		size += printf_putchar(' ');
	if (data->param & PARAM_D || data->param & PARAM_I)
		size += ft_putlong(*(int *)nbr, 0);
	else if (data->param & PARAM_U)
		size += ft_putlong(*(unsigned int *)nbr, 0);
	return (size);
}
