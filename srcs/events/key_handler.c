/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:38:11 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:50:48 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, t_env *env)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 123)
		move_left(env);
	else if (keycode == 124)
		move_right(env);
	else if (keycode == 126)
		move_up(env);
	else if (keycode == 125)
		move_down(env);
	else if (keycode == 35)
		switch_color(env);
	return (1);
}