/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:28:00 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/20 15:08:46 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	calc_print(int num1, int num2, char *op)
{
	int ret;

	ret = 0;
	if (*op == '+')
		ret = num1 + num2;
	if (*op == '-')
		ret = num1 - num2;
	if (*op == '*')
		ret = num1 * num2;
	if (*op == '/')
		ret = num1 / num2;
	if (*op == '%')
		ret = num1 % num2;
	printf("%d", ret);
}

int		main(int ac, char **ag)
{
	if (ac == 4)
	{
		int num_one;
		int num_two;
		char *ar_op;

		num_one = atoi(ag[1]);
		ar_op = ag[2];
		num_two = atoi(ag[3]);
		calc_print(num_one, num_two, ar_op);		
	}
	printf("\n");
	return (0);
}
