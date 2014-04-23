/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:47:03 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:13:50 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

int		ft_put_char(t_param *data, void *c)
{
	int		size;

	(void)data;
	size = 1;
	write(1, (char *)c, 1);
	return (size);
}

int		ft_put_str(t_param *data, void *s)
{
	int		size;
	int		len;

	size = 0;
	len = printf_fill_strlen(data, s);
	if (!(data->param & PARAM_MI))
		size += printf_fill(len);
	if (data->param & PARAM_DOT)
	{
		write(1, (char *)s, data->nb);
		size += data->nb;
	}
	else
		size += printf_putstr((char *)s);
	if (data->param & PARAM_MI)
		size += printf_fill(len);
	return (size);
}
