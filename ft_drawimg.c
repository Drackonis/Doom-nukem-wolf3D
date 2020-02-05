/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:38:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/02/05 15:55:50 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_checkwall(t_data *data)
{
	data->img.disttowall += 0.01f;
	data->img.testX = (int)(data->player.xPos +
		data->player.eyeX * data->img.disttowall);
	data->img.testY = (int)(data->player.yPos +
		data->player.eyeY * data->img.disttowall);

	if (data->img.testX < 0 || data->img.testX >= data->nbcol ||
			data->img.testY < 0 || data->img.testY >= data->nblin)
	{
		data->img.hitwall = 1;
		data->img.disttowall = data->depth;
	}
	else
	{
		if (data->tab[data->img.testY][data->img.testX] == 1)
		{
			data->img.hitwall = 1;
		}
	}
}

void		ft_putline(t_data *data)
{
	int i;
	int r;

	i = 0;
	data->ceiling = (float)(data->winheight / 2) - data->winheight
		/ (float)data->img.disttowall;
	data->floor = data->winheight - data->ceiling;
	r = data->img.disttowall * 20 < 255 ? 255 - (data->img.disttowall * 20) : 0;
	while (i < data->winheight)
	{
		if (i > data->ceiling && i < data->floor)
		{
			data->img.data[((data->winwidth - data->img.linePos)
				* (data->img.bpp / 8)) + (i * data->img.size_line)] = r;
			data->img.data[((data->winwidth - data->img.linePos)
				* (data->img.bpp / 8)) + (i * data->img.size_line) + 1] = r;
			data->img.data[((data->winwidth - data->img.linePos)
				* (data->img.bpp / 8)) + (i * data->img.size_line) + 2] = r;
		}
		i++;
	}
}

void		ft_drawlines(t_data *data)
{
	data->img.linePos = 0;
	data->img.hitwall = 0;
	while (data->img.linePos < data->winwidth)
	{
		data->img.rayangle = (data->player.angle - data->player.fov / 2.0f) +
			((float)data->img.linePos / (float)data->winwidth) * data->player.fov;
		data->player.eyeX = sin(data->img.rayangle);
		data->player.eyeY = cos(data->img.rayangle);
		data->img.disttowall = 0;
		data->img.hitwall = 0;
		while (data->img.hitwall == 0 && data->img.disttowall < data->depth)
		{
			ft_checkwall(data);
		}
		ft_putline(data);
		data->img.linePos++;
	}
}

void		ft_drawimg(t_data *data)
{
	ft_drawlines(data);
}
