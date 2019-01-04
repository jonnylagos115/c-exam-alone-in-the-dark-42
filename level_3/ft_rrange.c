/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:42:46 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/03 14:13:04 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int *arr;
	int len;
	int i;
	int temp_end;

	temp_end = end;
	if (end < 0)
		len = (start - end) + 1;
	else
		len = (end - start) + 1;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (len--)
	{
		arr[i] = end;
		if (temp_end < 0)
			end++;
		else
			end--;
		i++;
	}
	return (arr);
}
