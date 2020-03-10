/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:20:04 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 11:06:21 by rkergast         ###   ########.fr       */
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
	exit(-1);
}

void	ft_gettexture(t_data *data)
{
	data->tex1.tex = mlx_xpm_file_to_image(&data->mlx_ptr,
				"./Texture01.xpm", &data->tex1.widthTex, &data->tex1.heighTex);
	data->tex1.textab = mlx_get_data_addr(data->tex1.tex,
				&data->tex1.bits_per_pixel, &data->tex1.size_line,
				&data->tex1.endian);
	data->tex2.tex = mlx_xpm_file_to_image(&data->mlx_ptr,
				"./Texture02.xpm", &data->tex2.widthTex, &data->tex2.heighTex);
	data->tex2.textab = mlx_get_data_addr(data->tex2.tex,
				&data->tex2.bits_per_pixel, &data->tex2.size_line,
				&data->tex2.endian);
	data->tex3.tex = mlx_xpm_file_to_image(&data->mlx_ptr,
				"./Texture03.xpm", &data->tex3.widthTex, &data->tex3.heighTex);
	data->tex3.textab = mlx_get_data_addr(data->tex3.tex,
				&data->tex3.bits_per_pixel, &data->tex3.size_line,
				&data->tex3.endian);
	data->tex4.tex = mlx_xpm_file_to_image(&data->mlx_ptr,
				"./Texture04.xpm", &data->tex4.widthTex, &data->tex4.heighTex);
	data->tex4.textab = mlx_get_data_addr(data->tex4.tex,
				&data->tex4.bits_per_pixel, &data->tex4.size_line,
				&data->tex4.endian);
}

int		main(int ac, char **av)
{
	t_lines		begin;
	t_data		data;

	if (ac != 2)
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
		ft_playerdata(&data);
		ft_gettexture(&data);
		ft_initmlx(&data);
	}
	return (0);
}
/*
**void	printmap(t_data *data)
**{
**	int i;
**	int j;
**
**	i = 0;
**	j = 0;
**	printf("Coll >> | 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n");
**	printf("          - - - - - - - - - - - - - - - - - - - - -\n");
**	while(i < data->nblin)
**	{
**		printf("line ");
**		if (i < 10)
**			printf("0");
**		printf("%d | ", i);
**		j = 0;
**		while(j < data->nbcol)
**		{
**			printf("%d ", data->tab[i][j]);
**			j++;
**		}
**		printf("\n");
**		i++;
**	}
**	printf("nblin : %d | nbcol : %d\n", data->nblin, data->nbcol);
**	printf("xPos : %f | yPos %f\n", data->player.xPos, data->player.yPos);
**}
*/
