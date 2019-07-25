/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:20:41 by jlagos            #+#    #+#             */
/*   Updated: 2019/04/09 13:18:19 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*head;
	int		swap;

	head = lst;
	while (lst->next)
	{
		if (!(*cmp)(lst->data, lst->next->data))
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}
