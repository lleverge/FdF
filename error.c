/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:13:17 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/07 12:09:40 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_coord(char *line)
{
	int		i;

	i = 0;
	while (line[i])
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
