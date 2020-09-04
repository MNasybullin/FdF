/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:18:52 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:35:32 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "mem_lst.h"
# include "mlx.h"
# include "errors.h"
# define WIDTH	1500
# define HEIGHT	1000
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef	struct		s_view
{
	double			alpha;
	double			beta;
	double			gamma;
	int				zoom;
	int				x_move;
	int				y_move;
	float			z_move;
	int				projection;

}					t_view;

typedef	struct		s_map
{
	int				width;
	int				height;
	int				*coord;
	int				*color;
	char			back_color;
	int				z_min;
	int				z_max;
	int				def_color;
}					t_map;

typedef	struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*img_data;
	void			*img;
	int				bpp;
	int				stride;
	int				endian;
	int				help;
	int				lb;
	int				rb;
	int				x2;
	int				y2;
	int				x1;
	int				y1;
	int				x3;
	int				y3;
	int				x4;
	int				y4;
	t_view			*view;
	t_map			*map;
}					t_win;

typedef	struct		s_coord
{
	int				z;
	int				color;
	struct s_coord	*next;
}					t_coord;

typedef	struct		s_xyz
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_xyz;

char				**ft_strsplit(char const *s, char c);
void				set_m(void);
void				new_m(void *pointer);
void				del_m(void);
void				del_memory(void);
void				*mem(size_t size);
t_map				*map_create(void);
t_win				*win_create(t_map *map);
int					read_map(int fd, t_map *map, t_coord **coord);
void				free_strsplit(char **read_line);
void				print_err(char *s);
void				move_to_array(t_coord **coord, t_map *map);
t_coord				*next(t_coord **coord);
void				draw(t_win *win, t_map *map);
void				line(t_xyz f, t_xyz s, t_win *win);
void				put_pixel(int x, int y, t_win *win, int color);
t_xyz				xyz(int x, int y, t_map *map);
t_view				*view_create(t_map *map);
t_xyz				view(t_xyz point, t_win *win, t_map *map);
void				iso(int *x, int *y, int z);
void				put_pixel_last(t_xyz f, t_xyz s, t_win *win);
void				x_rotation(int *y, int *z, double alpha);
void				y_rotation(int *x, int *z, double beta);
void				z_rotation(int *x, int *y, double gamma);
int					deal_key(int key, void *param);
void				zoom(int key, t_win *win);
void				move_img(int key, t_win *win);
void				back(t_win *win);
void				rotate(int key, t_win *win);
void				change_pro(int key, t_win *win);
void				z_change(int key, t_win *win);
int					mouse_press(int key, int x, int y, void *param);
void				menu(t_win *win);
void				change_back(int key, t_win *win);
void				help_menu(int key, t_win *win);
void				last_pixel(int x, int y, t_win *win, t_map *map);
int					standart_color(int z, t_map *map);
double				percent(int start, int end, int current);
int					get_color(t_xyz cur, t_xyz start, t_xyz end, t_xyz delta);
int					ft_isdigit_base(char c, int base);
int					ft_atoi_base(char *str, int base);
void				change_def_color(int key, t_win *win);
int					mouse_move(int x, int y, void *param);
void				right_button(int x, int y, t_win *win);
void				left_button(int x, int y, t_win *win);
void				menu1(t_win *win);
void				put_pixel_last2(t_xyz f, t_xyz s, t_win *win);

#endif
