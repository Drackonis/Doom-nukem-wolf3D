/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:38:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/30 14:58:38 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_checkwall(t_data *data)
{
	data->img.disttowall += 0.1f;
	data->img.testX = (int)(data->player.xPos +
		data->player.eyeX * data->img.disttowall);
	data->img.testY = (int)(data->player.yPos +
		data->player.eyeY * data->img.disttowall);

}

void		ft_drawlines(t_data *data)
{
	data->img.linePos = 0;
	data->img.hitwall = 0;
	while (data->img.linePos < W_WIDTH)
	{
		data->img.rayangle = (data->player.angle - data->player.fov / 2.0f) +
			((float)data->img.linePos / (float)W_WIDTH) * data->player.fov;
		data->player.eyeX = sin(data->img.rayangle);
		data->player.eyeY = cos(data->img.rayangle);
		data->img.disttowall = 0;
		while(data->img.hitwall == 0)
		{
			ft_checkwall(data);
		}
		data->img.linePos++;
	}
}

void		ft_drawimg(t_data *data)
{
	ft_drawlines(data);
}
