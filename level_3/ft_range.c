/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:42:51 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/07 15:37:47 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int len;
	int	temp;
	int *ar;
	int i;

	if (end < start)
	{
		temp = start;
		start = end;
		end = temp;
	}
	len = (end - start) + 1;
	i = 0;
	ar = (int *)malloc(len * sizeof(int));
	if (!ar)
		return (NULL);
	if (!len)
		ar[i] = 0;
	while (len--)
	{
		ar[i++] = start;
		start++;
	}
	return (ar);
}

int		main(void)
{
	int *num_ar;
	int i;

	num_ar = ft_range(0, -3);
	i = 0;
	while (i < 3)
		printf("%d\n", num_ar[i++]);
	return (0);
}
