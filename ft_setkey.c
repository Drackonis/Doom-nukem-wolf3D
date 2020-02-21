/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:08:06 by rkergast          #+#    #+#             */
/*   Updated: 2020/02/21 15:20:06 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_checkcolide(t_data *data)
{
	/*int x;
	int y;
	if (data->player.xPos % 1.0f >= 0.5f)
		x = (int)data->player.xPos + 1;
	else
		x = (int)data->player.xPos;
	if (data->player.yPos % 1.0f >= 0.5f)
		y = (int)data->player.yPos + 1;
	else
		y = (int)data->player.yPos;*/

	printf("%d | %f | %f\n",(int)data->player.xPos ,data->player.xPos, data->player.xPos - (int)data->player.xPos);
	//printf("X : %d | Y : %d\n", (int)data->player.xPos, (int)data->player.yPos);
	//printf("float : %f | int : %d\n", data->player.xPos, (int)data->player.xPos);
	if (data->tab[(int)data->player.xPos][(int)data->player.yPos] == 1)
	{
		data->player.xPos = data->player.lastXPos;
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
	else if (kc == DOWN)
	{
		data->player.xPos -= sin(data->player.angle) * 0.2f;
		data->player.yPos -= cos(data->player.angle) * 0.2f;
	}
	else if (kc == RIGHT)
		data->player.angle -= 0.05;
	else if (kc == LEFT)
		data->player.angle += 0.05;
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
