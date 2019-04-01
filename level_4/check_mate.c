/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:08:43 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/31 18:09:04 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		is_check_mate(Chess *piece, int k_row, int k_col)
{
	char	p;
	int		row;
	int		col;
	int		diff;

	while (piece)
	{
		p = piece->p;
		row = piece->p_row;
		col = piece->p_col;
		if (p == 'P')
		{
			if (k_row == row - 1 && (k_col == col - 1 || k_col == col + 1))
				return (1);
		}
		if (p == 'B')
		{
			if (row > k_row)
				diff = row - k_row;
			else
				diff = k_row - row;
			if (k_col == (col - diff) || k_col == (col + diff))
				return (1);
		}
		if (p == 'R')
			if (row == k_row || col == k_col)
				return (1);
		if (p == 'Q')
		{
			if (k_row == row - 1 && (k_col == col - 1 || k_col == col + 1))
				return (1);
			if (row == k_row || col == k_col)
				return (1);
			if (row > k_row)
				diff = row - k_row;
			else
				diff = k_row - row;
			if (k_col == (col - diff) || k_col == (col + diff))
				return (1);
		}
		piece = piece->next;
	}
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac > 1)
	{
		Chess	*piece;
		Chess	*head;
		int		i;
		int		j;
		int		k_row;
		int		k_col;

		i = 0;
		j = -1;
		k_row = -1;
		k_col = -1;
		piece = (Chess *)malloc(sizeof(*piece));
		head = piece;
		while (++i < ac)
		{
			while (ag[i][++j])
			{
				if (ag[i][j] == 'K')
				{
					k_row = i - 1;
					k_col = j;
				}
				if (ag[i][j] == 'P' || ag[i][j] == 'B' || ag[i][j] == 'R' ||
						ag[i][j] == 'Q')
				{
					piece->p = ag[i][j];
					piece->p_row = i - 1;
					piece->p_col = j;
					piece->next = (Chess *)malloc(sizeof(*piece));
					piece = piece->next;
				}
			}
			j = -1;
		}
		free(piece);
		piece = NULL;
		if (is_check_mate(head, k_row, k_col))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return (0);
}
