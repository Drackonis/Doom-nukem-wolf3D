/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:15:56 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 11:27:18 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			isnb(char c)
{
	if (c == '-' || c == '+' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int			count_number(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		if (isnb(line[i]))
		{
			count++;
			i++;
		}
		else
			return (-1);
	}
	return (count);
}

int			atoi_modif(char *c)
{
	int i;

	i = c[0] - '0';
	return (i);
}

int			*fill_line(t_lines *line)
{
	int		i;
	int		j;
	int		*tab;
	char	*current;

	i = 0;
	j = 0;
	if (count_number(line->line) == -1 || !(tab = (int*)malloc(sizeof(int)
					* (count_number(line->line) + 1))))
		return (NULL);
	current = line->line;
	while (*current)
	{
		if (*current == ' ')
			current++;
		else if (isnb(*current))
		{
			tab[j] = atoi_modif(current);
			j++;
			current++;
		}
	}
	tab[j] = 0;
	return (tab);
}

int			**ft_settab(t_lines *begin, t_data *data)
{
	int		**tab;
	t_lines	*current;
	int		i;

	i = 0;
	current = begin;
	if (!(tab = (int**)malloc(sizeof(int*) * (data->nblin + 1))))
		ft_mallocerror(tab);
	while (current)
	{
		if (fill_line(current) == NULL)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = fill_line(current);
		current = current->next;
		i++;
	}
	data->nbcol = count_number(begin->line);
	tab[i] = NULL;
	return (tab);
}
