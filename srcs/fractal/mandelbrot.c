/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:48:47 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:38:29 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	magnitude(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}

static t_complex	square(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2.0 * z.re * z.im;
	return (result);
}

static t_complex	add(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = z.re + c.re;
	result.im = z.im + c.im;
	return (result);
}

int	mandelbrot(t_complex c, t_env *env)
{
	t_complex	z;
	int			iteration;

	(void)env;
	z.re = 0;
	z.im = 0;
	iteration = 0;
	while (magnitude(z) <= 2.0 && iteration < MAX_ITER)
	{
		z = add(square(z), c);
		iteration++;
	}
	return (iteration);
}