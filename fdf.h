/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:10:05 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/04 14:54:22 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"

# define BASE_COLOR 0x00FFFFFF
# define ORANGE 0x00FF5B2B
# define L_BLUE 0x005EB6DD
# define D_BLUE 0x00046380
# define RED 0x00B9121B

typedef struct		s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}					t_img;

typedef struct		s_seg
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z1;
	int		z2;
	int		dx;
	int		dy;
}					t_seg;

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
	int			y_map;
	int			x_map;
	int			h_map;
	int			x_win;
	int			y_win;
	t_img		*image;
	int			**draw;
	void		*mlx;
	void		*win;
	int			zoom;
	int			color;
	int			height;
	int			offset_x;
	int			offset_y;
	double		factor;
	t_seg		seg;
}					t_map;

void				read_map(char *av, t_env *env, t_map *map, int flag);
void				ft_freetab(char **tab);
void				error_length(void);
void				empty_map(void);
void				draw_map(t_env *env, t_map *map);
int					ft_keyhook(int keycode, t_map *map);
void				put_map(t_map *map);
int					get_color(t_map *map);
int					my_pixel_put_to_image(t_img *im, int x, int y);
void				draw_again(t_map *map);
#endif
