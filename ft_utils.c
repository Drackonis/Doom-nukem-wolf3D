/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:14:05 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 11:55:13 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_checkwall(t_data *data)
{
	data->img.disttowall += 0.01f;
	data->img.testX = (int)(data->player.xPos +
		data->player.eyeX * data->img.disttowall);
	data->img.testY = (int)(data->player.yPos +
		data->player.eyeY * data->img.disttowall);
	if (data->tab[data->img.testY][data->img.testX] == 1)
	{
		data->img.hitwall = 1;
		while (data->tab[data->img.testY][data->img.testX] == 1)
		{
			data->img.disttowall -= 0.00005f;
			data->img.testX = (int)(data->player.xPos +
				data->player.eyeX * data->img.disttowall);
			data->img.testY = (int)(data->player.yPos +
				data->player.eyeY * data->img.disttowall);
		}
	}
	else if (data->img.testX < 0 || data->img.testX >= data->nbcol ||
			data->img.testY < 0 || data->img.testY >= data->nblin)
	{
		data->img.hitwall = 1;
		data->img.disttowall = data->depth;
	}
}

void			ft_setpixelcolor(t_data *data, int i, int r)
{
	if (i > data->floor - 1)
	{
		data->img.data[r + 2] = FLOOR_R;
		data->img.data[r + 1] = FLOOR_G;
		data->img.data[r] = FLOOR_B;
	}
	else if (i > data->ceiling + 2 && i < data->floor)
	{
		ft_gettexturecolor(data, i);
		data->img.data[r + 2] = data->img.r;
		data->img.data[r + 1] = data->img.g;
		data->img.data[r] = data->img.b;
	}
	else
	{
		data->img.data[r + 2] = SKY_R;
		data->img.data[r + 1] = SKY_G;
		data->img.data[r] = SKY_B;
	}
}

void			ft_putline(t_data *data)
{
	int			i;
	int			r;

	i = 0;
	data->ceiling = (float)(data->winheight / 2) - data->winheight
		/ (float)data->img.disttowall;
	data->floor = data->winheight - data->ceiling;
	while (i < data->winheight - 1)
	{
		r = ((data->winwidth - data->img.linePos) *
				(data->img.bpp / 8)) + (i * data->img.size_line);
		ft_setpixelcolor(data, i, r);
		i++;
	}
}

void			malloc_error(void)
{
	write(1, "Malloc Error !\n", 15);
}
