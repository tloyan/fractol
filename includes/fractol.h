/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:22:50 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:51:51 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 1000

typedef enum e_color_schemes {
	PATERN0,
	PATERN1,
	PATERN2,
	PATERN3,
	PATERN4,
	PATERN5,
}	t_color_schemes;

typedef enum e_fractal_type {
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}	t_fractal_type;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_env
{
	void				*mlx;
	void				*win;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	t_data				img;
	t_complex			c;
	t_fractal_type		fractal_type;
	t_color_schemes		color_scheme;
}				t_env;

void	draw_fractal(t_env *env);
int		choose_color(int iter, t_env *env);
void	switch_color(t_env *env);

int		fractal(t_complex c, t_env *env);
int		mandelbrot(t_complex c, t_env *env);
int		julia(t_complex c, t_env *env);
int		burningship(t_complex c, t_env *env);

int		mouse_handler(int mousecode, int x, int y, t_env *env);
int		key_handler(int keycode, t_env *env);
void	zoom_in(int x, int y, t_env *env);
void	zoom_out(int x, int y, t_env *env);
void	move_left(t_env *env);
void	move_right(t_env *env);
void	move_down(t_env *env);
void	move_up(t_env *env);

double	ft_atof(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

#endif