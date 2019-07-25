/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:18:20 by jlagos            #+#    #+#             */
/*   Updated: 2019/04/18 13:19:13 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_min_to_swap(int num, int *tab, unsigned int size, unsigned int i) //returns index of min number from tab array
{
	int					num_swap;
	unsigned int		index;

	num_swap = num;
	index = i;
	while (++i < size)
	{
		if (num_swap > tab[i])
		{
			num_swap = tab[i];
			index = i;
		}
	}
	if (index == i)
		return (0);
	return (index);
}

void 	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				min;
	int				tmp;

	i = -1;
	while (++i < size)
	{
		min = find_min_to_swap(tab[i], tab, size, i);
		if (min != 0)
		{
			tmp = tab[i];
			tab[i] = tab[min];
			tab[min] = tmp;
		}
	}
}
