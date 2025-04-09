#include "push_swap.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char *ft_strdup(const char *s1)
{
	char *cpy;
	int i;
	size_t len;

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
char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *arr;

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
int update_atoi(const char *str)
{
	long num = 0;
	int sign = 1;
	int i = 0;

	if (!str || !*str)
		check_errors();
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			check_errors();
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > (long)INT_MAX + 1))
			check_errors();
		i++;
	}
	return sign * num;
}
