/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:19:10 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:08:08 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_win *win)
{
	if (key == 24 || key == 69 || key == 4)
		win->view->zoom++;
	if (key == 27 || key == 78 || key == 5)
		win->view->zoom--;
	if (win->view->zoom < 1)
		win->view->zoom = 1;
	draw(win, win->map);
}

void	move_img(int key, t_win *win)
{
	if (key == 123)
		win->view->x_move += 10;
	if (key == 124)
		win->view->x_move -= 10;
	if (key == 126)
		win->view->y_move += 10;
	if (key == 125)
		win->view->y_move -= 10;
	draw(win, win->map);
}

void	rotate(int key, t_win *win)
{
	if (key == 91)
		win->view->alpha -= 0.025;
	if (key == 87)
		win->view->alpha += 0.025;
	if (key == 86)
		win->view->beta -= 0.025;
	if (key == 88)
		win->view->beta += 0.025;
	if (key == 89)
		win->view->gamma -= 0.025;
	if (key == 92)
		win->view->gamma += 0.025;
	draw(win, win->map);
}

void	change_pro(int key, t_win *win)
{
	win->view->alpha = 0;
	win->view->beta = 0;
	win->view->gamma = 0;
	win->view->x_move = 0;
	win->view->y_move = 0;
	win->view->z_move = 1;
	win->view->zoom = FT_MIN(WIDTH / win->map->width / 2,
			HEIGHT / win->map->height / 2);
	if (key == 34)
		win->view->projection = 1;
	if (key == 35)
		win->view->projection = 0;
	draw(win, win->map);
}

int		deal_key(int key, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (key == 24 || key == 69 || key == 27 || key == 78)
		zoom(key, win);
	if (key == 123 || key == 124 || key == 126 || key == 125)
		move_img(key, win);
	if (key == 86 || key == 87 || key == 88 ||
			key == 91 || key == 89 || key == 92)
		rotate(key, win);
	if (key == 34 || key == 35)
		change_pro(key, win);
	if (key == 0 || key == 6)
		z_change(key, win);
	if (key == 53)
		exit(0);
	if (key == 11 || key == 45 || key == 9)
		change_back(key, win);
	if (key == 122)
		help_menu(key, win);
	if (key == 8)
		change_def_color(key, win);
	return (0);
}
