/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 19:52:55 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 13:56:17 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		printf_func(int i, t_param *data, va_list *ap);
int		printf_putchar(char c);
int		printf_putstr(char *str);
int		printf_two_pow(int nb);
int		printf_strlen(char *str);
int		printf_fill(int nb);
int		ft_printf(char *str, ...);
int		ft_put_char(t_param *data, void *c);
int		ft_put_str(t_param *data, void *s);
int		ft_putbase(unsigned long n, int size, unsigned long base);
int		ft_put_base(t_param *data, void *nbr);
int		ft_putlong(long n, int size);
int		ft_put_long(t_param *data, void *nbr);
int		ft_put_long_sub(t_param *data, void *nbr);
int		ft_put_point(t_param *data, void *nbr);
int		printf_fill_nbrlen(t_param *data, void *data_2);
int		printf_fill_strlen(t_param *data, void *data_2);
int		ft_nbrlen_long(long n, int size);
int		ft_nbrlen_ulong(unsigned long n, int size);
int		which_param(char *str, t_param *data, int *shift, va_list *ap);

#endif
