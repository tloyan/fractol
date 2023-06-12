/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:50:20 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:48 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef int	(*t_color_func)(int);

int	dynamic_color(int iter)
{
	int	red;
	int	green;
	int	blue;

	red = 0xFF * (0.5 + 0.5 * sin(iter / 10.0));
	green = 0xFF * (0.5 + 0.5 * sin(iter / 20.0 + M_PI / 2));
	blue = 0xFF * (0.5 + 0.5 * sin(iter / 30.0 + M_PI));
	return ((red << 16) | (green << 8) | blue);
}

int	green_to_blue_color(int iter)
{
	int	red;
	int	green;
	int	blue;

	if (iter < MAX_ITER / 2)
	{
		red = 0xFF * (1.0 - 2.0 * iter / MAX_ITER);
		green = 0xFF * (2.0 * iter / MAX_ITER);
		return ((red << 16) | (green << 8));
	}
	green = 0xFF * (1.0 - 2.0 * (iter - MAX_ITER / 2) / MAX_ITER);
	blue = 0xFF * (2.0 * (iter - MAX_ITER / 2) / MAX_ITER);
	return ((green << 8) | blue);
}

int	test_color(int iter)
{
	int red = (iter * 2 % 256);
    int green = (iter * 2 % 256);
    int blue = (iter * 2 % 256);

    return ((red << 16) | (green << 8) | blue);
}

int rainbow_color(int iter)
{
    int red = fabs(sin(iter) * 256);
    int green = fabs(sin(iter + 2) * 256);
    int blue = fabs(sin(iter + 4) * 256);

    return ((red << 16) | (green << 8) | blue);
}

int pastel_color(int iter)
{
    int red = fabs(sin(iter) * 127 + 128);
    int green = fabs(sin(iter + 2) * 127 + 128);
    int blue = fabs(sin(iter + 4) * 127 + 128);

    return ((red << 16) | (green << 8) | blue);
}

int gradient_bw_color(int iter)
{
    int color = iter % 256;

    return ((color << 16) | (color << 8) | color);
}

// int smooth_color(int iter)
// {
// 	int red = sin(0.2 * iter) * 230 + 25;
// 	int green = sin(0.3 * iter) * 230 + 25;
// 	int blue = sin(0.1 * iter) * 230 + 25;

// 	return ((red << 16) | (green << 8) | blue);
// }

int smooth_color(int iter)
{
	int red = sin(0.3 * iter) * 230 + 25;
	int green = sin(0.2 * iter) * 230 + 25;
	int blue = sin(0.1 * iter) * 230 + 25;

	return ((red << 16) | (green << 8) | blue);
}

int zebra_color(int iter)
{
	int color = (iter % 2) * 255;

	return ((color << 16) | (color << 8) | color);
}

int psychedelic_color(int iter)
{
	int red = cos(iter) * 256;
	int green = cos(iter + 2) * 256;
	int blue = cos(iter + 4) * 256;

	return ((red << 16) | (green << 8) | blue);
}

int	choose_color(int iter, t_env *env)
{
	static int	(*color_funcs[])(int) = {
		dynamic_color, green_to_blue_color, test_color,
		rainbow_color, pastel_color, gradient_bw_color,
		smooth_color, zebra_color, psychedelic_color};

	return (color_funcs[env->color_scheme](iter));
}

void	switch_color(t_env *env)
{
	printf("env->color_scheme %d\n", env->color_scheme);
	if (env->color_scheme < 6)
		env->color_scheme++;
	else
		env->color_scheme = 0;
	draw_fractal(env);
}