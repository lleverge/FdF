/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/03 10:56:59 by lleverge         ###   ########.fr       */
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

void			read_map(t_env *env, t_map *map)
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
	close(env->fd);
}
