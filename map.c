/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/10/20 17:20:37 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		read_map(char *av, t_env *env, t_map *map)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	if ((env->fd = open(av, O_RDONLY)) == -1)
		exit(1);
	if (!(map->draw = (int **)malloc(sizeof(int *) * (map->y_map))))
		exit(1);
	while (get_next_line(env->fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (tab)
			ft_strdel(&line);
		save_map(map, tab, map->y_map - 1 - i);
		free_tab(tab);
		i++;
	}
	close(env->fd);
}
