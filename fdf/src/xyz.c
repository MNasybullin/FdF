/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:28:12 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:31:18 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_xyz	xyz(int x, int y, t_map *map)
{
	t_xyz	point;
	int		i;

	i = y * map->width + x;
	point.x = x;
	point.y = y;
	point.z = map->coord[i];
	point.color = (map->color[i] == -1) ?
		standart_color(point.z, map) : map->color[i];
	return (point);
}

void	last_pixel(int x, int y, t_win *win, t_map *map)
{
	--x;
	--y;
	put_pixel_last(view(xyz(x, y, map), win, map),
			view(xyz(x, y, map), win, map), win);
}
