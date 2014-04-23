/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:19:30 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:15:36 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

int		printf_fill_nbrlen(t_param *data, void *data_2)
{
	int		len;
	int		min;

	len = 0;
	if (data->param & PARAM_DOT)
		min = data->nb2;
	else
		min = data->nb;
	if (data->param & PARAM_D || data->param & PARAM_I)
		len = ft_nbrlen_long(*(int *)data_2, 0);
	else if (data->param & PARAM_U)
		len = ft_nbrlen_long(*(unsigned int *)data_2, 0);
	else if (data->param & PARAM_L &&
			(data->param & PARAM_D || data->param & PARAM_I))
		len = ft_nbrlen_long(*(long *)data_2, 0);
	else if (data->param & PARAM_O || data->param & PARAM_X ||
			data->param & PARAM_P)
		len = ft_nbrlen_ulong(*(unsigned long *)data_2, 0);
	if ((data->param & PARAM_WH || data->param & PARAM_PL) &&
		*(long *)data_2 >= 0 && data->param & PARAM_L)
		len++;
	else if ((data->param & PARAM_WH || data->param & PARAM_PL) &&
			*(int *)data_2 >= 0 && !(data->param & PARAM_L))
		len++;
	return (min - len);
}

int		printf_fill_strlen(t_param *data, void *data_2)
{
	int		len;
	int		min;

	if (data->param & PARAM_DOT)
	{
		len = data->nb;
		min = data->nb2;
	}
	else
	{
		len = printf_strlen((char *)data_2);
		min = data->nb;
	}
	return (min - len);
}

int		ft_nbrlen_long(long n, int size)
{
	if (n < 0)
	{
		n *= -1;
		size += 1;
	}
	if (n >= 10)
		size = ft_nbrlen_long(n / 10, size);
	return (size + 1);
}

int		ft_nbrlen_ulong(unsigned long n, int size)
{
	if (n >= 10)
		size = ft_nbrlen_ulong(n / 10, size);
	return (size + 1);
}
