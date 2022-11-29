/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:01:33 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/25 15:15:05 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_fractal(t_vars *vars)
{
	int		pixel;
	t_point	p;
	t_color	color;

	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			color = get_color(mandelbrot(p, vars));
			pixel = ((int)p.y * vars->img->line_bytes) + ((int)p.x * 4);
			set_color(color, pixel, vars);
			p.x++;
		}
		p.y++;
	}
}