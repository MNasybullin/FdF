/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:19:04 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:19:24 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coord	*next(t_coord **coord)
{
	t_coord	*next;

	next = NULL;
	if (coord && *coord)
	{
		next = *coord;
		*coord = (*coord)->next;
	}
	return (next);
}

void	move_to_array(t_coord **coord, t_map *map)
{
	t_coord	*tmp;
	ssize_t	i;
	size_t	size_int;

	size_int = map->width * map->height * sizeof(int);
	if (!(map->coord = (int *)ft_memalloc(size_int)))
		print_err(MOVE_ERR);
	if (!(map->color = (int *)ft_memalloc(size_int)))
		print_err(MOVE_ERR);
	i = map->width * map->height - 1;
	while ((tmp = next(coord)) && i >= 0)
	{
		map->coord[i] = tmp->z;
		map->color[i] = tmp->color;
		if (tmp->z > map->z_max)
			map->z_max = tmp->z;
		if (tmp->z < map->z_min)
			map->z_min = tmp->z;
		i--;
		free(tmp);
	}
}
