/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:36:23 by lorobert          #+#    #+#             */
/*   Updated: 2022/11/09 12:37:41 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef struct s_img {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img;

typedef struct s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_img	*prev;
	t_img	*next;
}	t_vars;

// Fractal types
int		mandelbrot(t_point p);
int		julia(t_point p);

// Colors
int		get_color(int color, t_vars vars);
void	set_color(int color, int pixel, t_img *img);

#endif
