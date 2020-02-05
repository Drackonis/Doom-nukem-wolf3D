/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:08:06 by rkergast          #+#    #+#             */
/*   Updated: 2020/02/05 15:54:16 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_keymove(int kc, t_data *data)
{
	if (kc == UP)
	{
		data->player.xPos += sin(data->player.angle) * 0.2f;
		data->player.yPos += cos(data->player.angle) * 0.2f;
	}
	else if (kc == DOWN)
	{
		data->player.xPos -= sin(data->player.angle) * 0.2f;
		data->player.yPos -= cos(data->player.angle) * 0.2f;
	}
	else if (kc == RIGHT)
		data->player.angle -= 0.05;
	else if (kc == LEFT)
		data->player.angle += 0.05;
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
