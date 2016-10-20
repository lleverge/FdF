/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:10:05 by lleverge          #+#    #+#             */
/*   Updated: 2016/10/20 17:00:20 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_env
{
	int				fd;
	void			*mlx;
	void			*win;
	int				x_win;
	int				y_win;
}					t_env;

typedef struct		s_map
{
	int		y_map;
	int		x_map;
	int		h_map;
	int		**draw;
}					t_map;

int					ft_read_map(t_env *env);

#endif
