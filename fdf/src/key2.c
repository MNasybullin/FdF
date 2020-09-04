/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:28:38 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:12:10 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	z_change(int key, t_win *win)
{
	if (key == 6)
		win->view->z_move -= 1;
	if (key == 0)
		win->view->z_move += 1;
	draw(win, win->map);
}

void	change_back(int key, t_win *win)
{
	if (key == 11)
		win->map->back_color = (char)0x000000;
	if (key == 45)
		win->map->back_color = (char)0x2E2E2E;
	if (key == 9)
		win->map->back_color = (char)0xFFFFFF;
	draw(win, win->map);
}

void	help_menu(int key, t_win *win)
{
	if (key == 122)
	{
		if (win->help == 0)
			win->help = 1;
		else
			win->help = 0;
	}
	draw(win, win->map);
}

void	change_def_color(int key, t_win *win)
{
	if (key == 8)
	{
		if (win->map->def_color == 0)
			win->map->def_color = 1;
		else
			win->map->def_color = 0;
	}
	draw(win, win->map);
}

int		mouse_press(int key, int x, int y, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	x = 0;
	y = 0;
	if (key == 4 || key == 5)
		zoom(key, win);
	if (key == 1)
	{
		if (win->lb == 0)
			win->lb = 1;
		else
			win->lb = 0;
	}
	if (key == 2)
	{
		if (win->rb == 0)
			win->rb = 1;
		else
			win->rb = 0;
	}
	return (0);
}
