/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:44:40 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 12:13:11 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_setstartpos(t_data *data)
{
	int i;
	int t;
	int j;

	i = 0;
	t = 0;
	while (i < data->nblin && t == 0)
	{
		j = 0;
		while (j < data->nbcol && t == 0)
		{
			if (data->tab[i][j] == 0 && data->tab[i - 1][j] == 0 &&
					data->tab[i + 1][j] == 0 && data->tab[i][j - 1] == 0 &&
					data->tab[i][j + 1] == 0)
			{
				data->player.yPos = (float)i;
				data->player.xPos = (float)j;
				t++;
			}
			j++;
		}
		i++;
	}
}

void		ft_playerdata(t_data *data)
{
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	data->depth = 16;
	data->player.fov = 3.14159 / 4;
	data->player.angle = 1;
	while (i < data->nblin && t == 0)
	{
		j = 0;
		while (j < data->nbcol && t == 0)
		{
			if (data->tab[i][j] == 2)
			{
				data->player.yPos = (float)i;
				data->player.xPos = (float)j;
				t++;
			}
			j++;
		}
		i++;
	}
	(t == 0 ? ft_setstartpos(data) : t++);
}
