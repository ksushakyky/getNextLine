/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragorn <maragorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:08:36 by maragorn          #+#    #+#             */
/*   Updated: 2021/01/12 17:08:43 by maragorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_n(char **point)
{
	char *n;
	char *newline;

	newline = 0;
	if (ft_strchr(*point, '\n'))
	{
		newline = ft_strdup(*point);
		free(*point);
		*point = NULL;
		n = ft_strchr(newline, '\n');
		*point = ft_strdup(++n);
		ft_memsets(newline);
	}
	else if ((!(ft_strchr(*point, '\n'))))
		newline = ft_strdup(*point);
	return (newline);
}

char	*ft_point(char **point, char *buf_line)
{
	if (*point != NULL)
		*point = ft_strjoin(*point, buf_line);
	else
		*point = ft_strdup(buf_line);
	return (*point);
}

int		get_next_line(int fd, char **line)
{
	char		buf_line[BUFFER_SIZE + 1];
	int			rd;
	static char	*point;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd = read(fd, buf_line, BUFFER_SIZE)) >= 0)
	{
		buf_line[rd] = '\0';
		ft_point(&point, buf_line);
		if (ft_strchr(point, '\n') || rd == 0)
			break ;
	}
	if (ft_strchr(point, '\n'))
	{
		*line = line_n(&point);
		return (1);
	}
	else if (!(ft_strchr(point, '\n')) && rd == 0)
	{
		*line = line_n(&point);
		free(point);
		point = NULL;
	}
	return ((rd < 0) ? -1 : 0);
}
