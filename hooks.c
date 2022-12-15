/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:45:59 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/15 14:03:14 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "keys.h"
#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
		quit(vars);
	if (keycode == K_LEFT || keycode == K_DOWN || keycode == K_RIGHT \
		|| keycode == K_UP)
		move_fractal(keycode, vars);
	if (keycode == K_L)
	{
		vars->color_set = (vars->color_set + 1) % 3;
		compute_fractal(vars);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
			vars->img->addr, 0, 0);
	}
	return (0);
}

int	scroll_hook(int keycode, int x, int y, t_vars *vars)
{
	t_point	mouse;
	double	zoom;

	if (keycode == 4 || keycode == 5)
	{
		mouse.x = (double)x / (WIDTH / (vars->max.x - vars->min.x)) \
			+ vars->min.x;
		mouse.y = (double)y / (HEIGHT / (vars->max.y - vars->min.y)) \
			* -1 + vars->max.y;
		if (keycode == 4)
			zoom = 1.2;
		else
			zoom = 0.8;
		vars->min.x = mouse.x + ((vars->min.x - mouse.x) * (1.0 / zoom));
		vars->min.y = mouse.y + ((vars->min.y - mouse.y) * (1.0 / zoom));
		vars->max.x = mouse.x + ((vars->max.x - mouse.x) * (1.0 / zoom));
		vars->max.y = mouse.y + ((vars->max.y - mouse.y) * (1.0 / zoom));
		vars->factor.x = (vars->max.x - vars->min.x) / (WIDTH - 1);
		vars->factor.y = (vars->max.y - vars->min.y) / (HEIGHT - 1);
		compute_fractal(vars);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
			vars->img->addr, 0, 0);
	}
	return (0);
}

void	hook(t_vars *vars)
{
	mlx_key_hook(vars->win_ptr, key_hook, vars);
	mlx_hook(vars->win_ptr, 17, 0, quit, vars);
	mlx_mouse_hook(vars->win_ptr, scroll_hook, vars);
}
