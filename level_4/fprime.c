/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:23:48 by jlagos            #+#    #+#             */
/*   Updated: 2019/07/24 17:15:07 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdlib.h>

int		is_prime_nbr(int nbr)
{
	int	odd_nbr;

	odd_nbr = 2;
	if (!(nbr % 2))
		return (1);
	while (nbr > ++odd_nbr)
		if (!(nbr % odd_nbr))
			return (1);
	return (0);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		int		num;
		int		product;
		int		prime;

		num = atoi(ag[1]);
		product = 1;
		prime = 2;
		if (is_prime_nbr(num))
		{
			while (num && num != 1)
			{
				if (!(num % prime))
				{
					printf("%d*", prime);
					product *= prime;
					num = num / prime;
				}
				else
				{
					if (prime != 2)
					{
						prime += 2;
						while (is_prime_nbr(prime))
							prime += 2;
					}
					else
						prime++;
				}
				if (!is_prime_nbr(num))
				{
					printf("%d", num);
					num = 0;
				}
			}
			
		}
		else
			printf("%d", num);
	}
	printf("\n");
	return (0);
}
