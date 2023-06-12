/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:35:50 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:34:01 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	if (mousecode == 4)
		zoom_in(x, y, env);
	if (mousecode == 5)
		zoom_out(x, y, env);
	return (1);
}
