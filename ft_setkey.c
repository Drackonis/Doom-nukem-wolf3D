/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:08:06 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 10:56:30 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_checkcolide(t_data *data)
{
	if (data->tab[(int)data->player.lastYPos][(int)data->player.xPos] == 1)
	{
		data->player.xPos = data->player.lastXPos;
	}
	if (data->tab[(int)data->player.yPos][(int)data->player.lastXPos] == 1)
	{
		data->player.yPos = data->player.lastYPos;
	}
}

void	ft_keymove(int kc, t_data *data)
{
	data->player.lastXPos = data->player.xPos;
	data->player.lastYPos = data->player.yPos;
	if (kc == UP)
	{
		data->player.xPos += sin(data->player.angle) * 0.2f;
		data->player.yPos += cos(data->player.angle) * 0.2f;
	}
	if (kc == DOWN)
	{
		data->player.xPos -= sin(data->player.angle) * 0.2f;
		data->player.yPos -= cos(data->player.angle) * 0.2f;
	}
	if (kc == RIGHT || kc == LEFT)
		data->player.angle += (kc == RIGHT ? -0.08f : 0.08f);
	if (kc == RSTRAF)
	{
		data->player.yPos += sin(data->player.angle) * 0.2f;
		data->player.xPos -= cos(data->player.angle) * 0.2f;
	}
	if (kc == LSTRAF)
	{
		data->player.yPos -= sin(data->player.angle) * 0.2f;
		data->player.xPos += cos(data->player.angle) * 0.2f;
	}
	ft_checkcolide(data);
}

void	ft_keypad(int kc, t_data *data)
{
	int i;

	i = 0;
	if (kc == RPX)
	{
		data->pos.rx += (data->pos.rx < 1) ? 0.1 : 0;
		if (data->pos.rx < 1)
			while (i++ < 2)
				ft_keymove(LEFT, data);
	}
	else if (kc == RMX)
	{
		data->pos.rx -= (data->pos.rx > -1) ? 0.1 : 0;
		if (data->pos.rx > -1)
			while (i++ < 2)
				ft_keymove(RIGHT, data);
	}
	else if (kc == RPY)
	{
		data->pos.ry += (data->pos.ry < 1) ? 0.1 : 0;
	}
	else if (kc == RMY)
	{
		data->pos.ry -= (data->pos.ry > -1) ? 0.1 : 0;
	}
}
