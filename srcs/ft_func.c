/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:00:08 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 14:12:40 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_core.h"

static int	f(int i, t_param *d, va_list *ap, int (*t_o[12])(t_param *, void *))
{
	long	test;

	if (d->param & PARAM_STA)
	{
		test = (int)va_arg(*ap, long);
		if (test < 0)
		{
			d->param = d->param | PARAM_MI;
			test *= -1;
		}
		d->nb = test;
	}
	test = va_arg(*ap, long);
	return (t_o[i](d, &test));
}

int			printf_func(int i, t_param *data, va_list *ap)
{
	int		(*t_op[12])(t_param *, void *);
	char	*str;

	t_op[0] = &ft_put_long;
	t_op[1] = &ft_put_long;
	t_op[5] = &ft_put_char;
	t_op[6] = &ft_put_long;
	t_op[7] = &ft_put_base;
	t_op[8] = &ft_put_base;
	t_op[9] = &ft_put_point;
	t_op[10] = &ft_put_base;
	t_op[11] = &ft_put_str;
	if (i < 11)
		return (f(i, data, ap, t_op));
	else if (i == 11)
	{
		str = va_arg(*ap, char *);
		return (t_op[i](data, str));
	}
	else if (i == 12)
		return (printf_putchar('%'));
	return (-1);
}
