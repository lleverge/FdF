/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:13:17 by lleverge          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/11/09 16:28:58 by lleverge         ###   ########.fr       */
=======
/*   Updated: 2016/11/07 12:09:40 by lleverge         ###   ########.fr       */
>>>>>>> 2e416b7108565c9303634c9afdb12359857cfd94
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_coord(char *line)
{
	int		i;

	i = 0;
<<<<<<< HEAD
	while (line[i] && line[i] != ',')
=======
	while (line[i])
>>>>>>> 2e416b7108565c9303634c9afdb12359857cfd94
	{
		if (line[i] != '-' && !ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	return (0);
}

void		error_length(void)
{
	ft_putendl_fd("fdf: Found wrong line length. Exiting.", 2);
	exit(-1);
}

void		empty_map(void)
{
	ft_putendl_fd("fdf: No data found.", 2);
	exit(-1);
}
