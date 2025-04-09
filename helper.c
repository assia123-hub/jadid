/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:30:09 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 21:57:11 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*arr;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	arr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(arr))
		return (NULL);
	while (s1[++i])
		arr[i] = s1[i];
	while (s2[j])
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	free(s1);
	return (arr);
}

static int	initialize(const char *str, int *i, int *s)
{
	if (!str || !*str)
		check_errors();
	*i = 0;
	*s = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*s = -1;
		(*i)++;
	}
	return (1);
}

int	update_atoi(const char *str)
{
	long	n;
	int		s;
	int		i;

	n = 0;
	initialize(str, &i, &s);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			check_errors();
		n = n * 10 + (str[i] - '0');
		if ((s == 1 && n > INT_MAX) || (s == -1 && n > (long)INT_MAX + 1))
			check_errors();
		i++;
	}
	return (s * n);
}
