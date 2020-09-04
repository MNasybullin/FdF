/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:37:33 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:24:32 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_strsplit(char **read_line)
{
	int	i;

	i = 0;
	while (read_line[i])
	{
		free(read_line[i++]);
	}
	free(read_line);
}

t_coord	*z_coord(char *read_line)
{
	char	**str;
	t_coord	*tmp;

	if (!(tmp = (t_coord *)ft_memalloc(sizeof(t_coord))))
		print_err(MAP_READ);
	if (!(str = ft_strsplit(read_line, ',')))
		print_err(MAP_READ);
	tmp->z = ft_getnbr(str[0]);
	tmp->color = str[1] ? ft_atoi_base(str[1], 16) : -1;
	tmp->next = NULL;
	free_strsplit(str);
	return (tmp);
}

void	move(t_coord **coord, t_coord *tmp)
{
	if (coord)
	{
		if (tmp)
		{
			tmp->next = *coord;
		}
		*coord = tmp;
	}
}

void	get_coord(char **read_line, t_coord **coord, t_map *map)
{
	int	width;

	width = 0;
	while (*read_line)
	{
		move(coord, z_coord(*(read_line++)));
		width++;
	}
	if (map->width == 0)
		map->width = width;
	else if (map->width != width)
		print_err(MAP_NOT_COR);
}

int		read_map(int fd, t_map *map, t_coord **coord)
{
	char	*line;
	int		read;
	char	**read_line;

	while ((read = get_next_line(fd, &line)) == 1)
	{
		if (!(read_line = ft_strsplit(line, ' ')))
			print_err(MAP_READ);
		get_coord(read_line, coord, map);
		map->height++;
		free_strsplit(read_line);
		ft_strdel(&line);
	}
	if (!(*coord))
		print_err(MAP_READ);
	return (read);
}
