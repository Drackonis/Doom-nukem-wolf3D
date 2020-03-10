/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:38:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 11:22:19 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

struct s_tex	ft_getside(t_data *data,
		struct s_tex tex, float angletest, int heigh)
{
	if (angletest >= -3.14159f * 0.25f && angletest < 3.14159f * 0.25f)
	{
		tex.sampleX = (float)data->img.testY - data->player.ty;
		tex.block_side = 0;
	}
	else if (angletest >= 3.14159f * 0.25f && angletest < 3.14159f * 0.75f)
	{
		tex.sampleX = data->player.tx - (float)data->img.testX;
		tex.block_side = 1;
	}
	else if (angletest < -3.14159f * 0.25f && angletest >= -3.14159f * 0.75f)
	{
		tex.sampleX = (float)data->img.testX - data->player.tx;
		tex.block_side = 2;
	}
	else if (angletest >= -3.14159f * 0.75f || angletest < -3.14159f * 0.75f)
	{
		tex.sampleX = data->player.ty - (float)data->img.testY;
		tex.block_side = 3;
	}
	tex.sampleY = ((float)heigh - (float)data->ceiling) /
		((float)data->floor - (float)data->ceiling);
	return (tex);
}

void			ft_getcolor(t_data *data, struct s_tex tex)
{
	int			sx;
	int			sy;

	sx = tex.sampleX * tex.widthTex;
	sy = tex.sampleY * tex.heighTex;
	data->img.r = tex.textab[(int)(sy * tex.size_line) + (int)(sx * 4) + 2];
	data->img.g = tex.textab[(int)(sy * tex.size_line) + (int)(sx * 4) + 1];
	data->img.b = tex.textab[(int)(sy * tex.size_line) + (int)(sx * 4)];
	if (data->img.disttowall > data->depth)
	{
		data->img.r = SKY_R;
		data->img.g = SKY_G;
		data->img.b = SKY_B;
	}
	if (data->bound == 1 || data->lastSide != tex.block_side)
	{
		data->img.r = 0;
		data->img.g = 0;
		data->img.b = 0;
		data->lastSide = tex.block_side;
	}
}

void			ft_setplayervalue(t_data *data)
{
	data->player.bmx = (float)data->img.testX + 0.5f;
	data->player.bmy = (float)data->img.testY + 0.5f;
	data->player.tx = data->player.xPos + data->player.eyeX
		* data->img.disttowall;
	data->player.ty = data->player.yPos + data->player.eyeY
		* data->img.disttowall;
}

void			ft_gettexturecolor(t_data *data, int heigh)
{
	float		angletest;

	ft_setplayervalue(data);
	angletest = atan2f((data->player.ty - data->player.bmy),
			(data->player.tx - data->player.bmx));
	if (angletest >= -3.14159f * 0.25f && angletest < 3.14159f * 0.25f)
	{
		data->tex1 = ft_getside(data, data->tex1, angletest, heigh);
		ft_getcolor(data, data->tex1);
	}
	else if (angletest >= 3.14159f * 0.25f && angletest < 3.14159f * 0.75f)
	{
		data->tex2 = ft_getside(data, data->tex2, angletest, heigh);
		ft_getcolor(data, data->tex2);
	}
	else if (angletest < -3.14159f * 0.25f && angletest >= -3.14159f * 0.75f)
	{
		data->tex3 = ft_getside(data, data->tex3, angletest, heigh);
		ft_getcolor(data, data->tex3);
	}
	else if (angletest >= -3.14159f * 0.75f || angletest < -3.14159f * 0.75f)
	{
		data->tex4 = ft_getside(data, data->tex4, angletest, heigh);
		ft_getcolor(data, data->tex4);
	}
}

void			ft_drawlines(t_data *data)
{
	data->img.linePos = 0;
	data->img.hitwall = 0;
	while (data->img.linePos < data->winwidth)
	{
		data->img.rayangle = (data->player.angle - data->player.fov / 2.0f) +
			((float)data->img.linePos / (float)data->winwidth)
			* data->player.fov;
		data->player.eyeX = sin(data->img.rayangle);
		data->player.eyeY = cos(data->img.rayangle);
		data->img.disttowall = 0.01f;
		data->img.hitwall = 0;
		while (data->img.hitwall == 0 && data->img.disttowall < data->depth)
		{
			ft_checkwall(data);
		}
		ft_putline(data);
		data->img.linePos++;
	}
}
