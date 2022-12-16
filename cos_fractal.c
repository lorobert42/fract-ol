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

void	init_cos(t_vars *vars)
{
	double		ratio;

	vars->type = cos_fractal;
	ratio = (double)HEIGHT / (double)WIDTH;
	vars->min.x = -2.0;
	vars->max.x = 2.0;
	vars->min.y = -2.0 * ratio;
	vars->max.y = 2.0 * ratio;
	vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
	vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
}

int	cos_fractal(t_point p, t_vars *vars)
{
	t_point	z;
	t_point	c;
	double	tmp;
	int		i;

	z.x = p.x;
	z.y = p.y;
	c.x = p.x / (p.x * p.x + p.y * p.y);
	c.y = p.y / (p.x * p.x + p.y * p.y);
	i = 0;
	while (z.x * z.x + z.y * z.y <= 10 * M_PI && i < vars->max_iterations)
	{
		tmp = cos(z.x) * cosh(z.y) + c.x;
		z.y = -(sin(z.x) * sinh(z.y)) - c.y;
		z.x = tmp;
		i++;
	}
	return (i);
}
