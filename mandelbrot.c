/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:55:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 11:55:51 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	init_mandelbrot(t_vars *vars)
{
	double		ratio;

	vars->type = mandelbrot;
	ratio = (double)HEIGHT / (double)WIDTH;
	vars->min.x = -2.5;
	vars->max.x = 1.5;
	vars->min.y = -2.0 * ratio;
	vars->max.y = 2.0 * ratio;
	vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
	vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
}

int	mandelbrot(t_point p, t_vars *vars)
{
	t_point	z;
	t_point	z2;
	int		i;

	z.x = 0;
	z.y = 0;
	z2.x = 0;
	z2.y = 0;
	i = 0;
	while (z2.x + z2.y <= 4 && i < vars->max_iterations)
	{
		z.y = 2 * z.x * z.y + p.y;
		z.x = z2.x - z2.y + p.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	return (i);
}
