/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:31 by sdiego            #+#    #+#             */
/*   Updated: 2019/10/28 13:29:35 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "math.h"

void	x_rotation(int *y, int *z, double alpha)
{
	int	last_y;

	last_y = *y;
	*y = last_y * cos(alpha) + *z * sin(alpha);
	*z = -last_y * sin(alpha) + *z * cos(alpha);
}

void	y_rotation(int *x, int *z, double beta)
{
	int	last_x;

	last_x = *x;
	*x = last_x * cos(beta) + *z * sin(beta);
	*z = -last_x * sin(beta) + *z * cos(beta);
}

void	z_rotation(int *x, int *y, double gamma)
{
	int	last_x;
	int	last_y;

	last_x = *x;
	last_y = *y;
	*x = last_x * cos(gamma) - last_y * sin(gamma);
	*y = -last_x * sin(gamma) + last_y * cos(gamma);
}

void	iso(int *x, int *y, int z)
{
	int	last_x;
	int	last_y;

	last_x = *x;
	last_y = *y;
	*x = (last_x - last_y) * cos(0.523599);
	*y = (last_x + last_y) * sin(0.523599) - z;
}

t_xyz	view(t_xyz point, t_win *win, t_map *map)
{
	point.x *= win->view->zoom;
	point.y *= win->view->zoom;
	point.z *= win->view->zoom + win->view->z_move;
	point.x -= (map->width * win->view->zoom) / 2;
	point.y -= (map->height * win->view->zoom) / 2;
	x_rotation(&point.y, &point.z, win->view->alpha);
	y_rotation(&point.x, &point.z, win->view->beta);
	z_rotation(&point.x, &point.y, win->view->gamma);
	if (win->view->projection == 1)
		iso(&point.x, &point.y, point.z);
	point.x += WIDTH / 2 + win->view->x_move;
	point.y += HEIGHT / 2 + win->view->y_move;
	return (point);
}
