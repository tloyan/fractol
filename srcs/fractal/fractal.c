/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:23:16 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:38:50 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal(t_complex c, t_env *env)
{
	static int	(*funcs[])(t_complex, t_env) = {
		mandelbrot, julia, burningship};

	return (funcs[env->fractal_type](c, *env));
}