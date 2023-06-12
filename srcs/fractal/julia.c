/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:29:27 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 13:07:41 by thloyan          ###   ########.fr       */
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

int	julia(t_complex z, t_env *env)
{
	// t_complex	c;
	int			iteration;

	// c.re = -0.7;
	// c.im = 0.27015;

	// c.re = -0.123;
	// c.im = 0.745;
	iteration = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < MAX_ITER)
	{
		z = add(square(z), env->c);
		iteration++;
	}
	return (iteration);
}