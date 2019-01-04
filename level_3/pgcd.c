/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:41:39 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/03 19:22:44 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_it_prime(unsigned int n)
{
	unsigned int i;
	int primes;

	i = 5;
	primes = 2;
	if (n == 2 || n == 3)
		return (1);
	if (!(n % 2) || !(n % 3))
		return (0);
	while (i * i <= n) // this loop allows comparsion of each possible prime number starting from 5
	{
		if (!(n % i))
			return (0); //not prime
		i += primes;
		primes = 6 - primes;
	}
	return (1); //is prime
}

int		get_ar_length(int num)
{
	int len;
	int i;
	int primes;

	len = 0;
	i = 5;
	primes = 2;
	while (num)
	{
		if (!(num % 2))
		{
			num /= 2;
			len++;
		}
		else if (!(num % 3))
		{
			num /= 3;
			len++;
		}
		else
		{
			if (is_it_prime(num))
			{
				len++;
				break ;
			}
			num /= i;
			i += primes;
			primes = 6 - primes;
			len++;
		}
	}
	return (len);
}

int		*list_factors(int num) //returns list of prime factors from given number
{
	int i;
	int len;
	int *ar;
	int primes;
	int p;

	i = 0;
	len = get_ar_length(num);
	ar = (int *)malloc(sizeof(int) * len);
	primes = 2;
	p = 5;
	if (!ar)
		return (NULL);
	while (len--)
	{
		if (!(num % 2))
		{
			num /= 2;
			ar[i] = 2;
		}
		else if (!(num % 3))
		{
			num /= 3;
			ar[i] = 3;
		}
		else //if number isn't divisible by 2 or 3, then check if any other primes are divisible
		{
			if (p * p <= num) // 25 <= num
			{
				while (p * p <= num)
				{
					if (!(num % p))
					{
						num /= p; //get the quotient
						ar[i] = p; //assign the divisor first
						i++;
						break ;
					}
					p += primes;			//primes changes from 4 to 6 then vice versa each iteration
					primes = 6 - primes;	//it is the pattern to get all possible prime numbers in ascending order
				}
				ar[i] = num; //then assign the quotient
			}
			else //any number less than or equal to 25 & not divisible by 2 or 3, we can just assigned it as a prime factor
				ar[i] = num;
		}
		i++;
	}
	return (ar);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		int	*lst_factors1;
		int *lst_factors2;
		int len1;
		int len2;
		int i;
		int j;
		int gcd;

		lst_factors1 = list_factors(atoi(ag[1]));
		lst_factors2 = list_factors(atoi(ag[2]));
		len = get_ar_length(atoi(ag[1]));
		len2 = get_ar_length(atoi(ag[2]));
		i = 0;
		j = 0;
		gcd = 1;
		if (len2 < len) //whichever has the shortest length of array 
			len = len2;
		while (i != len && j != len) //loop ends when attempting to access out of bound elements
		{
			if (lst_factors1[i] == lst_factors2[j])
			{
				gcd *= lst_factors1[i++];		//multiplying each common prime factor (denominator) of the two numbers
				j++;
			}
			else if (lst_factors1[i] < lst_factors2[j])
				i++;
			else
				j++;
		}
		printf("%d\n", gcd);
	}
	else
		printf("\n");
	return (0);
}
