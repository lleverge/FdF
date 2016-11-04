/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/04 10:36:57 by lleverge         ###   ########.fr       */
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
			if (!ft_isdigit(map[i][j]) && map[i][j] != '-')
			{
				ft_putendl_fd("fdf: map must contains only numbers", 2);
				exit(-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int		**init_draw(t_map *map)
{
	int		**draw;
	int		i;

	i = 0;
	if (!(draw = (int **)malloc(sizeof(int *) * map->y_map)))
		exit(-1);
	while (i < map->y_map)
	{
		if (!(draw[i] = (int *)malloc(sizeof(int) * map->x_map)))
			exit(-1);
		i++;
	}
	return (draw);
}

static void		copy_map(char *av, int **draw, t_map *map, t_env *env)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

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
	map->zoom = env->x_win / (((map->x_map + map->y_map) / 2) * 3);
}

void			read_map(char *av, t_env *env, t_map *map, int flag)
{
	char	*line;
	char	**tab;

	while (get_next_line(env->fd, &line) == 1)
	{
		flag = 0;
		tab = ft_strsplit(line, ' ');
		if (tab)
		{
			ft_strdel(&line);
			check_line(tab);
			if (map->x_map == 0)
				map->x_map = tablen(tab);
			else if (map->x_map != 0)
				if (map->x_map != tablen(tab))
					error_length();
			ft_freetab(tab);
			map->y_map++;
		}
	}
	map->draw = init_draw(map);
	copy_map(av, map->draw, map, env);
	close(env->fd);
	if (flag)
		empty_map();
}
