/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:40:33 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:34:12 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_left(t_env *env)
{
	double	amount_move;

	amount_move = (env->x_max - env->x_min) * 0.1;
	env->x_min = env->x_min - amount_move;
	env->x_max = env->x_max - amount_move;
	draw_fractal(env);
}

void	move_right(t_env *env)
{
	double	amount_move;

	amount_move = (env->x_max - env->x_min) * 0.1;
	env->x_min = env->x_min + amount_move;
	env->x_max = env->x_max + amount_move;
	draw_fractal(env);
}

void	move_down(t_env *env)
{
	double	amount_move;

	amount_move = (env->y_max - env->y_min) * 0.1;
	env->y_min = env->y_min + amount_move;
	env->y_max = env->y_max + amount_move;
	draw_fractal(env);
}

void	move_up(t_env *env)
{
	double	amount_move;

	amount_move = (env->y_max - env->y_min) * 0.1;
	env->y_min = env->y_min - amount_move;
	env->y_max = env->y_max - amount_move;
	draw_fractal(env);
}
