/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:13:17 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/03 14:40:41 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_length(void)
{
	ft_putendl_fd("fdf: all lines must have same length", 2);
	exit(-1);
}

void		empty_map(void)
{
	ft_putendl_fd("fdf: map is empty", 2);
	exit(-1);
}
