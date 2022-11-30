/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:01:33 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/30 17:01:58 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_fractal(t_vars *vars)
{
	int		pixel;
	int		x;
	int		y;
	t_point	p;
	t_color	color;

	y = 0;
	while (y < HEIGHT)
	{
		p.y = vars->frac->ymax - y * vars->frac->yfactor;
		x = 0;
		while (x < WIDTH)
		{
			p.x = vars->frac->xmin + x * vars->frac->xfactor;
			color = get_color(mandelbrot(p));
			pixel = (y * vars->img->line_bytes) + (x * 4);
			set_color(color, pixel, vars);
			x++;
		}
		y++;
	}
}