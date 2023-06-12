/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:01:29 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:38:25 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex new_complex(double re, double im)
{
    t_complex c;

    c.re = re;
    c.im = im;

    return (c);
}

int	burningship(t_complex c, t_env *env)
{
	t_complex	z;
	int			iteration;

    z = new_complex(0, 0);
    iteration = 0;
    while (z.re * z.re + z.im * z.im <= 4 && iteration < MAX_ITER)
    {
        double tmp;
        tmp = z.re * z.re - z.im * z.im + c.re;
        z.im = fabs(2 * z.re * z.im) + c.im;
        z.re = fabs(tmp);
        iteration++;
    }
    return (iteration);
}
