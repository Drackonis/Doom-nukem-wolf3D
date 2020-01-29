/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:05:40 by rkergast          #+#    #+#             */
/*   Updated: 2019/09/02 16:05:46 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreejoin(char *s1, char *s2)
{
	char *new;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}
