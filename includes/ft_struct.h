/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 12:41:31 by mdelage           #+#    #+#             */
/*   Updated: 2014/04/23 13:58:51 by mdelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# define PARAM_D	1
# define PARAM_I	2
# define PARAM_F	4
# define PARAM_E	8
# define PARAM_G	16
# define PARAM_C	32
# define PARAM_U	64
# define PARAM_O	128
# define PARAM_X	256
# define PARAM_P	512
# define PARAM_XM	1024
# define PARAM_S	2048
# define PARAM_PO	4096
# define PARAM_H	8192
# define PARAM_L	16384
# define PARAM_MI	32768
# define PARAM_PL	65536
# define PARAM_0	131072
# define PARAM_WH	262144
# define PARAM_DOT	524288
# define PARAM_DI	1048576
# define PARAM_STA	2097152

typedef struct s_param	t_param;

struct		s_param
{
	int		param;
	int		nb;
	int		nb2;
};

#endif
