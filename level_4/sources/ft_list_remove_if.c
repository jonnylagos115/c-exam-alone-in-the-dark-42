/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:54:37 by jlagos            #+#    #+#             */
/*   Updated: 2019/02/27 14:50:09 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_remove.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*head;

	while (*begin_list && !(cmp)((*begin_list)->data, data_ref))
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	head = *begin_list;
	while (head && head->next)
	{
		if (!(cmp(head->next->data, data_ref)))
		{
			temp = head->next;
			head = head->next;
			free(temp);
		}
		if (head->next)
			head = head->next;
	}
}
