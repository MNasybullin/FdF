/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:01:22 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:40:51 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	left_button(int x, int y, t_win *win)
{
	win->x2 = win->x1;
	win->y2 = win->y1;
	win->x1 = x;
	win->y1 = y;
	if (x > win->x2)
		win->view->beta += 0.025;
	if (y > win->y2)
		win->view->alpha += 0.025;
	if (x < win->x2)
		win->view->beta -= 0.025;
	if (y < win->y2)
		win->view->alpha -= 0.025;
}

void	right_button(int x, int y, t_win *win)
{
	win->x4 = win->x3;
	win->y4 = win->y3;
	win->x3 = x;
	win->y3 = y;
	if (x > win->x4)
		win->view->x_move += 10;
	if (y > win->y4)
		win->view->y_move += 10;
	if (x < win->x4)
		win->view->x_move -= 10;
	if (y < win->y4)
		win->view->y_move -= 10;
}

int		mouse_move(int x, int y, void *param)
{
	t_win	*win;

	win = (t_win*)param;
	if (win->lb == 1)
		left_button(x, y, win);
	if (win->rb == 1)
		right_button(x, y, win);
	draw(win, win->map);
	return (0);
}
