/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:20:04 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/23 16:13:10 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	main_error(int error)
{
	if (error == 0)
		ft_putendl("Main structure allocation failed\n");
	else if (error == 1)
		ft_putendl("Usage : ./wolf3d \"map\"");
	if (error == 0 || error == 1)
		exit(-1);
	//TEMPORAIRE
	exit(-1);
}

int		main(int ac, char **av)
{
	t_wolf		*wolf;

	(void)av;
	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		main_error(0);
	if (ac != 2)
		main_error(1);
	return (0);
}
