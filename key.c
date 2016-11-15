/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:08:39 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/04 17:37:49 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		do_exit(void)
{
	ft_putendl("exit");
	exit(0);
}

static void		move_offset(t_map *map, int i, int j)
{
	map->offset_x += i;
	map->offset_y += j;
}

static void		modif_persp(t_map *map, int keycode)
{
	if (keycode == 83)
	{
		if (map->factor > 0.2)
		{
			map->factor -= 0.1;
			map->offset_x -= 50;
			map->offset_y += 50;
		}
	}
	else if (keycode == 84)
	{
		if (map->factor < 0.8)
		{
			map->factor += 0.1;
			map->offset_x += 50;
			map->offset_y -= 50;
		}
	}
}

int				ft_keyhook(int keycode, t_map *map)
{
	if (keycode == 53 || keycode == 12)
		do_exit();
	else if ((keycode == 69 || keycode == 24) && map->zoom < 30)
		map->zoom += 1;
	else if (keycode == 78 || keycode == 27)
		map->zoom -= 1;
	else if (keycode == 123)
		move_offset(map, -10, -10);
	else if (keycode == 124)
		move_offset(map, 10, 10);
	else if (keycode == 126)
		move_offset(map, 10, -10);
	else if (keycode == 125)
		move_offset(map, -10, 10);
	else if (keycode == 116)
		map->height += 1;
	else if (keycode == 121)
		map->height -= 1;
	else if (keycode == 83 || keycode == 84)
		modif_persp(map, keycode);
	mlx_clear_window(map->mlx, map->win);
	draw_again(map);
	return (0);
}
