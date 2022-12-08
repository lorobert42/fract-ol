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

	vars->type = julia;
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
