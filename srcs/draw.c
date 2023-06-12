/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:10:34 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:33:16 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pixel_to_complex(int x, int y, t_env *env)
{
	t_complex	c;

	c.re = (double)x / WIDTH * (env->x_max - env->x_min) + env->x_min;
	c.im = (double)y / HEIGHT * (env->y_max - env->y_min) + env->y_min;
	return (c);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// printf("x %d, y %d, color %d\n", x, y, color);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	draw_fractal(t_env *env)
// {
// 	t_complex	c;
// 	int			x;
// 	int			y;
// 	int			iteration;

// 	img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			c = pixel_to_complex(x, y, env);
// 			iteration = mandelbrot(c);
// 			my_mlx_pixel_put(&env->img, x, y, choose_color(iteration, env));
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
// }

void	draw_fractal(t_env *env)
{
	t_complex	c;
	t_data		img;
	int			x;
	int			y;
	int			iteration;

	img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = pixel_to_complex(x, y, env);
			iteration = fractal(c, env);
			my_mlx_pixel_put(&img, x, y, choose_color(iteration, env));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	mlx_destroy_image(env->mlx, img.img);
}
