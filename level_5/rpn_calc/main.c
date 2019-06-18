/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:55:36 by jlagos            #+#    #+#             */
/*   Updated: 2019/06/18 16:44:01 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

void	store_values(int *num_arr, char *str, int index_start)
{
	int		i;

	i = 0;
	while (IS_NOT_OPERATOR(str[index_start]))
	{
		if (str[index_start] != ' ')
		{
			num_arr[i] = str[index_start] - '0';
			index_start++;
			while (str[index_start] >= '0' && str[index_start] <= '9')
				num_arr[i] = (num_arr[i] * 10) + (str[index_start++] - '0');
			i++;	
		}
		else
			index_start++;
	}
}

void		calc_ret(int *num_arr, char *str, int num_len, int *i, int *ret)
{
	int		flag;

	if (num_len == 1)
		flag = 2;
	else
		flag = 0;
	while (IS_OPERATOR(str[*i]))
	{
		if (str[*i] == '+')
		{
			if (!flag)
				(*ret) = num_arr[num_len - 2] + num_arr[num_len - 1];
			else if (flag == 1)
				(*ret) = num_arr[num_len - 1] + (*ret);
			else if (flag == 2)
				(*ret) += num_arr[num_len - 1];
		}
		if (str[*i] == '-')
		{
			if (!flag)
				(*ret) = num_arr[num_len - 2] - num_arr[num_len - 1];
			else if (flag == 1)
				(*ret) = num_arr[num_len - 1] - (*ret);
			else if (flag == 2)
				(*ret) -= num_arr[num_len - 1];
		}
		if (str[*i] == '*')
		{
			if (!flag)
				(*ret) = num_arr[num_len - 2] * num_arr[num_len - 1];
			else
				(*ret) = (*ret) * num_arr[num_len - 1];
		}
		if (str[*i] == '/')
		{
			if (!flag)
				(*ret) = num_arr[num_len - 2] / num_arr[num_len - 1];
			else if (flag == 1)
				(*ret) = num_arr[num_len - 1] / (*ret);
			else if (flag == 2)
				(*ret) /= num_arr[num_len - 1];
		}
		if (str[*i] == '%')
		{
			if (!flag)
				(*ret) = num_arr[num_len - 2] % num_arr[num_len - 1];
			else if (flag == 1)
				(*ret) = num_arr[num_len - 1] % (*ret);
			else if (flag == 2)
				(*ret) %= num_arr[num_len - 1];
		}
		num_len -= 2;
		flag = 1;
		(*i)++;
		if (str[*i] == ' ')
			(*i)++;
	}
	if (num_len != 1 && num_len != 0)
		(*ret) = -1;
}

int		rpn_calc(char *str)
{
	int		i;
	int		num_len;
	int		*num_arr;
	int		index_start;
	int		ret;

	i = 0;
	num_len = 0;
	ret = 0;
	while (str[i])
	{
		index_start = i;
		while (IS_NOT_OPERATOR(str[i]))
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i] >= '0' && str[i] <= '9')
					i++;
				num_len++;
			}
			i++;
		}
		num_arr = (int *)malloc(sizeof(int) * num_len);
		store_values(num_arr, str, index_start);
		calc_ret(num_arr, str, num_len, &i, &ret);
		if (ret == -1)
			return (ret);
		free(num_arr);
		num_len = 0;
	}
	return (ret);
}

int		main(int ac, char **ag)
{
	if (ac > 1)
	{
		int		ret;

		ret = rpn_calc(ag[1]);
		if (ret == -1)
			printf("Error");
		else
			printf("%d", ret);
	}
	printf("\n");
	return (0);
}
