/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:05:52 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 16:06:07 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnclr(char *s, int i)
{
	char	*new;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	new = ft_strnew(ft_strlen(s) - i);
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	ft_strdel(&s);
	return (new);
}
