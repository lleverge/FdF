/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:41 by lleverge          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/11/15 12:14:38 by lleverge         ###   ########.fr       */
=======
/*   Updated: 2016/11/07 11:57:10 by lleverge         ###   ########.fr       */
>>>>>>> 2e416b7108565c9303634c9afdb12359857cfd94
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				my_pixel_image(t_img *img, unsigned int color, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				i;

	i = 0;
	img->data = mlx_get_data_addr(img->image, &(img->bpp),
								&(img->size_line), &(img->endian));
	r = (color & 0x00ff0000) >> 16;
	g = (color & 0x0000ff00) >> 8;
	b = color & 0x0000ff00;
	while (i != img->bpp / 8)
	{
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = r;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = g;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = b;
		img->data[(y * img->size_line) + (x * (img->bpp / 8)) + i++] = 0;
	}
	return (0);
}

void			draw_again(t_map *map)
{
	map->image->image = mlx_new_image(map->mlx, map->x_win, map->y_win);
	put_map(map);
<<<<<<< HEAD
q	mlx_put_image_to_window(map->mlx, map->win, map->image->image, 0, 0);
=======
	mlx_put_image_to_window(map->mlx, map->win, map->image->image, 0, 0);
>>>>>>> 2e416b7108565c9303634c9afdb12359857cfd94
	mlx_destroy_image(map->mlx, map->image->image);
	mlx_key_hook(map->win, &ft_keyhook, map);
	mlx_loop(map->mlx);
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
