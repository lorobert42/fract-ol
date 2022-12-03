/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:27:40 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:27:42 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	init_julia(double x, double y, t_vars *vars)
{
	double		ratio;

	vars->type = compute_julia;
	ratio = (double)HEIGHT / (double)WIDTH;
	vars->min.x = -2.0;
	vars->max.x = 2.0;
	vars->min.y = -2.0 * ratio;
	vars->max.y = 2.0 * ratio;
	vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
	vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
	vars->offset.x = x;
	vars->offset.y = y;
}

void	compute_julia(t_vars *vars)
{
	int		pixel;
	int		x;
	int		y;
	t_point	p;
	t_color	color;

	y = 0;
	while (y < HEIGHT)
	{
		p.y = vars->max.y - y * vars->factor.y;
		x = 0;
		while (x < WIDTH)
		{
			p.x = vars->min.x + x * vars->factor.x;
			color = get_color(julia(p, vars));
			pixel = (y * vars->img->line_bytes) + (x * 4);
			set_color(color, pixel, vars);
			x++;
		}
		y++;
	}
}

int	julia(t_point p, t_vars *vars)
{
	t_point	z;
	double	tmp;
	int		i;

	z.x = p.x;
	z.y = p.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < MAX_ITERATIONS)
	{
		tmp = z.x * z.x - z.y * z.y + vars->offset.x;
		z.y = 2.0 * z.x * z.y + vars->offset.y;
		z.x = tmp;
		i++;
	}
	return (i);
}
