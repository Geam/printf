/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:39:32 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:13:59 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

int		ft_putbase(unsigned long n, int size, unsigned long base)
{
	if (n >= base)
		size = ft_putbase(n / base, size, base);
	if (n % base < 10)
		size += printf_putchar((n % base) + '0');
	else if (n % base >= 10)
		size += printf_putchar((n % base) - 10 + 'a');
	return (size);
}

int		ft_put_base(t_param *data, void *nbr)
{
	int		size;
	int		min;

	size = 0;
	min = printf_fill_nbrlen(data, nbr);
	if (!(data->param & PARAM_MI))
		size += printf_fill(min);
	if (data->param & PARAM_O)
		size += ft_putbase(*(unsigned int *)nbr, 0, 8);
	else if (data->param & PARAM_X)
		size += ft_putbase(*(unsigned int *)nbr, 0, 16);
	if (data->param & PARAM_MI)
		size += printf_fill(min);
	return (size);
}
