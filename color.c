/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:19:30 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/03 15:19:45 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_color(t_map *map)
{
	if (map->seg.z1 > 0 && map->seg.z2 > 0)
		return (RED);
	else if (map->seg.z1 > 0 || map->seg.z2 > 0)
		return (ORANGE);
	else if (map->seg.z1 < 0 && map->seg.z2 < 0)
		return (D_BLUE);
	else if (map->seg.z1 < 0 || map->seg.z2 < 0)
		return (L_BLUE);
	else
		return (BASE_COLOR);
}
