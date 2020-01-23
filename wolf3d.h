/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/23 16:01:15 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "pthread.h"
# include <stdlib.h>
# include <fcntl.h>
# include <wchar.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			endian;
	int			sl;
	int			bpp;
}				t_mlx;

typedef struct	s_env
{
	int			screen_height;
	int			screen_width;
}				t_env;

typedef struct	s_editor
{
	int			menu;
}				t_editor;

typedef struct	s_wolf
{
	t_env		env;
	t_mlx		mlx;
	t_editor	editor;
	int			fd;
}				t_wolf;

#endif
