/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:05:18 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/29 16:19:07 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_line(const int fd, char **line, char **tab)
{
	int		i;

	i = 0;
	while (tab[fd][i] != '\n' && tab[fd][i] != '\0')
		i++;
	if (i == (int)ft_strlen(tab[fd]))
	{
		*line = ft_strdup(tab[fd]);
		ft_strclr(tab[fd]);
	}
	else
	{
		*line = ft_strsub(tab[fd], 0, i);
		tab[fd] = ft_strnclr(tab[fd], i + 1);
	}
}

int		end_of_fd(int ret, char **tab, const int fd)
{
	if (!tab[fd] || (ret < BUFF_SIZE && !ft_strlen(tab[fd])))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tab[256];
	char			*buf;
	int				ret;
	int				i;

	ret = 0;
	i = 0;
	if (fd < 0 || !line || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tab[fd] = ft_strfreejoin(tab[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (buf)
		ft_strdel(&buf);
	if (end_of_fd(ret, tab, fd) == 0)
		return (0);
	get_line(fd, line, tab);
	return (1);
}
