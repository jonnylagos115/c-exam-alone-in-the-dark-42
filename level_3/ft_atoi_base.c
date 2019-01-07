/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:15:23 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/06 19:01:52 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		power_of_ret(int str_base, int power)
{
	int product;

	product = 1;
	if (!power) //any number to the power of 0 results to 1
		return (1);
	if (power != 1)
	{
		while (power--)
			product *= str_base;
	}
	else
		return (str_base);
	return (product);
}

int		convert_to_int(char c, int str_base)
{
	int digit;

	digit = 0;
	if (str_base >= 10)
	{
		if (c >= 'A' && c <= 'F')
			digit = c - 55;
		else if (c >= 'a' && c <= 'f')
			digit = c - 87;
		else
			digit = c - '0';
	}
	else
	{
		if ((c < 'A' || c > 'F') && (c < 'a' || c > 'f'))
		{
			if (str_base >= (c - '0'))
				digit = c - '0';
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (digit);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int digit;
	int base_10;
	int power;

	i = 0;
	digit = 0;
	base_10 = 0;
	power = ft_strlen((char*)str) - 1;
	while (str[i])
	{
		digit = convert_to_int(str[i], str_base);
		if (digit < 0)
		{
			ft_putstr("Invalid\n");
			return (digit);
		}
		base_10 += digit * power_of_ret(str_base, power);
		power--;
		i++;
	}
	return (base_10);
}

int		main(int ac, char **ag)
{
	if (ac == 3)
	{
		int ret;

		ret = ft_atoi_base(ag[1], atoi(ag[2]));
		printf("ret: %d\n", ret);
	}
	else
		printf("\n");
	return (0);
}
