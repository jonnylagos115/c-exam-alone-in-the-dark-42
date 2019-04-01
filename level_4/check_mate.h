/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:09:26 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/31 18:09:41 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct chess_piece
{
	char	p;
	int 	p_row;
	int 	p_col;
	struct chess_piece 	*next;
}Chess;

#endif
