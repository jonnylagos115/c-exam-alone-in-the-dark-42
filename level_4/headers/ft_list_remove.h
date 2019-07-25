/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:56:02 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/27 14:34:04 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_REMOVE_H
# define FT_LIST_REMOVE_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
void 			ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif
