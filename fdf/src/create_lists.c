/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:52:24 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 12:50:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"

t_map	*map_create(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		print_err(MAP_CR);
	}
	map->height = 0;
	map->width = 0;
	map->color = NULL;
	map->coord = NULL;
	map->back_color = (char)0x000000;
	map->z_max = 0;
	map->z_min = 0;
	map->def_color = 0;
	return (map);
}

t_win	*win_create(t_map *map)
{
	t_win	*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		print_err(WIN_CR);
	if (!(win->mlx_ptr = mlx_init()))
		print_err(WIN_CR);
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "FdF")))
		print_err(WIN_CR);
	if (!(win->img = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT)))
		print_err(WIN_CR);
	if (!(win->img_data = mlx_get_data_addr(win->img, &win->bpp,
					&win->stride, &win->endian)))
		print_err(WIN_CR);
	win->help = 0;
	win->lb = 0;
	win->rb = 0;
	win->x2 = 0;
	win->y2 = 0;
	win->x1 = 0;
	win->y1 = 0;
	win->map = map;
	return (win);
}

t_view	*view_create(t_map *map)
{
	t_view	*view;

	if (!(view = (t_view *)ft_memalloc(sizeof(t_view))))
		print_err(VIEW_CR);
	view->zoom = FT_MIN(WIDTH / map->width / 2, HEIGHT / map->height / 2);
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	view->x_move = 0;
	view->y_move = 0;
	view->z_move = 1;
	view->projection = 0;
	return (view);
}
