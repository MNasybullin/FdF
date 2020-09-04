/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:36:32 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 12:45:52 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		standart_color(int z, t_map *map)
{
	double percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (map->def_color == 0)
	{
		if (percentage < 0.2)
			return (0x0101DF);
		else if (percentage < 0.4)
			return (0x651f9a);
		else if (percentage < 0.6)
			return (0x9a1f88);
		else if (percentage < 0.8)
			return (0xEF8633);
		else
			return (0xF3AF3D);
	}
	else
	{
		if (percentage < 0.4)
			return (0x000000);
		else if (percentage < 0.6)
			return (0x9a1f88);
		else
			return (0xF3AF3D);
	}
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_xyz cur, t_xyz start, t_xyz end, t_xyz delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light((start.color) & 0xFF, (end.color) & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
