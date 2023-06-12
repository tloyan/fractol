/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:58:54 by thloyan           #+#    #+#             */
/*   Updated: 2023/06/12 15:52:27 by thloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	printf("Erreur : nom de la fractale manquant\n");
	printf("Utilisation : fractol <nom_fractale> [<re> <im>]\n");
	printf("Fractales disponibles : mandelbrot, julia, ...\n");
	exit(0);
}

void	check_params(int argc, char **argv)
{
	char	*fractal_name;

	if (argc < 2)
		error();
	fractal_name = argv[1];
	if (ft_strcmp(fractal_name, "mandelbrot") != 0
		&& ft_strcmp(fractal_name, "julia") != 0
		&& ft_strcmp(fractal_name, "burningship") != 0
		&& ft_strcmp(fractal_name, "newton") != 0)
		error();
	if (ft_strcmp(fractal_name, "julia") != 0 && (argc != 2 && argc != 4))
		error();
	// if () // check if argc 2 and 4 are valid number
}

int	get_fractal_type(const char *fractal_name)
{
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
		return (MANDELBROT);
	else if (ft_strcmp(fractal_name, "julia") == 0)
		return (JULIA);
	else if (ft_strcmp(fractal_name, "burningship") == 0)
		return (BURNINGSHIP);
	return (-1);
}

void	params_to_env(int argc, char **argv, t_env *env)
{
	env->fractal_type = get_fractal_type(argv[1]);
	if (env->fractal_type == JULIA && argc == 4)
	{
		env->c.re = ft_atof(argv[2]);
		env->c.im = ft_atof(argv[3]);
	}
	else
	{
		env->c.re = -0.7;
		env->c.im = 0.27015;
	}
}

t_env	setup_env(int argc, char **argv)
{
	t_env	env;

	check_params(argc, argv);
	params_to_env(argc, argv, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "fractol");
	env.x_min = -2;
	env.y_min = -2;
	env.x_max = 2;
	env.y_max = 2;
	env.color_scheme = PATERN0;
	return (env);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_data	img;

	env = setup_env(argc, argv);
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_key_hook(env.win, key_handler, &env);
	draw_fractal(&env);
	mlx_loop(env.mlx);
}
