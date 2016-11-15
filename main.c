/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:59:45 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/07 12:24:30 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			check_param(int ac, char **env)
{
	if (ac != 2 || !env || !(*env))
	{
		if (ac != 2)
			ft_putendl_fd("fdf: usage: ./fdf file1", 2);
		if (!env || !(*env))
			ft_putendl_fd("fdf: cant be launch with empty env", 2);
		exit(1);
	}
}

static t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		exit(1);
	map->y_map = 0;
	map->x_map = 0;
	map->h_map = 0;
	map->zoom = 20;
	map->height = 3;
	map->factor = 0.5;
	map->offset_x = -300;
	map->offset_y = 500;
	return (map);
}

static t_env		*init_env(char *av)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	if ((env->fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl_fd("fdf: invalid fd", 2);
		exit(1);
	}
	env->y_win = 800;
	env->x_win = 1200;
	return (env);
}

int					main(int ac, char **av, char **environ)
{
	t_env	*env;
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check_param(ac, environ);
	env = init_env(av[1]);
	map = init_map();
	read_map(av[1], env, map, 1);
	draw_map(env, map);
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}
