/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:08:06 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/29 16:40:28 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_keymove(int kc, t_data *data)
{
	if (kc == DOWN)
		data->pos.iy += data->space;
	else if (kc == UP)
		data->pos.iy -= data->space;
	else if (kc == RIGHT)
		data->pos.ix += data->space;
	else if (kc == LEFT)
		data->pos.ix -= data->space;
}

void	ft_keycolor(int kc, t_data *data)
{
	if (kc == R)
		data->color.r -= 20;
	else if (kc == G)
		data->color.g -= 20;
	else if (kc == B)
		data->color.b -= 20;
	else if (kc == C)
		data->color.color++;
	if (data->color.color > COLOR_MAX)
		data->color.color = 0;
}

void	ft_switchproj(t_data *data)
{
	if (data->proj == PROJ_MAX)
		data->proj = 0;
	else
		data->proj++;
}

void	ft_keyzoom(int kc, t_data *data)
{
	if (kc == LESS)
	{
		data->space -= 5;
		if (data->space <= 4)
			data->space = 5;
	}
	else if (kc == MORE)
		data->space += 5;
	else if (kc == DIV)
	{
		data->heightcoef--;
	}
	else if (kc == MUL)
		data->heightcoef++;
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
