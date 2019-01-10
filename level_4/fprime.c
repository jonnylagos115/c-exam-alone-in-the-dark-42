/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:22:45 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/09 15:13:40 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_star_or_not(int div, int i, int num)
{
	if (div == num)
		printf("%d", i);
	else
		printf("*%d", i);
}

void	print_primes(unsigned int num)
{
	unsigned int 	i;
	unsigned int 	div;
	int				primes;

	i = 5;
	primes = 2;
	div = num;
	while (!(div % 2))
	{
		print_star_or_not(div, 2, num);
		div /= 2;
	}
	while (!(div % 3))
	{
		print_star_or_not(div, 3, num);
		div /= 3;
	}
	while (i * i <= num)
	{
		if (!(div % i))
		{
			print_star_or_not(div, i, num);
			div /= i;
		}
		else
		{
			i += primes;
			primes = 6 - primes;
		}
	}
	if (div == num)
		printf("%d", num);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		int num;

		num = atoi(ag[1]);
		print_primes(num);
	}
	printf("\n");
	return (0);
}
