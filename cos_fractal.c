/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:12 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/05 11:27:12 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fractol.h"

void	init_cos(double x, double y, t_vars *vars)
{
	double		ratio;

	vars->type = compute_cos;
	ratio = (double)HEIGHT / (double)WIDTH;
	vars->min.x = -2.5;
	vars->max.x = 1.5;
	vars->min.y = -2.0 * ratio;
	vars->max.y = 2.0 * ratio;
	vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
	vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
	vars->offset.x = x;
	vars->offset.y = y;
}

void	compute_cos(t_vars *vars)
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
			color = get_color(cos_fractal(p));
			pixel = (y * vars->img->line_bytes) + (x * 4);
			set_color(color, pixel, vars);
			x++;
		}
		y++;
	}
}

int	cos_fractal(t_point p)
{
	t_point	z;
	double	tmp;
	int		i;

	z.x = p.x;
	z.y = p.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 10 * M_PI && i < MAX_ITERATIONS)
	{
		tmp = cos(z.x) * cosh(z.y) + (p.x / (p.x * p.x + p.y * p.y));
		z.y = -(sin(z.x) * sinh(z.y)) - (p.y / (p.x * p.x + p.y * p.y));
		z.x = tmp;
		i++;
	}
	return (i);
}
