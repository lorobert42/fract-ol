/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:58 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:32:35 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "fractol.h"

int	quit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->img->addr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	free(vars->img);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 65307)
		quit(vars);
	return (0);
}

int	scroll_hook(int keycode, int x, int y, t_vars *vars)
{
	float	mousex;
	float	mousey;
	float	zoom;

	if (keycode == 4 || keycode == 5)
	{
		mousex = (float)x / (WIDTH / (vars->frac->xmax - vars->frac->xmin)) + vars->frac->xmin;
		mousey = (float)y / (HEIGHT / (vars->frac->ymax - vars->frac->ymin)) * -vars->frac->ymax;
		if (keycode == 4)
			zoom = 0.8;
		else
			zoom = 1.2;
		vars->frac->xmin = mousex + ((vars->frac->xmin - mousex) * (1.0 / zoom));
		vars->frac->ymin = mousey + ((vars->frac->ymin - mousey) * (1.0 / zoom));
		vars->frac->xmax = mousex + ((vars->frac->xmax - mousex) * (1.0 / zoom));
		vars->frac->ymax = mousey + ((vars->frac->ymax - mousey) * (1.0 / zoom));
	}
	compute_fractal(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
		vars->img->addr, 0, 0);
	return (0);
}

void	hook(t_vars *vars)
{
	mlx_key_hook(vars->win_ptr, key_hook, vars);
	mlx_hook(vars->win_ptr, 17, 0, quit, vars);
	mlx_mouse_hook(vars->win_ptr, scroll_hook, vars);
}

t_fractal	*init_fractal(void)
{
	t_fractal	*frac;

	frac = malloc(sizeof(t_fractal));
	if (!frac)
		return (NULL);
	frac->xmin = -2.0;
	frac->xmax = 2.0;
	frac->ymin = -2.0;
	frac->ymax = frac->ymin + (frac->xmax - frac->xmin) * HEIGHT / WIDTH;
	frac->xfactor = (frac->xmax - frac->xmin) / (WIDTH - 1);
	frac->yfactor = (frac->ymax - frac->ymin) / (HEIGHT - 1);
	return (frac);
}

int	main(void)
{
	t_vars		vars;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	vars.img = malloc(sizeof(t_img));
	vars.img->addr = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	vars.img->buffer = mlx_get_data_addr(vars.img->addr, \
			&vars.img->pixel_bits, &vars.img->line_bytes, \
			&vars.img->endian);
	vars.frac = init_fractal();
	compute_fractal(&vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, \
			vars.img->addr, 0, 0);
	hook(&vars);
	mlx_loop(vars.mlx_ptr);
}
