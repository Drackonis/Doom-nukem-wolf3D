/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:44:40 by rkergast          #+#    #+#             */
/*   Updated: 2020/02/05 15:02:44 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
}
