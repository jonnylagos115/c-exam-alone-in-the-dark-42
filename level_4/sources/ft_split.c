/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:28:05 by jlagos            #+#    #+#             */
/*   Updated: 2019/01/14 15:20:01 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <printf.h>

int				is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

size_t			num_of_strings(char const *s, size_t *x)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (is_white_space(s[i]))
	{
		i++;
		(*x)++;
	}
	while (s[i])
	{
		if (is_white_space(s[i])
			if (s[i + 1] != ' ' || s[i + 1] != )
				len++;
		i++;
		if (s[i] == '\0' && !(is_white_space(s[i - 1])))
			len++;
	}
	return (len);
}

size_t			len_str(char **s)
{
	size_t len;

	len = 0;
	while (is_white_space(**s))
		(*s)++;
	if (**s == '\0')
		return (1);
	while (!(is_white_space(**s)))
	{
		len++;
		(*s)++;
	}
	return (len);
}

void			assign_char(char **str, char const *s, size_t *read_s)
{
	size_t j;

	j = 0;
	while (!(is_white_space(s[*read_s])))
	{
		(*str)[j++] = s[*read_s];
		(*read_s)++;
	}
	(*str)[j] = '\0';
	while (!(is_white_space(s[*read_s])))
		(*read_s)++;
}

void			*free_malloc(char ***strsplit, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		ft_strdel(&(*strsplit)[i++]);
	ft_strdel(*strsplit);
	return (NULL);
}

char			**ft_split(char *str)
{
	char	**strsplit;
	char	*temp;
	size_t	read_s;
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	temp = (char *)str;
	read_s = 0;
	i = 0;
	len = num_of_strings(str, &read_s);
	if (!(strsplit = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	while (i < len + 1)
	{
		if (!(strsplit[i] = ft_strnew(len_str(&temp))))
			return (free_malloc(&strsplit, i));
		i++;
	}
	i = 0;
	while (i < len)
		assign_char(&strsplit[i++], str, &read_s);
	strsplit[i] = NULL;
	return (strsplit);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char **arr_str;
		int i;

		i = 0;
		arr_str = ft_split(ag[1]);
		while (i < 3)
			printf("%s\n", arr_str[i++]);
	}
	return (0);
}
