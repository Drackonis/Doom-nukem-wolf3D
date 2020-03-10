/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:02:26 by rkergast          #+#    #+#             */
/*   Updated: 2020/03/10 13:09:29 by rkergast         ###   ########.fr       */
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
# define W_WIDTH 1280
# define W_HEIGHT 720

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define LSTRAF 12
# define RSTRAF 14

# define SPACE 49
# define ENTER 36
# define ESC 53

# define RPX 37
# define RMX 38
# define RPY 34
# define RMY 40

# define FLOOR_R 50
# define FLOOR_G 50
# define FLOOR_B 50
# define SKY_R 70
# define SKY_G 70
# define SKY_B 120

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
	float				rayangle;
	float				disttowall;
	int					linePos;
	int					hitwall;
	int					testX;
	int					testY;
	int					r;
	int					g;
	int					b;
}						t_img;

typedef struct			s_player
{
	float				xPos;
	float				yPos;
	float				lastXPos;
	float				lastYPos;
	float				angle;
	float				fov;
	float				eyeX;
	float				eyeY;
	float				tx;
	float				ty;
	float				bmx;
	float				bmy;
}						t_player;

typedef	struct			s_tex
{
	void				*tex;
	char				*textab;
	int					block_side;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					widthTex;
	int					heighTex;
	int					r;
	int					g;
	int					b;
	float				sampleX;
	float				sampleY;
}						t_tex;

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
	int					depth;
	struct s_player		player;
	struct s_lines		*begin;
	struct s_pt			pt;
	struct s_pos		pos;
	struct s_color		color;
	struct s_img		img;
	struct s_tex		tex1;
	struct s_tex		tex2;
	struct s_tex		tex3;
	struct s_tex		tex4;
	int					ceiling;
	int					floor;
	int					heightcoef;
	int					ret;
	int					idx;
	int					start;
	int					linlen;
	int					bound;
	int					lastSide;
}						t_data;

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
void					ft_keymove(int kc, t_data *data);
void					ft_checkcolide(t_data *data);

void					ft_initwin(t_data *data);
void					ft_setwin(t_data *data);
void					ft_setscreen(t_data *data);
void					ft_setzoom(t_data *data);

int						ft_initmlx(t_data *data);

void					ft_mallocerror(int **tab);
void					malloc_error(void);
void					read_fail(void);
void					invalid_map(t_data *data);
void					open_fail(void);
void					fd_empty(void);

void					ft_playerdata(t_data *data);
void					ft_drawlines(t_data *data);
void					ft_checkwall(t_data *data);
void					ft_putline(t_data *data);
void					ft_gettexturecolor(t_data *data, int heigh);

#endif
