/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:52:34 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/06 16:33:36 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			write(1, "-", 1);
	   i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');	
	return (sign * num);
}

void	print_hex(int num) //print hex of a value from converted base 10 
{
	int remainder;

	remainder = num % 16;
	if (num / 16)	//used recursion to print remainders from last to first
		print_hex(num / 16);
	if (remainder > 9)
	{
		remainder += 87;
		ft_putchar(remainder);
	}
	else
		ft_putchar(remainder + '0');
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		int base10;

		base10 = ft_atoi(ag[1]);
		print_hex(base10);
	}
	write(1, "\n", 1);
	return (0);
}
