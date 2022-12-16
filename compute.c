/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:01:33 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/16 09:37:29 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

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
		p.y = vars->max.y - y * vars->factor.y;
		x = 0;
		while (x < WIDTH)
		{
			p.x = vars->min.x + x * vars->factor.x;
			color = get_color(vars->type(p, vars), vars);
			pixel = (y * vars->img->line_bytes) + (x * 4);
			set_color(color, pixel, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
			vars->img->addr, 0, 0);
}
