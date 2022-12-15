/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:01:33 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/08 11:07:58 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "fractol.h"

void	*compute_fractal(void *thread)
{
	int		pixel;
	int		x;
	int		y;
	t_point	p;
	t_color	color;
	t_vars	*vars;

	vars = ((t_thread *)thread)->vars;
	y = ((t_thread *)thread)->id * (HEIGHT / THREADS);
	while (y < ((t_thread *)thread)->id * (HEIGHT / THREADS) + (HEIGHT / THREADS))
	{
		p.y = vars->max.y - y * vars->factor.y;
		x = 0;
		while (x < WIDTH)
		{
			p.x = vars->min.x + x * vars->factor.x;
			color = get_color(vars->type(p, vars));
			pixel = (y * vars->img->line_bytes) + (x * 4);
			set_color(color, pixel, vars);
			x++;
		}
		y++;
	}
	return (NULL);
}
