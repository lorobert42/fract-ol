/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:48 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/05 11:17:48 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fractol.h"

void	init_burning_ship(t_vars *vars)
{
	double		ratio;

	vars->type = burning_ship;
	ratio = (double)HEIGHT / (double)WIDTH;
	vars->min.x = -2.5;
	vars->max.x = 1.5;
	vars->min.y = -1.5 * ratio;
	vars->max.y = 2.5 * ratio;
	vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
	vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
}

int	burning_ship(t_point p, t_vars *vars)
{
	t_point	z;
	double	tmp;
	int		i;

	z.x = p.x;
	z.y = p.y;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < vars->max_iterations)
	{
		tmp = z.x * z.x - z.y * z.y + p.x;
		z.y = -2.0 * fabs(z.x * z.y) + p.y;
		z.x = tmp;
		i++;
	}
	return (i);
}
