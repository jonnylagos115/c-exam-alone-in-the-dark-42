/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:57:05 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/06 17:15:13 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int num)
{
	if (num > 9)
		ft_putnum(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
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

void	tab_mult(int num)
{
	int i;
	int product;

	i = 1;
	product = 0;
	while (i <= 9)
	{
		product = i * num;
		ft_putchar(i + '0');
		ft_putstr(" x ");
		ft_putnum(num);
		ft_putstr(" = ");
		ft_putnum(product);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		int num;

		num = ft_atoi(ag[1]);
		tab_mult(num);
	}
	else
		write(1, "\n", 1);
	return (0);
}
