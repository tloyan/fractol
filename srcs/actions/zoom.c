/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:20:54 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:34:21 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_env *env)
{
	double	zoom_factor;
	double	x_percent;
	double	y_percent;
	double	new_width;
	double	new_height;

	zoom_factor = 1.5;
	x_percent = (double)x / WIDTH;
	y_percent = (double)y / HEIGHT;
	new_width = (env->x_max - env->x_min) / zoom_factor;
	new_height = (env->y_max - env->y_min) / zoom_factor;
	env->x_min = env->x_min + x_percent * (env->x_max - env->x_min - new_width);
	env->x_max = env->x_min + new_width;
	env->y_min = env->y_min + y_percent * (
			env->y_max - env->y_min - new_height);
	env->y_max = env->y_min + new_height;
	draw_fractal(env);
}

void	zoom_out(int x, int y, t_env *env)
{
	double	zoom_factor;
	double	x_percent;
	double	y_percent;
	double	new_width;
	double	new_height;

	zoom_factor = 0.75;
	x_percent = (double)x / WIDTH;
	y_percent = (double)y / HEIGHT;
	new_width = (env->x_max - env->x_min) / zoom_factor;
	new_height = (env->y_max - env->y_min) / zoom_factor;
	env->x_min = env->x_min + x_percent * (env->x_max - env->x_min - new_width);
	env->x_max = env->x_min + new_width;
	env->y_min = env->y_min + y_percent * (
			env->y_max - env->y_min - new_height);
	env->y_max = env->y_min + new_height;
	draw_fractal(env);
}
