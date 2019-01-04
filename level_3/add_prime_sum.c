/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:14:10 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/20 17:34:43 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int n;

	i = 0;
	n = 0;
	sign = 1;
	if (!str)
		return ('\0');
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	return (n * sign);
}

/*int		is_it_prime(unsigned int n)
{
	unsigned int i;
	int primes;

	i = 5;
	primes = 2;
	if (n == 2 || n == 3)
		return (1);
	if (!(n % 2) || !(n % 3))
		return (0);
	while (i * i <= n)
	{
		if (!(n % i))
			return (0);
		i += primes;
		primes -= 6;
	}
	return (1);
}*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		unsigned int	num;
		unsigned int	i;
		int				sum;
		int				primes;

		num = ft_atoi(ag[1]);
		sum = 10;
		i = 5;
		primes = 2;
		if (num == 2 || num == 3)
			write(1, &num, 1);
		if (num == 5)
			write(1, "10", 2);
		else
		{
			while (i < num)
			{
				i += primes;
				primes = 6 - primes;
				sum += i;
			}
			ft_putnbr(sum);
		}
	}
	write(1, "\n", 1);
	return (0);
}
