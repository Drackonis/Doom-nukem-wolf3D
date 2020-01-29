/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:20:04 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/29 17:47:55 by rkergast         ###   ########.fr       */
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

void	printmap(t_data *data)
{
	int i = 0;
	int j = 0;

	while(i < data->nblin)
	{
		printf("line %d |", i);
		j = 0;
		while(j < data->nbcol)
		{
			printf("%d ", data->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	t_wolf		*wolf;
	t_lines		begin;
	t_data		data;

	(void)av;
	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		main_error(0);
	else if (ac != 2)
		main_error(1);
	else
	{
		begin.index = 0;
		begin = read_arg(av, begin, &data);
		data.begin = &begin;
		data.tab = ft_settab(&begin, &data);
		if (!data.tab)
		{
			write(1, "Invalide Map !\n", 15);
			return (0);
		}
		printmap(&data);
		//ft_initmlx(&data);
	}

	return (0);
}
