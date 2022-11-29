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

# define MAX_ITERATIONS 50
# define WIDTH 800
# define HEIGHT 600

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef struct s_fractal {
	float	width;
	float	height;
	float	xmax;
	float	ymax;
	float	xmin;
	float	ymin;
	float	zoom;
	t_point	start;
}	t_fractal;

typedef struct s_img {
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img;

typedef struct s_vars {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_img		*prev;
	t_img		*next;
	t_fractal	*frac;
}	t_vars;

typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

void	compute_fractal(t_vars *vars);

// Fractal types
int		mandelbrot(t_point p, t_vars *vars);
int		julia(t_point p);

// Colors
t_color	get_color(int color);
void	set_color(t_color color, int pixel, t_vars *vars);

#endif
