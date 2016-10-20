/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:21:08 by lleverge          #+#    #+#             */
/*   Updated: 2016/10/20 16:18:21 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_read_map(t_env *env)
{
	int		i;
	char	*line;
	char	**map;

	i = 0;
	while (get_next_line(env->fd, &line) == 1)
	{
		map = ft_strsplit(line, ' ');
	}
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
	if (close(env->fd) == -1)
		return (-1);
	return (0);
}
