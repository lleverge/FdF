/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/03 13:01:55 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

static int		check_line(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_isdigit(map[i][j]))
			{
				ft_putendl_fd("fdf: map must contains only numbers", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int		**init_draw(char *av, t_map *map, t_env *env)
{
	int		**draw;
	char	*line;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (!(draw = (int **)malloc(sizeof(int *) * map->y_map)))
		exit(-1);
	while (i < map->y_map)
	{
		if (!(draw[i] = (int *)malloc(sizeof(int) * map->x_map)))
			exit(-1);
		i++;
	}
	i = 0;
	if ((env->fd = open(av, O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(env->fd, &line) == 1)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		if (tab)
		{
			ft_strdel(&line);
			while (j < map->x_map)
			{
				draw[i][j] = ft_atoi(tab[j]);
				j++;
			}
			i++;
		}
	}
	return (draw);
}

static void		print_draw(int **draw, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(draw[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			read_map(char *av, t_env *env, t_map *map)
{
	char	*line;
	char	**tab;

	while (get_next_line(env->fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (tab)
		{
			ft_strdel(&line);
			if (!check_line(tab))
				exit(-1);
			if (map->x_map == 0)
				map->x_map = tablen(tab);
			else if (map->x_map != 0)
				if (map->x_map != tablen(tab))
				{
					ft_putendl_fd("fdf: all lines must have same length", 2);
					exit(-1);
				}
			ft_freetab(tab);
			map->y_map++;
		}
	}
	map->draw = init_draw(av, map, env);
	close(env->fd);
}
