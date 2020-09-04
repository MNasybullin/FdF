/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:19:04 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:16:01 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_win	*win;
	t_coord	*coord;

	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			print_err(OPEN);
		map = map_create();
		if (read_map(fd, map, &coord) == -1)
			print_err(READ);
		win = win_create(map);
		move_to_array(&coord, map);
		win->view = view_create(map);
		draw(win, win->map);
		mlx_hook(win->win_ptr, 2, 0, deal_key, win);
		mlx_hook(win->win_ptr, 4, 0, mouse_press, win);
		mlx_hook(win->win_ptr, 6, 0, mouse_move, win);
		mlx_loop(win->mlx_ptr);
	}
	print_err(USE);
	return (0);
}
