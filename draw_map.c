/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:41 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/04 14:54:02 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				my_pixel_put_to_image(t_img *img, int x, int y)
{
	int	i;

	i = 0;
	img->data = mlx_get_data_addr(img->image, &(img->bpp),
								&(img->size_line), &(img->endian));
	while (i != img->bpp / 8)
	{
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = 255;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = 100;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = 105;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = 0;
	}
	return (0);
}

void			draw_again(t_map *map)
{
	map->image->image = mlx_new_image(map->mlx, map->x_win, map->y_win);
	put_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->image->image, 0, 0);
	mlx_key_hook(map->win, &ft_keyhook, map);
	mlx_loop(map->mlx);
	mlx_destroy_image(map->mlx, map->image->image);
}

void			draw_map(t_env *env, t_map *map)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->x_win, env->y_win, "FdF");
	map->mlx = env->mlx;
	map->win = env->win;
	map->x_win = env->x_win;
	map->y_win = env->y_win;
	draw_again(map);
}
