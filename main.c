/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:59:45 by lleverge          #+#    #+#             */
/*   Updated: 2016/10/20 16:25:51 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	check_param(ac, environ);
	env = init_env(av[1]);
	ft_read_map(env);
	return (0);
}
