/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragorn <maragorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:59:03 by maragorn          #+#    #+#             */
/*   Updated: 2021/01/12 16:26:30 by maragorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	while (s1[len])
		++len;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*sum;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((s1 == 0 && s2 == 0) || s1 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	sum = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!sum)
		return (NULL);
	while (i < s1_len)
	{
		sum[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		sum[i++] = s2[j++];
	sum[i] = '\0';
	free(s1);
	return (sum);
}

char	*ft_memsets(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
