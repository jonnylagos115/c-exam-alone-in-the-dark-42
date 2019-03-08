/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:58:28 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/08 13:58:58 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		gcf(int large_n, int small_n) //Euclid's Algorithm implementation
{
	int	ret;
	int R;

	R = 1;
	while (R)
	{
		R = large_n % small_n;
		ret = large_n / small_n;
		large_n = small_n;
		small_n = R;
	}
	return (large_n);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		int 	num1;
		int 	num2;
		int		ret;

		num1 = atoi(ag[1]);
		num2 = atoi(ag[2]);
		if (num1 > num2)
			ret = gcf(num1, num2);
		else
			ret = gcf(num2, num1);
		printf("%d", ret);
	}
	printf("\n");
	return (0);
}
