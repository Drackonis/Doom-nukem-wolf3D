/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:47:21 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/30 13:43:14 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void ft_setscreen(t_data *data)
{
	data->winheight = 1080;
	data->winwidth = 1920;
}

void ft_initwin(t_data *data)
{
	data->proj = 0;
}

int		ft_initmlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	ft_setscreen(data);
	ft_initwin(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->winwidth,\
			data->winheight, "WOLF3D");
	mlx_key_hook(data->win_ptr, ft_getkey, data);
	mlx_expose_hook(data->win_ptr, ft_display, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
