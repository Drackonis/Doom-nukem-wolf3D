/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/01/29 16:47:46 by rkergast         ###   ########.fr       */
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

# define BUFF_SIZE 1
# define PROJ_MAX 1
# define COLOR_MAX 1

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define R 15
# define G 5
# define B 11
# define C 8

# define SPACE 49
# define ENTER 36
# define ESC 53
# define DIV 75
# define MUL 67

# define MORE 69
# define LESS 78
# define RPX 37
# define RMX 38
# define RPY 34
# define RMY 40

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					endian;
	int					sl;
	int					bpp;
}						t_mlx;

typedef struct			s_env
{
	int					screen_height;
	int					screen_width;
}						t_env;

typedef struct			s_editor
{
	int					menu;
}						t_editor;

typedef struct			s_lines
{
	int					index;
	char				*line;
	struct s_lines		*next;
}						t_lines;

typedef struct			s_pt
{
	int					x;
	int					y;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					dx;
	int					dy;
	int					sy;
	int					err;
}						t_pt;

typedef struct			s_pos
{
	int					ix;
	int					iy;
	float				rx;
	float				ry;
}						t_pos;

typedef struct			s_color
{
	int					color;
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef	struct			s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					winwidth;
	int					winheight;
	int					space;
	int					nblin;
	int					nbcol;
	int					**tab;
	int					proj;
	int					kc;
	struct s_lines		*begin;
	struct s_pt			pt;
	struct s_pos		pos;
	struct s_color		color;
	struct s_img		img;
	int					heightcoef;
	int					ret;
	int					idx;
	int					start;
	int					linlen;
}						t_data;

typedef struct			s_wolf
{
	t_env				env;
	t_mlx				mlx;
	t_editor			editor;
	int					fd;
}						t_wolf;

t_lines					read_arg(char **argv, t_lines begin, t_data *data);
t_lines					set_chain(int fd, t_lines begin, t_data *data);
t_lines					*set_link(int idx, char *line);
int						get_next_line(const int fd, char **line);

int						**ft_settab(t_lines *begin, t_data *data);
int						*fill_line(t_lines *line);
int						count_number(char *line);
int						isnb(char c);

int						ft_display(t_data *data);
int						ft_getkey(int kc, t_data *data);

void					ft_keypad(int kc, t_data *data);
void					ft_keyzoom(int kc, t_data *data);
void					ft_switchproj(t_data *data);
void					ft_keycolor(int lc, t_data *data);
void					ft_keymove(int kc, t_data *data);

void					ft_initwin(t_data *data);
void					ft_setwin(t_data *data);
void					ft_setscreen(t_data *data);
void					ft_setzoom(t_data *data);

int						ft_initmlx(t_data *data);

void					malloc_error(void);
void					read_fail(void);
void					invalid_map(void);
void					open_fail(void);
void					fd_empty(void);

#endif
