/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:22:45 by jlagos            #+#    #+#             */
/*   Updated: 2019/03/12 14:09:32 by jlagos           ###   ########.fr       */
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
	int				f_prime;

	i = 5;
	primes = 2;
	div = num;
	f_prime = 2;
	while (!(div % f_prime) || f_prime == 2)
	{
		if (div % f_prime && f_prime == 2)
			f_prime++;
		else
		{
			print_star_or_not(div, f_prime, num);
			div /= f_prime;
		}
	}
	while (i * i <= num || div >= i)
	{
		if (!(div % i) || div == i)
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
