/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/10/20 18:12:35 by lleverge         ###   ########.fr       */
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

static void		read_map(char *av, t_env *env, t_map *map)
{
	char	*line;
	char	**tab;

	while (get_next_line(env->fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		if (tab)
		{
			ft_strdel(&line);
			check_line(tab);
			if (map->x_map == 0)
				map->x_map = tablen(tab);
			else if (map->x_map != 0)
				if (map->x_map != tablen(tab))
					ft_putendl_fd("fdf: all lines must have same length", 2);
			ft_freetab(split);
			map->y_map++;
		}
	}
	close(env->fd);
}
