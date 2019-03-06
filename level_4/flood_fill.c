/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:21:29 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/05 17:06:49 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int 	j;
	char 	flag;
	int 	row;
	int		col;

	flag = tab[begin.x][begin.y];
	row = begin.y - 1;
	col = begin.x;
	j = col;
	while (++row < size.y)
	{
		while (j < size.x)
		{
			if (flag == tab[row - 1][j])
				tab[row - 1][j] = 'F';
			else
				break ;
			j += 2;
		}
		j = col;
	}
}
