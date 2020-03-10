/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:05:18 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 11:30:00 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_lines				*set_link(int idx, char *line)
{
	t_lines			*new;

	if (!(new = (t_lines*)malloc(sizeof(t_lines))))
		malloc_error();
	new->index = idx;
	new->line = ft_strdup(line);
	return (new);
}

void				set_value(t_data *data)
{
	data->ret = 0;
	data->idx = 0;
	data->start = 0;
	data->linlen = 0;
}

void				next_free(t_data *data, char *line)
{
	data->idx++;
	data->start++;
	free(line);
	line = NULL;
}

t_lines				set_chain(int fd, t_lines begin, t_data *data)
{
	char			*line;
	t_lines			*current;

	set_value(data);
	while ((data->ret = get_next_line(fd, &line)) == 1)
	{
		(line == NULL || *line == '\0') ? invalid_map() : 0;
		if (data->start == 0)
		{
			begin.index = data->idx;
			begin.line = ft_strdup(line);
			data->linlen = ft_strlen(line);
			current = &begin;
		}
		else
		{
			current->next = set_link(data->idx, line);
			current = current->next;
		}
		next_free(data, line);
	}
	((data->ret <= 0 && data->linlen <= 0) ? invalid_map() : 0);
	data->nblin = data->idx;
	current->next = NULL;
	return (begin);
}

t_lines				read_arg(char **argv, t_lines begin, t_data *data)
{
	int				fd;
	int				ret;

	fd = 0;
	ret = 0;
	if (argv[1])
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		open_fail();
	begin = set_chain(fd, begin, data);
	if (begin.line == NULL)
		fd_empty();
	if (argv[1])
		close(fd);
	return (begin);
}
